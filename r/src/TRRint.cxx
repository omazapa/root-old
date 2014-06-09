#include<TRRint.h>
#include<cstring>

using namespace ROOT::R;
ClassImp(TRRint)
//______________________________________________________________________________
TRRint::TRRint(): TObject()
{
   if (!gApplication) gApplication = new TRint("ROOTR", 0, 0, 0, 0, kTRUE);
}

//______________________________________________________________________________
TRRint::TRRint(const char* name, std::vector<std::string> args)
{
   Int_t argc = args.size();
   Char_t *cargs[argc];
   for (Int_t i = 0; i < argc; i++) {
      cargs[i] = new Char_t[args[i].size()];
      strcmp(cargs[i], args[i].c_str());
   }

   if (!gApplication)  gApplication = new TRint(name, &argc, cargs, 0, 0, kTRUE);
}

//______________________________________________________________________________
Long_t TRRint::ProcessLine(const char *line)
{
   return gApplication->ProcessLine(line);
}


void TRRint::Run(Bool_t retrn )
{
   return gApplication->Run(retrn);
}

ROOTR_MODULE(ROOTR_TRRint)
{

   Rcpp::class_<ROOT::R::TRRint>("TRRint")
   .constructor<const char*, std::vector<std::string> >()
   .method("ProcessLine", &ROOT::R::TRRint::ProcessLine)
   .method("Run", &ROOT::R::TRRint::Run)
   ;
}