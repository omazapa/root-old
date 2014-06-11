#include<TRRint.h>
#include<cstring>

using namespace ROOT::R;
ClassImp(TRRint)
//______________________________________________________________________________
TRRint::TRRint(): TRint("ROOTR",0,0,0,0,kTRUE)
{
}

//______________________________________________________________________________
TRRint::TRRint(const char *name):TRint(name,0,0,0,0,kTRUE)
{
}

//______________________________________________________________________________
Long_t TRRint::ProcessLine(const char *line)
{
   return TApplication::ProcessLine(line);
}


ROOTR_MODULE(ROOTR_TRRint)
{

   Rcpp::class_<ROOT::R::TRRint>("TRRint","TRint class to create a ROOT application.")
   .constructor()
   .constructor<const char *>()
   .method("ProcessLine", (Long_t (ROOT::R::TRRint::*)(const char*))&ROOT::R::TRRint::ProcessLine)
   .method("Run",(void (ROOT::R::TRRint::*)(Bool_t))&ROOT::R::TRRint::Run)
   ;
}