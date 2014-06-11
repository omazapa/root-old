#include<TRGraph.h>


using namespace ROOT::R;
ClassImp(TRGraph)
//______________________________________________________________________________
TRGraph::TRGraph(): TGraph()
{
}

//______________________________________________________________________________
TRGraph::TRGraph(Int_t n, std::vector<Double_t> x, std::vector<Double_t> y): TGraph(n, x.data(), y.data())
{
}

//______________________________________________________________________________
void TRGraph::Draw()
{
   TGraph::Draw();
}


ROOTR_MODULE(ROOTR_TRGraph)
{
   ROOT::R::class_<ROOT::R::TRGraph>("TRGraph")
   .constructor<int, std::vector<Double_t>, std::vector<Double_t> >()
   .method("Draw", (void (ROOT::R::TRGraph::*)())(&ROOT::R::TRGraph::Draw))
   .method("Draw", (void (ROOT::R::TRGraph::*)(const char *))(&ROOT::R::TRGraph::Draw))
   ;
}