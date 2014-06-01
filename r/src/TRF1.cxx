#include<TRF1.h>


using namespace ROOT::R;
ClassImp(TRF1)
//______________________________________________________________________________
TRF1::TRF1(): TObject()
{
   f1 = new TF1;
}

//______________________________________________________________________________
TRF1::TRF1(const TRF1 &f): TObject(f)
{
   f1 = f.f1;
}

//______________________________________________________________________________
TRF1::TRF1(std::string name, std::string formula)
{
   f1 = new TF1(name.c_str(), formula.c_str());
}

//______________________________________________________________________________
Double_t TRF1::Eval(Double_t x)
{
   return f1->Eval(x);
}

//______________________________________________________________________________
std::vector<Double_t> TRF1::Eval(std::vector<Double_t> x)
{
   std::vector<Double_t> result(x.size());
   for (unsigned int i = 0; i < x.size(); i++) result[i] = f1->Eval(x[i]);
   return result;
}

//______________________________________________________________________________
void TRF1::Draw()
{
   f1->Draw();
}

//______________________________________________________________________________
void TRF1::Draw(std::string options)
{
   f1->Draw(options.c_str());
}


ROOTR_MODULE(ROOTR_TRF1)
{

   Rcpp::class_<ROOT::R::TRF1>("TRF1")
   .constructor<std::string, std::string>()
   .method("Eval", (std::vector<Double_t> (ROOT::R::TRF1::*)(std::vector<Double_t>))&ROOT::R::TRF1::Eval)
   .method("Eval", (Double_t (ROOT::R::TRF1::*)(Double_t))&ROOT::R::TRF1::Eval)
   .method("Draw", (void (ROOT::R::TRF1::*)())(&ROOT::R::TRF1::Draw))
   .method("Draw", (void (ROOT::R::TRF1::*)(std::string))(&ROOT::R::TRF1::Draw))
   ;
}