// @(#)root/r:$Id$
// Author: Omar Zapata   26/05/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TCanvas
#define ROOT_R_TCanvas

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_TCanvas
#include<TCanvas.h>
#endif
//________________________________________________________________________________________________________
/**
   This is TCanvas class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {

      class TRCanvas: public TObject {
      protected:
         TCanvas *c;
      public:
         TRCanvas();
         TRCanvas(const TRCanvas &);
         TRCanvas(std::string name, std::string tittle);
         ~TRCanvas() {
            delete c;
         }
         void Draw();
         void Draw(std::string options);
         ClassDef(TRCanvas, 0)
      };
   }
}



#endif
