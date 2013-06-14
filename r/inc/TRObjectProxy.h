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
*                                                                        *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
*************************************************************************/
#ifndef ROOT_R_TRObjectProxy
#define ROOT_R_TRObjectProxy
//ROOT headers
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
//pragma to disable warnings on Rcpp that have
//a so many noise compiling
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wshadow"
#endif
//R headers
#ifndef __CINT__
#include <RInside.h>
#include <Rcpp.h>
#else
class RInside;
class RInside::Proxy;
namespace Rcpp {
   class RObject;
   class NumericMatrix;
}
//internal R objects (at R api) Rinternals.h
typedef struct SEXPREC *SEXP;
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
         TRObjectProxy() {};
         TRObjectProxy(SEXP xx);

         void operator=(SEXP xx);
         TString toString();
         template<class Type> Type toScalar();
         template<class Type> TVectorT<Type> toVector();
         template<class TypeClass, class TypeData> TypeClass   toArray();
         template<class Type> TMatrixT<Type>   toMatrix();
         template <typename T> operator T() {
            return ::Rcpp::as<T>(x);
         }
         ClassDef(TRObjectProxy, 0) //
      };

   }

#ifndef __CINT__
//______________________________________________________________________________
   template<class Type> Type ROOT::R::TRObjectProxy::toScalar()
   {
      //Return R's scalars like  Integers and Doubles to Int_t and Doublet_t
      return ::Rcpp::as<Type>(x);
   }

//______________________________________________________________________________
   template<class Type> TVectorT<Type> ROOT::R::TRObjectProxy::toVector()
   {
      std::vector<Type> vec =::Rcpp::as<std::vector<Type> >(x);
      return TVectorT<Type>(vec.size(), vec.data());
   }

//______________________________________________________________________________
   template<class TypeClass, class TypeData> TypeClass   ROOT::R::TRObjectProxy::toArray()
   {
      std::vector<TypeData> vec =::Rcpp::as<std::vector<TypeData> >(x);
      return TypeClass(vec.size(), vec.data());
   }

//______________________________________________________________________________
   template<class Type> TMatrixT<Type>   ROOT::R::TRObjectProxy::toMatrix()
   {
      Rcpp::NumericMatrix mat =::Rcpp::as<Rcpp::NumericMatrix>(x);
      return TMatrixT<Type>(mat.nrow(), mat.ncol(), mat.begin(), "F");
   }

#endif

}


#endif