// @(#)root/meta:$Id$
// Author: Bianca-Cristina Cristescu   10/07/13

/*************************************************************************
 * Copyright (C) 1995-2013, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// The TEnum class implements the enum type.                            //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "TEnum.h"
#include "TEnumConstant.h"
#include "TInterpreter.h"
#include "TClass.h"
#include "TClassEdit.h"
#include "TClassTable.h"
#include "TProtoClass.h"
#include "TROOT.h"

ClassImp(TEnum)

//______________________________________________________________________________
TEnum::TEnum(const char *name, void *info, TClass *cls)
   : fInfo(info), fClass(cls)
{
   //Constructor for TEnum class.
   //It take the name of the TEnum type, specification if it is global
   //and interpreter info.
   //Constant List is owner if enum not on global scope (thus constants not
   //in TROOT::GetListOfGlobals).
   SetName(name);
   if (cls) {
      fConstantList.SetOwner(kTRUE);
   }

   // Determine fQualName
   if (0 != strcmp("",GetTitle())){ // It comes from a protoclass
      fQualName = std::string(GetTitle()) + "::" + GetName();
   }
   else if (GetClass()){ // It comes from a class/ns
      fQualName = std::string(GetClass()->GetName()) + "::" + GetName();
   }
   else { // it is in the global scope
      fQualName = GetName();
   }
}

//______________________________________________________________________________
TEnum::~TEnum()
{
   //Destructor
}

//______________________________________________________________________________
void TEnum::AddConstant(TEnumConstant *constant)
{
   //Add a EnumConstant to the list of constants of the Enum Type.
   fConstantList.Add(constant);
}

//______________________________________________________________________________
Bool_t TEnum::IsValid()
{
   // Return true if this enum object is pointing to a currently
   // loaded enum.  If a enum is unloaded after the TEnum
   // is created, the TEnum will be set to be invalid.

   // Register the transaction when checking the validity of the object.
   if (!fInfo && UpdateInterpreterStateMarker()) {
      DeclId_t newId = gInterpreter->GetEnum(fClass, fName);
      if (newId) {
         Update(newId);
      }
      return newId != 0;
   }
   return fInfo != 0;
}

//______________________________________________________________________________
Long_t TEnum::Property() const
{
   // Get property description word. For meaning of bits see EProperty.

   return kIsEnum;
}

//______________________________________________________________________________
void TEnum::Update(DeclId_t id)
{
   fInfo = (void *)id;
}

//______________________________________________________________________________
TEnum *TEnum::GetEnum(const std::type_info &ti, ESearchAction sa)
{
   int errorCode = 0;
   char *demangledEnumName = TClassEdit::DemangleName(ti.name(), errorCode);

   if (errorCode != 0) {
      if (!demangledEnumName) {
         free(demangledEnumName);
      }
      std::cerr << "ERROR TEnum::GetEnum - A problem occurred while demangling name.\n";
      return nullptr;
   }

   const char *constDemangledEnumName = demangledEnumName;
   TEnum *en = TEnum::GetEnum(constDemangledEnumName, sa);
   free(demangledEnumName);
   return en;

}

//______________________________________________________________________________
TEnum *TEnum::GetEnum(const char *enumName, ESearchAction sa)
{
   // Static function to retrieve enumerator from the ROOT's typesystem.
   // It has no side effect, except when the load flag is true. In this case,
   // the load of the library containing the scope of the enumerator is attempted.
   // There are two top level code paths: the enumerator is scoped or isn't.
   // If it is not, a lookup in the list of global enums is performed.
   // If it is, two lookups are carried out for its scope: one in the list of
   // classes and one in the list of protoclasses. If a scope with the desired name
   // is found, the enum is searched. If the scope is not found, and the load flag is
   // true, the aforementioned two steps are performed again after an autoload attempt
   // with the name of the scope as key is tried out.
   // If the interpreter lookup flag is false, the ListOfEnums objects are not treated
   // as such, but rather as THashList objects. This prevents any flow of information
   // from the interpreter into the ROOT's typesystem: a snapshot of the typesystem
   // status is taken.

   // Potential optimisation: reduce number of branches using partial specialisation of
   // helper functions.

   TEnum *theEnum = nullptr;

   // Wrap some gymnastic around the enum finding. The special treatment of the
   // ListOfEnums objects is located in this routine.
   auto findEnumInList = [](const TCollection * l, const char * enName, ESearchAction sa_local) {
      TObject *obj;
      if (sa_local & kInterpLookup) {
         obj = l->FindObject(enName);
      } else {
         auto enumTable = dynamic_cast<const THashList *>(l);
         obj = enumTable->THashList::FindObject(enName);
      }
      return static_cast<TEnum *>(obj);
   };

   // Helper routine to look fo the scope::enum in the typesystem.
   // If autoload and interpreter lookup is allowed, TClass::GetClass is called.
   // If not, the list of classes and the list of protoclasses is inspected.
   auto searchEnum = [&theEnum, findEnumInList](const char * scopeName, const char * enName, ESearchAction sa_local) {
      // Check if the scope is a class
      if (sa_local == (kALoadAndInterpLookup)) {
         auto scope = TClass::GetClass(scopeName, true);
         TEnum *en = nullptr;
         if (scope) en = findEnumInList(scope->GetListOfEnums(), enName, sa_local);
         return en;
      }

      if (auto tClassScope = static_cast<TClass *>(gROOT->GetListOfClasses()->FindObject(scopeName))) {
         // If this is a class, load only if the user allowed interpreter lookup
         // If this is a namespace and the user did not allow for interpreter lookup, load but before disable
         // autoparsing if enabled.
         bool canLoadEnums (sa_local & kInterpLookup);
         const bool scopeIsNamespace (tClassScope->Property() & kIsNamespace);

         const bool autoParseSuspended = gInterpreter->IsAutoParsingSuspended();
         const bool suspendAutoParse = autoParseSuspended || scopeIsNamespace;

         TInterpreter::SuspendAutoParsing autoParseRaii(gInterpreter, suspendAutoParse);

         if (scopeIsNamespace && !autoParseSuspended){
            canLoadEnums=true;
         }

         auto listOfEnums = tClassScope->GetListOfEnums(canLoadEnums);

         // Previous incarnation of the code re-enabled the auto parsing,
         // before executing findEnumInList
         theEnum = findEnumInList(listOfEnums, enName, sa_local);
      }
      // Check if the scope is still a protoclass
      else if (auto tProtoClassscope = static_cast<TProtoClass *>((gClassTable->GetProtoNorm(scopeName)))) {
         auto listOfEnums = tProtoClassscope->GetListOfEnums();
         if (listOfEnums) theEnum = findEnumInList(listOfEnums, enName, sa_local);
      }
      return theEnum;
   };

   const auto lastPos = strrchr(enumName, ':');
   if (lastPos != nullptr) {
      // We have a scope
      // All of this C gymnastic is to avoid allocations on the heap
      const auto enName = lastPos + 1;
      const auto scopeNameSize = ((Long64_t)lastPos - (Long64_t)enumName) / sizeof(decltype(*lastPos)) - 1;
#ifdef R__WIN32
      char *scopeName = new char[scopeNameSize + 1];
#else
      char scopeName[scopeNameSize + 1]; // on the stack, +1 for the terminating character '\0'
#endif
      strncpy(scopeName, enumName, scopeNameSize);
      scopeName[scopeNameSize] = '\0';
      // Three levels of search
      theEnum = searchEnum(scopeName, enName, kNone);
      if (!theEnum && (sa & kAutoload)) {
         const auto libsLoaded = gInterpreter->AutoLoad(scopeName);
         // It could be an enum in a scope which is not selected
         if (libsLoaded == 0){
            gInterpreter->AutoLoad(enumName);
         }
         theEnum = searchEnum(scopeName, enName, kAutoload);
      }
      if (!theEnum && (sa & kALoadAndInterpLookup)) {
         if (gDebug > 0) {
            printf("TEnum::GetEnum: Header Parsing - The enumerator %s is not known to the typesystem: an interpreter lookup will be performed. This can imply parsing of headers. This can be avoided selecting the numerator in the linkdef/selection file.\n", enumName);
         }
         theEnum = searchEnum(scopeName, enName, kALoadAndInterpLookup);
      }
#ifdef R__WIN32
      delete [] scopeName;
#endif
   } else {
      // We don't have any scope: this is a global enum
      theEnum = findEnumInList(gROOT->GetListOfEnums(), enumName, kNone);
      if (!theEnum && (sa & kAutoload)) {
         gInterpreter->AutoLoad(enumName);
         theEnum = findEnumInList(gROOT->GetListOfEnums(), enumName, kAutoload);
      }
      if (!theEnum && (sa & kALoadAndInterpLookup)) {
         if (gDebug > 0) {
            printf("TEnum::GetEnum: Header Parsing - The enumerator %s is not known to the typesystem: an interpreter lookup will be performed. This can imply parsing of headers. This can be avoided selecting the numerator in the linkdef/selection file.\n", enumName);
         }
         theEnum = findEnumInList(gROOT->GetListOfEnums(), enumName, kALoadAndInterpLookup);
      }
   }

   return theEnum;
}
