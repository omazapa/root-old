#include<TRGraph.h>


using namespace ROOT::R;
ClassImp(TRGraph)
//______________________________________________________________________________
TRGraph::TRGraph(): TObject()
{
   graph = new TGraph;
}

//______________________________________________________________________________
TRGraph::TRGraph(const TRGraph &g)
{
   graph = g.graph;
}

//______________________________________________________________________________
TRGraph::TRGraph(Int_t n, std::vector<Double_t> x, std::vector<Double_t> y)
{
   graph = new TGraph(n, (const Double_t *)x.data(), (const Double_t *)y.data());
}

//______________________________________________________________________________
void TRGraph::Draw(std::string options)
{
   graph->Draw(options.c_str());
}

ROOTR_MODULE(ROOTR_TRGraph)
{
   Rcpp::class_<ROOT::R::TRGraph>("TRGraph")
   .constructor<int, std::vector<Double_t>, std::vector<Double_t> >()
   .method("Draw", &ROOT::R::TRGraph::Draw)
   ;
}