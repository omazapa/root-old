// @(#)root/r:$Id$
// Author: Omar Zapata   26/05/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRF1
#define ROOT_R_TRF1

#ifndef ROOT_TF1
#include<TF1.h>
#endif

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

//________________________________________________________________________________________________________
/**
   This is TF1's wrapper class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {
      class TRF1: public TF1 {
      public:
         TRF1();
         TRF1(const TF1 &f1): TF1(f1) {}
         TRF1(Char_t *name, Char_t *formula, Double_t xmin = 0, Double_t xmax = 1);
         std::vector<Double_t> Eval(std::vector<Double_t> x);
         void Draw();
         inline Int_t Write(const Char_t *name) {
            return TF1::Write(name);
         }
      };
   }
}

namespace Rcpp {
   template<> SEXP wrap(const TF1 &f)
   {
      return Rcpp::wrap(ROOT::R::TRF1(f));
   }
   template<> TF1 as(SEXP f)
   {
      return Rcpp::as<ROOT::R::TRF1>(f);
   }
}

ROOTR_EXPOSED_CLASS_INTERNAL(TRF1)
//______________________________________________________________________________
ROOT::R::TRF1::TRF1(): TF1()
{
}

//______________________________________________________________________________
ROOT::R::TRF1::TRF1(Char_t *name, Char_t *formula, Double_t xmin, Double_t xmax): TF1(name, formula, xmin, xmax)
{
}

//______________________________________________________________________________
std::vector<Double_t> ROOT::R::TRF1::Eval(std::vector<Double_t> x)
{
   std::vector<Double_t> result(x.size());
   for (unsigned int i = 0; i < x.size(); i++) result[i] = TF1::Eval(x[i]);
   return result;
}

//______________________________________________________________________________
void ROOT::R::TRF1::Draw()
{
   TF1::Draw(0);
}


ROOTR_MODULE(ROOTR_TF1)
{

   ROOT::R::class_<ROOT::R::TRF1>("TF1", "1-Dim ROOT's function class")
   .constructor<Char_t *, Char_t *, Double_t, Double_t>()
   .method("Eval", (std::vector<Double_t> (ROOT::R::TRF1::*)(std::vector<Double_t>))&ROOT::R::TRF1::Eval)
   .method("Eval", (Double_t (ROOT::R::TRF1::*)(Double_t))&ROOT::R::TRF1::Eval)
   .method("Draw", (void (ROOT::R::TRF1::*)())(&ROOT::R::TRF1::Draw))
   .method("Draw", (void (ROOT::R::TRF1::*)(const char *))(&ROOT::R::TRF1::Draw))
   .method("SetRange", (void (ROOT::R::TRF1::*)(Double_t, Double_t))(&ROOT::R::TRF1::SetRange))
   .method("SetParameter", (void (ROOT::R::TRF1::*)(Int_t, Double_t))(&ROOT::R::TRF1::SetParameter))
   .method("Write", (Int_t(ROOT::R::TRF1::*)(const char *, Int_t, Int_t))(&ROOT::R::TRF1::Write))
   .method("Write", (Int_t(ROOT::R::TRF1::*)(const char *))(&ROOT::R::TRF1::Write))
   ;
}

#endif
