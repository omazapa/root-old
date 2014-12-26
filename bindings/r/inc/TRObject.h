// @(#)root/r:$Id$
// Author: Omar Zapata   26/12/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRObject
#define ROOT_R_TRObject

#ifndef ROOT_TObject
#include<TObject.h>
#endif

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

//________________________________________________________________________________________________________
/**
   This is TObject's wrapper class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {
      class TRObject: public TObject {
      public:
         TRObject():TObject(){};
         TRObject(const TObject &obj):TObject(obj){};
         TString ClassName(){return TObject::ClassName();}

         static void Load();
         
       ClassDef(TRObject, 0)   
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRObject)
namespace Rcpp {
   template<> SEXP wrap(const TObject &obj);
   template<> TObject as(SEXP obj);
}
#endif
