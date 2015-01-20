// @(#)root/r:$Id$
// Author: Omar Zapata   26/05/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_Gpad
#define ROOT_R_Gpad

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
         TRCanvas(TString name):TCanvas(name.Data(), "", 1){}
         TRCanvas(TString name,TString tittle):TCanvas(name.Data(), tittle.Data(), 1){}
         TRCanvas(TString name,TString tittle,Int_t form):TCanvas(name.Data(), tittle.Data(), form){}
         ~TRCanvas() {};
         
         void Draw(){TCanvas::Draw();}
         void Draw(TString opt){TCanvas::Draw(opt.Data());}
         void Write(TString a, Int_t b, Int_t c){TCanvas::Write(a.Data(),b,c);}
      };
   }
   
   
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRCanvas)

#endif
