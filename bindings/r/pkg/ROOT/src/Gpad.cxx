
#include<Gpad.h>

ROOTR_MODULE(Gpad)
{

   ROOT::R::class_<ROOT::R::TRCanvas>("TCanvas", "A Canvas is an area mapped to a window directly under the control of the display manager. ")
   .constructor<TString >()
   .constructor<TString , TString >()
   .constructor<TString , TString , Int_t>()
   .method("Draw", (void (ROOT::R::TRCanvas::*)())(&ROOT::R::TRCanvas::Draw))
   .method("Draw", (void (ROOT::R::TRCanvas::*)(TString))(&ROOT::R::TRCanvas::Draw))
   .method("Divide", (void (ROOT::R::TRCanvas::*)(Int_t, Int_t, Float_t, Float_t, Int_t))(&ROOT::R::TRCanvas::Divide))
   .method("Write", (Int_t(ROOT::R::TRCanvas::*)(TString , Int_t, Int_t))(&ROOT::R::TRCanvas::Write))
   .method("Update", (void(ROOT::R::TRCanvas::*)())(&ROOT::R::TRCanvas::Update))
   ;
}
