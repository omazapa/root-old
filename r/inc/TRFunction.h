// @(#)root/r:$Id$
// Author: Omar Zapata   16/06/2013

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
#ifndef ROOT_R_TRFunction
#define ROOT_R_TRFunction

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

//________________________________________________________________________________________________________
/**
   This is a class to pass functions from ROOT to R


   @ingroup R
*/

namespace ROOT {
   namespace R {

      class TRInterface;
      class TRFunction: public TObject {
         friend class TRInterface;
         friend SEXP Rcpp::wrap<TRFunction>(const TRFunction &f);

      protected:
         Rcpp::InternalFunction *f;
         static TF1 f1;
         static Double_t fFunctor1(Double_t x) {
            return f1(x);
         }
         static Double_t fFunctor1par(TVectorD x, TVectorD par) {
            f1.InitArgs(x.GetMatrixArray(), par.GetMatrixArray());
            return f1.EvalPar(x.GetMatrixArray(), par.GetMatrixArray());
         }
      public:
         TRFunction(): TObject() {
            f = NULL;
         }

         TRFunction(const TRFunction &fun);
         TRFunction(const TF1 &fun);
#ifndef __CINT__
         template<class T> TRFunction(T fun) {
            f = new Rcpp::InternalFunction(fun);
         }
#endif
//         operator SEXP(){return *f;}
         ClassDef(TRFunction, 0) //
      };
   }
}
#endif