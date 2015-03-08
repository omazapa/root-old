// @(#)root/r:$Id$
// Author: Omar Zapata   3/01/2015


/*************************************************************************
 * Copyright (C)  2015, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_Core
#define ROOT_R_Core

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif


#ifndef ROOT_TObject
#include<TObject.h>
#endif

#ifndef ROOT_TSystem
#include<TSystem.h>
#endif

#ifndef ROOT_TThread
#include<TThread.h>
#endif

#ifndef ROOT_TApplication
#include<TApplication.h>
#endif

namespace ROOT {
   namespace R {
//________________________________________________________________________________________________________
/**
   This is a TObject wrap for R


   @ingroup R
*/
      class TRObject: public TObject {
      public:
         TRObject():TObject(){};
         TRObject(const TObject &obj):TObject(obj){};
         TRObject(const TRObject &obj):TObject(obj){};
         TString ClassName(){return TObject::ClassName();}
         TString GetName(){return TObject::GetName();}
         
      };

//________________________________________________________________________________________________________
/**
   This is a gSystem wrap for R


   @ingroup R
*/
      class TRSystem: public TObject {
      private:
         TThread *th;
      public:
         TRSystem();
         ~TRSystem() {
            if (th) delete th;
         }
         void ProcessEventsLoop();
         Int_t   Load(TString module);
      };
      

      //________________________________________________________________________________________________________
/**
   This is a TObject pointer wrap for R


   @ingroup R
*/
//          class TRObjectPtr:public Rcpp::XPtr<TRObject>
//          {
//            TRObjectPtr(TRObject *obj):XPtr(obj){}
//            
//          }
      
typedef Rcpp::XPtr<ROOT::R::TRObject> TRObjectPtr;      
   }
}

ROOTR_EXPOSED_CLASS_INTERNAL(TRObject)
ROOTR_EXPOSED_CLASS_INTERNAL(TRSystem)


#endif
