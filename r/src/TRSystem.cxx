#include<TRSystem.h>

using namespace ROOT::R;
ClassImp(TRSystem)
//______________________________________________________________________________
TRSystem::TRSystem(): TSystem()
{
}

void TRSystem::ProcessEventsLoop()
{
  th=new TThread( [] (void *args) { while(kTRUE){gSystem->ProcessEvents(); gSystem->Sleep(10);  }} );
  th->Run();
}

// void TRSystem::ProcessEvents()
// {
//   gSystem->ProcessEvents();
// }

ROOTR_MODULE(ROOTR_TRSystem)
{

   ROOT::R::class_<ROOT::R::TRSystem>("TRSystem", "TSystem class to manipulate ROOT's Process.")
   .constructor()
   .method("ProcessEvents", (Bool_t (ROOT::R::TRSystem::*)())&ROOT::R::TRSystem::ProcessEvents)
   .method("ProcessEventsLoop", &ROOT::R::TRSystem::ProcessEventsLoop)
   ;
}