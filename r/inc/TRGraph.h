// @(#)root/r:$Id$
// Author: Omar Zapata   26/05/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRGraph
#define ROOT_R_TRGraph

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_TGraph
#include<TGraph.h>
#endif
//________________________________________________________________________________________________________
/**
   This is TGraph class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {

      class TRGraph: public TGraph {
      public:
         TRGraph();
         TRGraph(Int_t n, std::vector<double> x, std::vector<double> y);
         void Draw();
//          ClassDef(TRGraph, 0)
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRGraph)

//______________________________________________________________________________
ROOT::R::TRGraph::TRGraph(): TGraph()
{
}

//______________________________________________________________________________
ROOT::R::TRGraph::TRGraph(Int_t n, std::vector<Double_t> x, std::vector<Double_t> y): TGraph(n, x.data(), y.data())
{
}

//______________________________________________________________________________
void ROOT::R::TRGraph::Draw()
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
#endif
