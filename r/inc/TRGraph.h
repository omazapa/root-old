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
         ClassDef(TRGraph, 0)
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRGraph)


#endif
