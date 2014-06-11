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

      class TRCanvas: public TCanvas {
      public:
         TRCanvas();
         TRCanvas(const char *name, const char *title = "", Int_t form = 1);
         void Draw();
         ClassDef(TRCanvas, 0)
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRCanvas)


#endif
