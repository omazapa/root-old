// @(#)root/r:$Id$
// Author: Omar Zapata   29/05/2013

/*************************************************************************
 * Copyright (C) 2013-2014, Omar Andres Zapata Mesa                      *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRObjectProxy
#define ROOT_R_TRObjectProxy

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif
//________________________________________________________________________________________________________
/**
   This is a class to get ROOT's objects from R's objects


   @ingroup R
*/

namespace ROOT {
   namespace R {
      class TRObjectProxy: public TObject {
      private:
         Rcpp::RObject x;
      public:
         TRObjectProxy(): TObject() {};
         TRObjectProxy(SEXP xx);

         void operator=(SEXP xx);

         template<class T> T As() {
            return ::Rcpp::as<T>(x);
         }

         template<class T> T operator=(TRObjectProxy &obj) {
            return ::Rcpp::as<T>(obj);
         }

         template <typename T> operator T() {
            return ::Rcpp::as<T>(x);
         }
         ClassDef(TRObjectProxy, 0) //
      };

   }
}


#endif
