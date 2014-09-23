// @(#)root/r:$Id$
// Author: Omar Zapata   29/05/2013

/*************************************************************************
* Copyright (C) 2013,  Gfif Developers                                   *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
* For the licensing terms see $ROOTSYS/LICENSE.                          *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
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

//pragma to disable warnings on Rcpp which have
//so many noise compiling
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wignored-qualifiers"
#pragma GCC diagnostic ignored "-Wunused-parameter"

#endif

#if  defined(__CINT__)
#include<compilerdata.h>
gSystem->AddIncludePath(RINCLUDEPATH);
gSystem->AddLinkedLibs(RLINKEDLIBS);
#endif


#ifndef __CINT__
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
#else
class RInside;
class RInside::Proxy;
namespace Rcpp {
   class RObject;
   class NumericMatrix;
   class NumericVector;
   class InternalFunction;
   class Environment;
   class Environment::Binding;

}
//internal R objects (at R api) Rinternals.h
typedef struct SEXPREC *SEXP;
#endif
#endif
