#include<TRCanvas.h>
#include<TApplication.h>

using namespace ROOT::R;
ClassImp(TRCanvas)
//______________________________________________________________________________
TRCanvas::TRCanvas(): TCanvas()
{
}

//______________________________________________________________________________
TRCanvas::TRCanvas(const char *name, const char *title, Int_t form): TCanvas(name, title, form)
{

}

//______________________________________________________________________________
void TRCanvas::Draw()
{
   TCanvas::Draw();
}



ROOTR_MODULE(ROOTR_TRCanvas)
{

   ROOT::R::class_<ROOT::R::TRCanvas>("TRCanvas", "A Canvas is an area mapped to a window directly under the control of the display manager. ")
   .constructor<const char *, const char *, Int_t>()
   .method("Draw", (void (ROOT::R::TRCanvas::*)())(&ROOT::R::TRCanvas::Draw))
   .method("Draw", (void (ROOT::R::TRCanvas::*)(std::string))(&ROOT::R::TRCanvas::Draw))
   .method("Write", (Int_t(ROOT::R::TRCanvas::*)(const char *, Int_t, Int_t))(&ROOT::R::TRCanvas::Write))   
   .method("Update", (void(ROOT::R::TRCanvas::*)())(&ROOT::R::TRCanvas::Update))
   ;
}