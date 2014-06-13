#include<TRSystem.h>
#include<TApplication.h>
#include<TError.h>
using namespace ROOT::R;
ClassImp(TRSystem)

//______________________________________________________________________________
TRSystem::TRSystem(): TObject()
{
   th = nullptr;
}

void TRSystem::ProcessEventsLoop()
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

Int_t TRSystem::Load(const Char_t *module)
{
   return gSystem->Load(module);
}

ROOTR_MODULE(ROOTR_TRSystem)
{

   ROOT::R::class_<ROOT::R::TRSystem>("TRSystem", "TSystem class to manipulate ROOT's Process.")
   .constructor()
   .method("ProcessEventsLoop", &ROOT::R::TRSystem::ProcessEventsLoop)
   .method("Load", (Int_t(ROOT::R::TRSystem::*)(const Char_t *))&ROOT::R::TRSystem::Load)
   ;
}