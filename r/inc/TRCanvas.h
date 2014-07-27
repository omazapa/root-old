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
         TRCanvas(const char *name):TCanvas(name, "", 1){}
         TRCanvas(const char *name,const char *tittle):TCanvas(name, tittle, 1){}
         ~TRCanvas() {};
         
         void Draw(){TCanvas::Draw();}
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRCanvas)


ROOTR_MODULE(ROOTR_TRCanvas)
{

   ROOT::R::class_<ROOT::R::TRCanvas>("TRCanvas", "A Canvas is an area mapped to a window directly under the control of the display manager. ")
   .constructor<const char *>()
   .constructor<const char *, const char *>()
   .constructor<const char *, const char *, Int_t>()
   .method("Draw", (void (ROOT::R::TRCanvas::*)())(&ROOT::R::TRCanvas::Draw))
   .method("Draw", (void (ROOT::R::TRCanvas::*)(std::string))(&ROOT::R::TRCanvas::Draw))
   .method("Divide", (void (ROOT::R::TRCanvas::*)(Int_t, Int_t, Float_t, Float_t, Int_t))(&ROOT::R::TRCanvas::Divide))
   .method("Write", (Int_t(ROOT::R::TRCanvas::*)(const char *, Int_t, Int_t))(&ROOT::R::TRCanvas::Write))
   .method("Update", (void(ROOT::R::TRCanvas::*)())(&ROOT::R::TRCanvas::Update))
   ;
}

#endif
