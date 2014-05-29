#include<TRCanvas.h>


using namespace ROOT::R;
ClassImp(TRCanvas)
//______________________________________________________________________________
TRCanvas::TRCanvas():TObject()
{
 c=new TCanvas;
}

//______________________________________________________________________________
TRCanvas::TRCanvas(const TRCanvas &ca)
{
  c=ca.c;
}

//______________________________________________________________________________
TRCanvas::TRCanvas(std::string name,std::string tittle)
{
  c=new TCanvas(name.c_str(),tittle.c_str());
}

//______________________________________________________________________________
void TRCanvas::Draw()
{
  c->Draw();
}

//______________________________________________________________________________
void TRCanvas::Draw(std::string options)
{
  c->Draw(options.c_str());
}


ROOTR_MODULE(ROOTR_TRCanvas) {
    
    Rcpp::class_<ROOT::R::TRCanvas>( "TRCanvas" )
    .constructor<std::string,std::string>()
    .method( "Draw", (void (ROOT::R::TRCanvas::*)())(&ROOT::R::TRCanvas::Draw))
    .method( "Draw", (void (ROOT::R::TRCanvas::*)(std::string))(&ROOT::R::TRCanvas::Draw))
    ;
}