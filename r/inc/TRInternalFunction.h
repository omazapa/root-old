// @(#)root/r:$Id$
// Author: Omar Zapata   07/06/2014


/*************************************************************************
 * Copyright (C) 2013-2014, Omar Andres Zapata Mesa                      *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRInternalFunction
#define ROOT_R_TRInternalFunction

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

//________________________________________________________________________________________________________
/**
   This is a class to support deprecated method to pass function to R's Environment,
   based in Rcpp::InternalFunction


   @ingroup R
*/
namespace ROOT {
   namespace R {
      
      class TRInternalFunction  {
      public:

      #include<TRInternalFunction__ctors.h>

      inline SEXP asSexp() const { return m_sexp ; }
      private:
	
	inline void set( SEXP xp){
		Rcpp::Environment RCPP = Rcpp::Environment::Rcpp_namespace() ;
		Rcpp::Function intf = RCPP["internal_function"] ;
		setSEXP( intf( xp ) ) ; 
	}
       void setSEXP(SEXP x){
    
        // replace the currently protected SEXP by the new one
        m_sexp = Rcpp::Rcpp_ReplaceObject(m_sexp, x) ;
         }
       SEXP m_sexp;
      };
   }
}

#endif