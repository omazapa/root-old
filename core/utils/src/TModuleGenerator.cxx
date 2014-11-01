// @(#)root/utils:$Id$
// Author: Axel Naumann, 2-13-07-02
// Author: Danilo Piparo, 2013, 2014

/*************************************************************************
 * Copyright (C) 1995-2013, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

////////////////////////////////////////////////////////////////////////////////
//
// PCM writer.
//
////////////////////////////////////////////////////////////////////////////////

#include "TModuleGenerator.h"

#include "TMetaUtils.h"
#include "RConfigure.h"
#include "RConfig.h"

#include "clang/Basic/SourceManager.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Lex/HeaderSearch.h"
#include "clang/Lex/Preprocessor.h"
#include "llvm/Support/Path.h"

#include <map>

#ifndef R__WIN32
#include <unistd.h>
#endif

#include <iostream>

using namespace ROOT;
using namespace clang;

TModuleGenerator::TModuleGenerator(CompilerInstance *CI,
                                   const std::string &shLibFileName):
   fCI(CI),
   fIsPCH(shLibFileName == "allDict.cxx"),
   fDictionaryName(llvm::sys::path::stem(shLibFileName)),
   fModuleDirName(llvm::sys::path::parent_path(shLibFileName))
{

   // Clean the dictionary name from characters which are not accepted in C++
   std::string tmpName = fDictionaryName;
   fDictionaryName.clear();
   ROOT::TMetaUtils::GetCppName(fDictionaryName, tmpName.c_str());

   // Need to resolve _where_ to create the pcm
   // We default in the lib subdirectory
   // otherwise we put it in the same directory as the dictionary file (for ACLiC)
   if (fModuleDirName.empty()) {
      fModuleDirName = "./";
   } else {
      fModuleDirName += "/";
   }

   fModuleFileName = fModuleDirName
                     + ROOT::TMetaUtils::GetModuleFileName(fDictionaryName.c_str());
   // .pcm -> .pch
   if (IsPCH()) fModuleFileName[fModuleFileName.length() - 1] = 'h';

   // Add a random string to the filename to avoid races
   llvm::SmallString<10> resultPath("%%%%%%%%%%");
   llvm::sys::fs::createUniqueFile(resultPath.str(), resultPath);
   fUmbrellaName = fModuleDirName + fDictionaryName + resultPath.c_str() + "_dictUmbrella.h";
   fContentName = fModuleDirName + fDictionaryName + resultPath.c_str() + "_dictContent.h";
}

TModuleGenerator::~TModuleGenerator()
{
   unlink(fUmbrellaName.c_str());
   unlink(fContentName.c_str());
}

//______________________________________________________________________________
TModuleGenerator::ESourceFileKind
TModuleGenerator::GetSourceFileKind(const char *filename) const
{
   // Check whether the file's extension is compatible with C or C++.
   // Return whether source, header, Linkdef or nothing.
   if (filename[0] == '-') return kSFKNotC;

   const size_t len = strlen(filename);
   const char *ext = filename + len - 1;
   while (ext >= filename && *ext != '.') --ext;
   if (ext < filename || *ext != '.') {
      // This might still be a system header, let's double check
      // via the FileManager.
      clang::Preprocessor &PP = fCI->getPreprocessor();
      clang::HeaderSearch &HdrSearch = PP.getHeaderSearchInfo();
      const clang::DirectoryLookup *CurDir = 0;
      const clang::FileEntry *hdrFileEntry
         =  HdrSearch.LookupFile(filename, clang::SourceLocation(),
                                 true /*isAngled*/, 0 /*FromDir*/, CurDir,
                                 clang::ArrayRef<const clang::FileEntry *>(),
                                 0 /*SearchPath*/, 0 /*RelativePath*/,
                                 0 /*SuggestedModule*/);
      if (hdrFileEntry) {
         return kSFKHeader;
      }
      return kSFKNotC;
   }
   ++ext;
   const size_t lenExt = filename + len - ext;

   ESourceFileKind ret = kSFKNotC;
   switch (lenExt) {
      case 1: {
            const char last = toupper(filename[len - 1]);
            if (last == 'H') ret = kSFKHeader;
            else if (last == 'C') ret = kSFKSource;
            break;
         }
      case 2: {
            if (filename[len - 2] == 'h' && filename[len - 1] == 'h')
               ret = kSFKHeader;
            else if (filename[len - 2] == 'c' && filename[len - 1] == 'c')
               ret = kSFKSource;
            break;
         }
      case 3: {
            const char last = filename[len - 1];
            if ((last == 'x' || last == 'p')
                  && filename[len - 2] == last) {
               if (filename[len - 3] == 'h') ret = kSFKHeader;
               else if (filename[len - 3] == 'c') ret = kSFKSource;
            }
         }
   } // switch extension length

   /*
   static const size_t lenLinkdefdot = 8;
   if (ret == kSFKHeader && len - lenExt >= lenLinkdefdot) {
      if ((strstr(filename,"LinkDef") || strstr(filename,"Linkdef") ||
           strstr(filename,"linkdef")) && strstr(filename,".h")) {
         ret = kSFKLinkdef;
      }
   }*/
   return ret;
}


static
std::pair<std::string, std::string> SplitPPDefine(const std::string &in)
{
   std::string::size_type posEq = in.find('=');
   if (posEq == std::string::npos)
      return std::make_pair(in, "");
   return std::pair<std::string, std::string>
          (in.substr(0, posEq), in.substr(posEq + 1, std::string::npos));
}


void TModuleGenerator::ParseArgs(const std::vector<std::string> &args)
{
   // Parse -I -D -U headers.h SomethingLinkdef.h.
   for (size_t iPcmArg = 1 /*skip argv0*/, nPcmArg = args.size();
         iPcmArg < nPcmArg; ++iPcmArg) {
      ESourceFileKind sfk = GetSourceFileKind(args[iPcmArg].c_str());
      if (sfk == kSFKHeader || sfk == kSFKSource) {
         fHeaders.push_back(args[iPcmArg]);
      } else if (sfk == kSFKNotC && args[iPcmArg][0] == '-') {
         switch (args[iPcmArg][1]) {
            case 'I':
               if (args[iPcmArg] != "-I." &&  args[iPcmArg] != "-Iinclude") {
                  fCompI.push_back(args[iPcmArg].c_str() + 2);
               }
               break;
            case 'D':
               if (args[iPcmArg] != "-DTRUE=1" && args[iPcmArg] != "-DFALSE=0"
                     && args[iPcmArg] != "-DG__NOCINTDLL") {
                  // keep -DG__VECTOR_HAS_CLASS_ITERATOR?
                  fCompD.push_back(SplitPPDefine(args[iPcmArg].c_str() + 2));
               }
               break;
            case 'U':
               fCompU.push_back(args[iPcmArg].c_str() + 2);
               break;
         }
      }
   }
}

std::ostream &TModuleGenerator::WritePPDefines(std::ostream &out) const
{
   // Write
   // #ifndef FOO
   // # define FOO=bar
   // #endif
   for (auto const & strPair : fCompD) {
      std::string cppname(strPair.first);
      size_t pos = cppname.find('(');
      if (pos != std::string::npos) cppname.erase(pos);
      out << "#ifndef " << cppname << "\n"
          "  #define " << strPair.first;
      if (!strPair.second.empty()) {
         out << " " << strPair.second;
      } else {
         out << " 1";
      }
      out << "\n"
          "#endif\n";
   }
   out << std::endl;
   return out;
}

std::ostream &TModuleGenerator::WritePPUndefines(std::ostream &out) const
{
   // Write
   // #ifdef FOO
   // # undef FOO
   // #endif
   for (auto const & undef : fCompU) {
      out << "#ifdef " << undef << "\n"
          "  #undef " << undef << "\n"
          "#endif\n";
   }
   out << std::endl;
   return out;
}

std::ostream &TModuleGenerator::WritePPIncludes(std::ostream &out) const
{
   // Write
   // #include "header1.h"
   // #include "header2.h"
   for (auto const & incl : fHeaders) {
      out << "#include \"" << incl << "\"\n";
   }
   out << std::endl;
   return out;
}

std::ostream &TModuleGenerator::WriteStringVec(const std::vector<std::string> &vec,
      std::ostream &out) const
{
   for (auto const & theStr : vec) {
      out << "\"" << theStr << "\",\n";
   }
   out << "0" << std::endl;
   return out;
}

std::ostream &TModuleGenerator::WriteStringPairVec(const StringPairVec_t &vec,
      std::ostream &out) const
{
   for (auto const & strPair : vec) {
      out << "\"" << strPair.first;
      if (!strPair.second.empty()) {
         out << "=";
         // Need to escape the embedded quotes.
         for (const char *c = strPair.second.c_str(); *c != '\0'; ++c) {
            if (*c == '"') {
               out << "\\\"";
            } else {
               out << *c;
            }
         }
      }
      out << "\",\n";
   }
   out << "0" << std::endl;
   return out;
}

//______________________________________________________________________________
void TModuleGenerator::WriteRegistrationSource(std::ostream &out,
      bool inlineHeaders,
      const std::string &fwdDeclnArgsToKeepString,
      const std::string &headersClassesMapString,
      const std::string &fwdDeclString) const
{

   std::string payloadCode;

   // Add defines and undefines to the payloadCode
   std::ostringstream definesAndUndefines;
   //    Anticipate the undefines.
   //    Suppose to have a namespace called "declarations" used in R5 for template
   //    instantiations in the header given to genreflex.
   //    Now, in this namespace, objects with some names, typically dummy, will be
   //    present.
   //    If you give such headers to cling to parse, problems will occour, as the
   //    names appear multiple times. One possible solution is to get out of this
   //    with preprocessor defines given to genreflex, redefining "declarations"
   //    to a hash or <project>_<package> via the build system.
   WritePPUndefines(definesAndUndefines);
   WritePPDefines(definesAndUndefines);
   payloadCode += definesAndUndefines.str();

   // If necessary, inline the headers
   std::string inlinedHeaders;
   if (inlineHeaders) {
      std::string hdrFullPath;
      for (auto const & hdrName : fHeaders) {
         hdrFullPath = hdrName;
         bool headerFound = false;
         if (!llvm::sys::fs::exists(hdrFullPath)) {
            for (auto const & incDir : fCompI) {
               hdrFullPath = incDir + ROOT::TMetaUtils::GetPathSeparator() + hdrName;
               if (llvm::sys::fs::exists(hdrFullPath)) {
                  headerFound = true;
                  break;
               }
            }
         } else {
            headerFound = true;
         }
         if (!headerFound) {
            ROOT::TMetaUtils::Error(0, "Cannot find header %s: cannot inline it.\n", hdrName.c_str());
         } else {
            std::ifstream headerFile(hdrFullPath.c_str());
            const std::string headerFileAsStr((std::istreambuf_iterator<char>(headerFile)),
                                              std::istreambuf_iterator<char>());
            inlinedHeaders += headerFileAsStr;
         }
      }

   } else {
      // Now, if not, just #include them in the payload
      for (auto & hdrName : fHeaders) {
         inlinedHeaders += "#include \"" + hdrName + "\"\n";
      }
   }

   // Recover old genreflex behaviour, i.e. do not print warnings due to glitches
   // in the headers at runtime. This is not synonym of ignoring warnings as they
   // will be printed at dictionary generation time.
   // In order to do this we leverage the diagnostic pragmas and, since there is no
   // way to express as a pragma the option "-Wno-deprecated" the
   // _BACKWARD_BACKWARD_WARNING_H macro, used to avoid to go through
   // backward/backward_warning.h.
   payloadCode += "#define _BACKWARD_BACKWARD_WARNING_H\n" +
                  inlinedHeaders + "\n"
                  "#undef  _BACKWARD_BACKWARD_WARNING_H\n";

   // Dictionary initialization code for loading the module
   out << "namespace {\n"
       "  void TriggerDictionaryInitialization_"
       << GetDictionaryName() << "_Impl() {\n"
       "    static const char* headers[] = {\n";
   if (inlineHeaders) {
      out << 0 ;
   } else {
      WriteHeaderArray(out);
   };
   out << "    };\n"
       "    static const char* includePaths[] = {\n";
   WriteIncludePathArray(out) <<
                              "    };\n"
                              "    static const char* fwdDeclCode = \n" << fwdDeclString << ";\n"
                              "    static const char* payloadCode = R\"DICTPAYLOAD(\n" << payloadCode << ")DICTPAYLOAD\";\n"
                              "    " << headersClassesMapString << "\n"
                              "    static bool isInitialized = false;\n"
                              "    if (!isInitialized) {\n"
                              "      TROOT::RegisterModule(\"" << GetDictionaryName() << "\",\n"
                              "        headers, includePaths, payloadCode, fwdDeclCode,\n"
                              "        TriggerDictionaryInitialization_" << GetDictionaryName() << "_Impl, " << fwdDeclnArgsToKeepString << ", classesHeaders);\n"
                              "      isInitialized = true;\n"
                              "    }\n"
                              "  }\n"
                              "  static struct DictInit {\n"
                              "    DictInit() {\n"
                              "      TriggerDictionaryInitialization_" << GetDictionaryName() << "_Impl();\n"
                              "    }\n"
                              "  } __TheDictionaryInitializer;\n"
                              "}\n"
                              "void TriggerDictionaryInitialization_" << GetDictionaryName() << "() {\n"
                              "  TriggerDictionaryInitialization_" << GetDictionaryName() << "_Impl();\n"
                              "}" << std::endl;
}

//______________________________________________________________________________
void TModuleGenerator::WriteContentHeader(std::ostream &out) const
{
   // Write a header file describing the content of this module
   // through a series of variables inside the namespace
   // ROOT::Dict::[DictionaryName]. Each variable is an array of string
   // literals, with a const char* of 0 being the last element, e.g.
   // ROOT::Dict::_DictName::arrIncludes[] = { "A.h", "B.h", 0 };

   out << "namespace ROOT { namespace Dict { namespace _"
       << GetDictionaryName() << "{\n";

   out << "const char* arrIncludes[] = {\n";
   WriteHeaderArray(out) << "};\n";

   out << "const char* arrIncludePaths[] = {\n";
   WriteIncludePathArray(out) << "};\n";
   /*
      out << "const char* arrDefines[] = {\n";
      WriteDefinesArray(out) << "};\n";

      out << "const char* arrUndefines[] = {\n";
      WriteUndefinesArray(out) << "};\n";*/

   out << "} } }" << std::endl;
}

//______________________________________________________________________________
void TModuleGenerator::WriteUmbrellaHeader(std::ostream &out) const
{
   // Write a header file pulling in the content of this module
   // through a series of #defined, #undefs and #includes.
   // The sequence corrsponds to a rootcling invocation with
   //   -c -DFOO -UBAR header.h
   // I.e. defines, undefines and finally includes.

   WritePPDefines(out);
   WritePPUndefines(out);
   WritePPIncludes(out);
}
