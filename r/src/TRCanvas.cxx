#include<TRCanvas.h>


using namespace ROOT::R;
ClassImp(TRCanvas)
//______________________________________________________________________________
TRCanvas::TRCanvas(): TCanvas()
{
}

//______________________________________________________________________________
TRCanvas::TRCanvas(std::string name, std::string tittle):TCanvas(name.c_str(), tittle.c_str())
{
}

//______________________________________________________________________________
void TRCanvas::Draw()
{
   TCanvas::Draw();
}

//______________________________________________________________________________
void TRCanvas::Draw(std::string options)
{
   TCanvas::Draw(options.c_str());
}


ROOTR_MODULE(ROOTR_TRCanvas)
{

   ROOT::R::class_<ROOT::R::TRCanvas>("TRCanvas")
   .constructor<std::string, std::string>()
   .method("Draw", (void (ROOT::R::TRCanvas::*)())(&ROOT::R::TRCanvas::Draw))
   .method("Draw", (void (ROOT::R::TRCanvas::*)(std::string))(&ROOT::R::TRCanvas::Draw))
   ;
}