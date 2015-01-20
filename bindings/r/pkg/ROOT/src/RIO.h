// @(#)root/r:$Id$
// Author: Omar Zapata   5/06/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_RIO
#define ROOT_R_RIO

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_TFile
#include<TFile.h>
#endif

#ifndef ROOT_R_Core
#include<Core.h>
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
         TRFile():TFile(){}
         TRFile(TString fname):TFile(fname.Data()){}
         TRFile(TString fname, TString option):TFile(fname.Data(),option.Data()){}
         TRFile(TString fname, TString option, TString ftitle):TFile(fname.Data(),option.Data()){}
	 TRFile(TString fname, TString option, TString ftitle, Int_t compress );
	 
         template<class T> T Get(TString object) {
            return *(T *)TFile::Get(object);
         }
         inline void Close() {
            TFile::Close(0);
         }
         inline void Close(TString opt) {
            TFile::Close(opt.Data());
         }
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRFile)
#endif
