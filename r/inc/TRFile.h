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
         ClassDef(TRFile, 0)
      };
   }
}



#endif
