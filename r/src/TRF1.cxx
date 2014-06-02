#include<TRF1.h>


using namespace ROOT::R;
ClassImp(TRF1)
//______________________________________________________________________________
TRF1::TRF1(): TF1()
{
}

//______________________________________________________________________________
TRF1::TRF1(const TRF1 &f): TF1(f)
{
}

//______________________________________________________________________________
TRF1::TRF1(std::string name, std::string formula):TF1(name.c_str(), formula.c_str())
{
}

//______________________________________________________________________________
std::vector<Double_t> TRF1::Eval(std::vector<Double_t> x)
{
   std::vector<Double_t> result(x.size());
   for (unsigned int i = 0; i < x.size(); i++) result[i] = TF1::Eval(x[i]);
   return result;
}

//______________________________________________________________________________
void TRF1::Draw()
{
   TF1::Draw(0);
}

//______________________________________________________________________________
void TRF1::Draw(std::string options)//overloaded beacause Chart* poiter is not supported in Rcpp
{
   TF1::Draw(options.c_str());
}


ROOTR_MODULE(ROOTR_TRF1)
{

   ROOT::R::class_<ROOT::R::TRF1>("TRF1","1-Dim ROOT's function class")
   .constructor<std::string, std::string>()
   .method("Eval", (std::vector<Double_t> (ROOT::R::TRF1::*)(std::vector<Double_t>))&ROOT::R::TRF1::Eval)
   .method("Eval", (Double_t (ROOT::R::TRF1::*)(Double_t))&ROOT::R::TRF1::Eval)
   .method("Draw", (void (ROOT::R::TRF1::*)())(&ROOT::R::TRF1::Draw))
   .method("Draw", (void (ROOT::R::TRF1::*)(std::string))(&ROOT::R::TRF1::Draw))
   .method("SetRange", (void (ROOT::R::TRF1::*)(Double_t,Double_t))(&ROOT::R::TRF1::SetRange))
   .method("SetParameter", (void (ROOT::R::TRF1::*)(Int_t,Double_t))(&ROOT::R::TRF1::SetParameter))
   ;
}