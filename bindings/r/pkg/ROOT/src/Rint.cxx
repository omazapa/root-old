#include<Rint.h>

ROOTR_MODULE(Rint)
{

   ROOT::R::class_<ROOT::R::TRRint>("TRint", "TRint class to create a ROOT application.")
   .constructor()
   .constructor<TString>()
   .method("ProcessLine", (Long_t (ROOT::R::TRRint::*)(TString))&ROOT::R::TRRint::ProcessLine)
   .method("Run", (void (ROOT::R::TRRint::*)(Bool_t))&ROOT::R::TRRint::Run)
   .method("Terminate", (void (ROOT::R::TRRint::*)(Int_t))&ROOT::R::TRRint::Terminate)
   .method("WorkingDirectory", (TString (ROOT::R::TRRint::*)())(&ROOT::R::TRRint::WorkingDirectory))
   ;
}