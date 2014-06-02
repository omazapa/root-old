// @(#)root/r:$Id$
// Author: Omar Zapata   26/05/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRF1
#define ROOT_R_TRF1

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_TF1
#include<TF1.h>
#endif
//________________________________________________________________________________________________________
/**
   This is TF1 class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {

      class TRF1: public TF1 {
      public:
         TRF1();
         TRF1(const TRF1 &);
         TRF1(std::string name, std::string formula);
         std::vector<Double_t> Eval(std::vector<Double_t> x);
         void Draw();
         void Draw(std::string options);
         ClassDef(TRF1, 0)
      };
   }
}



#endif
