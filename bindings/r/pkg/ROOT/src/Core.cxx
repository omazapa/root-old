/*************************************************************************
 * Copyright (C) 2015, Omar Andres Zapata Mesa                           *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#include<Core.h>

using namespace ROOT::R;

//______________________________________________________________________________
ROOT::R::TRSystem::TRSystem(): TObject()
{
   th = nullptr;
}

//______________________________________________________________________________
void ROOT::R::TRSystem::ProcessEventsLoop()
{
   if (!gApplication) {
      Error("TRSystem", "Running ProcessEventsLoop without global object gApplication.");
      return;
   }
   th = new TThread([](void * args) {
      while (kTRUE) {
         gSystem->ProcessEvents();
         gSystem->Sleep(100);
      }
   }, (void *)this);
   th->Run();
}

//______________________________________________________________________________
Int_t ROOT::R::TRSystem::Load(TString module)
{
   return gSystem->Load(module.Data());
}


//namespace Rcpp {
//   template<> TObject* as(SEXP f)
//   {
//    return Rcpp::as<XPtr<TObject> >(f);
//   }
//}

ROOTR_MODULE(Core)
{

   ROOT::R::class_<ROOT::R::TRObject>("TObject", "Mother of all ROOT objects.")
   .constructor()
   .method("ClassName",&ROOT::R::TRObject::ClassName)
   .method("GetName",&ROOT::R::TRObject::GetName);
   
   ROOT::R::class_<ROOT::R::TRSystem>("TSystem", "TSystem class to manipulate ROOT's Process.")
   .constructor()
   .method("ProcessEventsLoop", &ROOT::R::TRSystem::ProcessEventsLoop)
   .method("Load", (Int_t(ROOT::R::TRSystem::*)(TString))&ROOT::R::TRSystem::Load)
   ;
}
