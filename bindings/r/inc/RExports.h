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
// #if __cplusplus > 199711L
#include<array>
// #endif

//pragma to disable warnings on Rcpp which have
//so many noise compiling
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Woverloaded-virtual"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wignored-qualifiers"
#endif


#include<RcppCommon.h>
namespace ROOT {
   namespace R {
      class TRFunction;
      class TRObjectProxy;
   }
}

namespace Rcpp {

//TString
   template<> inline SEXP wrap(const TString &s)
   {
      return wrap(std::string(s.Data()));
   }
   template<> inline TString as(SEXP s)
   {
      return TString(::Rcpp::as<std::string>(s).c_str());
   }

   template<> SEXP wrap(const TVectorD &v);
   template<> TVectorD as(SEXP) ;

   template<> SEXP wrap(const TMatrixD &m);
   template<> TMatrixD as(SEXP) ;

   template<> SEXP wrap(const ROOT::R::TRObjectProxy &o);
   template<> ROOT::R::TRObjectProxy as(SEXP) ;

   template<class T, size_t i> std::array<T, i> as(SEXP &obj)
   {
      std::vector<T> v = Rcpp::as<std::vector<T> >(obj);
      std::array<T, i> a;
      std::copy(v.begin(), v.end(), a.begin());
      return a;
   }

   namespace traits {
      template <typename T, size_t i>
      class Exporter<std::array<T, i> > {
      public:
         Exporter(SEXP x) {
            t = Rcpp::as<T, i>(x);
         }
         std::array<T, i> get() {
            return t;
         }
      private:
         std::array<T, i> t;
      } ;
   }
}
#include<Rcpp.h>//this headers should be called after templates definitions
#undef HAVE_UINTPTR_T
#include<RInside.h>

namespace ROOT {
   namespace R {
      //reference to internal ROOTR's Module that call ROOT's classes in R
      extern  VARIABLE_IS_NOT_USED SEXP ModuleSymRef;
      template<class T> class class_: public Rcpp::class_<T> {
      public:
         class_(const char *name_, const char *doc = 0): Rcpp::class_<T>(name_, doc) {}
      };

      //________________________________________________________________________________________________________
      template<class T> void function(const char *name_, T fun, const char *docstring = 0)
      {
         //template function required to create modules using the macro ROOTR_MODULE
         Rcpp::function(name_, fun, docstring);
      }
   }
}

//macros redifined to be accord with the namespace
#define ROOTR_MODULE RCPP_MODULE
#define ROOTR_EXPOSED_CLASS RCPP_EXPOSED_CLASS

//modified definiton to support ROOTR namespace
#define ROOTR_EXPOSED_CLASS_INTERNAL(CLASS)\
   namespace ROOT{                         \
      namespace R{                         \
         class CLASS;                      \
      }}                                   \
   RCPP_EXPOSED_CLASS_NODECL(ROOT::R::CLASS)



//modified macro for ROOTR global Module Object Symbol Reference ROOT::R::ModuleSymRef
#define LOAD_ROOTR_MODULE(NAME) Rf_eval( Rf_lang2( ( ROOT::R::ModuleSymRef == NULL ? ROOT::R::ModuleSymRef = Rf_install("Module") : ROOT::R::ModuleSymRef ), _rcpp_module_boot_##NAME() ), R_GlobalEnv )
#endif
