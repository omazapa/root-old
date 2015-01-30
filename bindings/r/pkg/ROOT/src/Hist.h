// @(#)root/r:$Id$
// Author: Omar Zapata   26/05/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_Hist
#define ROOT_R_Hist

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_R_Core
#include<Core.h>
#endif

#ifndef ROOT_TF1
#include<TF1.h>
#endif

#ifndef ROOT_TH1F
#include<TH1F.h>
#endif

#ifndef ROOT_TGraph
#include<TGraph.h>
#endif

//________________________________________________________________________________________________________
/**
   This is TH1F's wrapper class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {
      class TRH1F: public TH1F {
      public:
         TRH1F():TH1F(){}
         TRH1F(const TH1F &f1): TH1F(f1) {}
         TRH1F(TRObjectPtr obj): TH1F((const TH1F &)*obj) {}
         TRH1F(TString name, TString tittle, Int_t nbinsx, Double_t xlow, Double_t xup):TH1F(name.Data(), tittle.Data(), nbinsx,xlow,xup){}
         void FillRandom(TString fname, Int_t ntimes = 5000){TH1F::FillRandom(fname.Data(),ntimes);}
         void Draw(){TH1F::Draw();}
         void Draw(TString opt){TH1F::Draw(opt.Data());}
         inline Int_t Write(const TString name) {
            return TH1F::Write(name.Data());
         }
         inline Int_t Write(const TString name, Int_t option,Int_t bufsize) {
            return TH1F::Write(name.Data(),option,bufsize);
         }
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRH1F)

namespace Rcpp {
   template<> SEXP wrap(const TH1F &f);
   template<> TH1F as(SEXP f);
}


//________________________________________________________________________________________________________
/**
   This is TF1's wrapper class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {
      class TRF1: public TF1 {
      public:
         TRF1():TF1(){}
         TRF1(const TF1 &f1): TF1(f1) {}
         TRF1(TRObjectPtr obj): TF1((const TF1 &)*obj) {}
         TRF1(TString name, TString formula, Double_t xmin = 0, Double_t xmax = 1):TF1(name.Data(), formula.Data(), xmin, xmax){}
         std::vector<Double_t> Eval(std::vector<Double_t> x);
         void Draw(){TF1::Draw();}
         void Draw(TString opt){TF1::Draw(opt.Data());}
         inline Int_t Write(const TString name) {
            return TF1::Write(name.Data());
         }
         inline Int_t Write(const TString name, Int_t option,Int_t bufsize) {
            return TF1::Write(name.Data(),option,bufsize);
         }
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRF1)

namespace Rcpp {
   template<> SEXP wrap(const TF1 &f);
   template<> TF1 as(SEXP f);
}

//________________________________________________________________________________________________________
/**
   This is TGraph class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {

      class TRGraph: public TGraph {
      public:
         TRGraph(): TGraph() {};
         TRGraph(const TGraph &g): TGraph(g) {};
         TRGraph(Int_t n, std::vector<double> x, std::vector<double> y): TGraph(n, x.data(), y.data()){}
         void Draw(){TGraph::Draw();}
         void Draw(TString opt){TGraph::Draw(opt.Data());}
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRGraph)

namespace Rcpp {
   template<> SEXP wrap(const TGraph &f);
   template<> TGraph as(SEXP f);
}


#endif
