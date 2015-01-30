#include<Hist.h>

//______________________________________________________________________________
std::vector<Double_t> ROOT::R::TRF1::Eval(std::vector<Double_t> x)
{
   std::vector<Double_t> result(x.size());
   for (unsigned int i = 0; i < x.size(); i++) result[i] = TF1::Eval(x[i]);
   return result;
}

namespace Rcpp {
   template<> SEXP wrap(const TH1F &f)
   {
      return Rcpp::wrap(ROOT::R::TRH1F(f));
   }
   template<> TH1F as(SEXP f)
   {
      return Rcpp::as<ROOT::R::TRH1F>(f);
   }

    
   template<> SEXP wrap(const TF1 &f)
   {
      return Rcpp::wrap(ROOT::R::TRF1(f));
   }
   template<> TF1 as(SEXP f)
   {
      return Rcpp::as<ROOT::R::TRF1>(f);
   }
   
   template<> SEXP wrap(const TGraph &f)
   {
      return Rcpp::wrap(ROOT::R::TRGraph(f));
   }
   template<> TGraph as(SEXP f)
   {
      return Rcpp::as<ROOT::R::TRGraph>(f);
   }
}


ROOTR_MODULE(Hist)
{
   ROOT::R::class_<ROOT::R::TRH1F>("TH1F", " histograms with one float per channel.  Maximum precision 7 digits")
   .constructor<TString , TString , Int_t, Double_t, Double_t>()
   .constructor<ROOT::R::TRObjectPtr>()
   .method("FillRandom", (void (ROOT::R::TRH1F::*)(TString,Int_t))(&ROOT::R::TRH1F::FillRandom))
   .method("Draw", (void (ROOT::R::TRH1F::*)())(&ROOT::R::TRH1F::Draw))
   .method("Draw", (void (ROOT::R::TRH1F::*)(TString))(&ROOT::R::TRH1F::Draw))
   .method("Write", (Int_t(ROOT::R::TRH1F::*)(TString, Int_t, Int_t))(&ROOT::R::TRH1F::Write))
   .method("Write", (Int_t(ROOT::R::TRH1F::*)(TString))(&ROOT::R::TRH1F::Write));

    
    
   ROOT::R::class_<ROOT::R::TRF1>("TF1", "1-Dim ROOT's function class")
   .constructor<TString , TString , Double_t, Double_t>()
   .constructor<ROOT::R::TRObjectPtr>()
   .method("Eval", (std::vector<Double_t> (ROOT::R::TRF1::*)(std::vector<Double_t>))&ROOT::R::TRF1::Eval)
   .method("Eval", (Double_t (ROOT::R::TRF1::*)(Double_t))&ROOT::R::TRF1::Eval)
   .method("Draw", (void (ROOT::R::TRF1::*)())(&ROOT::R::TRF1::Draw))
   .method("Draw", (void (ROOT::R::TRF1::*)(TString))(&ROOT::R::TRF1::Draw))
   .method("SetRange", (void (ROOT::R::TRF1::*)(Double_t, Double_t))(&ROOT::R::TRF1::SetRange))
   .method("SetParameter", (void (ROOT::R::TRF1::*)(Int_t, Double_t))(&ROOT::R::TRF1::SetParameter))
   .method("Write", (Int_t(ROOT::R::TRF1::*)(TString, Int_t, Int_t))(&ROOT::R::TRF1::Write))
   .method("Write", (Int_t(ROOT::R::TRF1::*)(TString))(&ROOT::R::TRF1::Write));
   
   ROOT::R::class_<ROOT::R::TRGraph>("TGraph")
   .constructor<int, std::vector<Double_t>, std::vector<Double_t> >()
   .method("Draw", (void (ROOT::R::TRGraph::*)())(&ROOT::R::TRGraph::Draw))
   .method("Draw", (void (ROOT::R::TRGraph::*)(TString))(&ROOT::R::TRGraph::Draw));

   
}