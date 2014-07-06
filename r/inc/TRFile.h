// @(#)root/r:$Id$
// Author: Omar Zapata   5/06/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRFILE
#define ROOT_R_TRFILE

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_TFile
#include<TFile.h>
#endif

#ifndef ROOT_R_TRF1
#include<TRF1.h>
#endif

#ifndef ROOT_R_TRGraph
#include<TRGraph.h>
#endif

#ifndef ROOT_R_TRCanvas
#include<TRCanvas.h>
#endif

//________________________________________________________________________________________________________
/**
   This is TFile class for R


   @ingroup R
*/
namespace ROOT {
   namespace R {

      class TRFile: public TFile {
      public:
         TRFile();
         TRFile(const char *fname, Option_t *option = "", const char *ftitle = "", Int_t compress = 1);
         template<class T> T Get(const Char_t *object) {
            return *(T *)TFile::Get(object);
         }
         inline void Close() {
            TFile::Close(0);
         }
      };
   }
}
//______________________________________________________________________________
ROOT::R::TRFile::TRFile(): TFile()
{
}

//______________________________________________________________________________
ROOT::R::TRFile::TRFile(const char *fname, Option_t *option , const char *ftitle, Int_t compress): TFile(fname, option, ftitle, compress)
{

}

ROOTR_MODULE(ROOTR_TRFile)
{

   ROOT::R::class_<ROOT::R::TRFile>("TRFile", "TFile class to manipulate ROOT's files.")
   .constructor<const char *, Option_t *, const char *, Int_t>()
   .method("Map", (void (ROOT::R::TRFile::*)())&ROOT::R::TRFile::Map)
   .method("ls", (void (ROOT::R::TRFile::*)(Option_t *))&ROOT::R::TRFile::ls)
   .method("Flush", (void (ROOT::R::TRFile::*)())&ROOT::R::TRFile::Flush)
   .method("Close", (void (ROOT::R::TRFile::*)(Option_t *))&ROOT::R::TRFile::Close)
   .method("Close", (void (ROOT::R::TRFile::*)())&ROOT::R::TRFile::Close)
   .method("Get", &ROOT::R::TRFile::Get<ROOT::R::TRF1>)
   .method("Get", &ROOT::R::TRFile::Get<ROOT::R::TRGraph>)
//    .method("Get", &ROOT::R::TRFile::Get<ROOT::R::TRCanvas>)//TRCanvas no supported at the moment
   ;
}


#endif
