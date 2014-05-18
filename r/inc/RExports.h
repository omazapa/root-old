// @(#)root/r:$Id$
// Author: Omar Zapata   29/05/2013


/*************************************************************************
 * Copyright (C) 2013-2014, Omar Andres Zapata Mesa                      *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_RExports
#define ROOT_R_RExports
//ROOT headers
#ifndef ROOT_Rtypes
#include<Rtypes.h>
#endif

#ifndef ROOT_TString
#include<TString.h>
#endif

#ifndef ROOT_TVectorD
#include<TVectorD.h>
#endif

#ifndef ROOT_TMatrixD
#include<TMatrixD.h>
#endif

#ifndef ROOT_TArrayD
#include<TArrayD.h>
#endif

#ifndef ROOT_TArrayF
#include<TArrayF.h>
#endif

#ifndef ROOT_TArrayI
#include<TArrayI.h>
#endif

//std headers
#include<string>
#include<vector>
//support for std c++11 classes
#if __cplusplus > 199711L
#include<array>
#endif

//pragma to disable warnings on Rcpp which have
//so many noise compiling
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#endif

// #if  defined(__CINT__)
// #include<compilerdata.h>
// gSystem->AddIncludePath(RINCLUDEPATH);
// gSystem->AddLinkedLibs(RLINKEDLIBS);
// #endif


#include<RcppCommon.h>
namespace ROOT {
   namespace R {
      class TRFunction;
   }
}
namespace Rcpp {

   template<> SEXP wrap(const TString &s);
   template<> TString as(SEXP) ;

   template<> SEXP wrap(const TVectorD &v);
   template<> TVectorD as(SEXP) ;

   template<> SEXP wrap(const TMatrixD &m);
   template<> TMatrixD as(SEXP) ;

}
#include<Rcpp.h>//this headers should be called after templates definitions
#include<RInside.h>
#endif
