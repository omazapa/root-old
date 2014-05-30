#include<TRRint.h>
#include<cstring>

using namespace ROOT::R;
ClassImp(TRRint)
//______________________________________________________________________________
TRRint::TRRint():TObject()
{
 useIntenalApp=kFALSE;
 if(!gApplication) r=new TRint("ROOTR",0,0,0,0,kTRUE);
 else useIntenalApp=kTRUE;//use internal app
}

//______________________________________________________________________________
TRRint::TRRint(const TRRint &ri)
{
  r=ri.r;
}

//______________________________________________________________________________
TRRint::TRRint(std::string name,std::vector<std::string> args)
{
//   Int_t argc=args.size();
//   Char_t **cargs;
//   *cargs=new Char_t[argc];
//   for(Int_t i=0;i<argc;i++)
//   {
//     cargs[i]=new Char_t[args[i].size()];
//     strcmp(cargs[i],args[i].c_str());
//   }
  
//   r=new TRint(name.c_str(),&argc,cargs,0,0,kTRUE);
  if(!gApplication)  r=new TRint(name.c_str(),0,0,0,0,kTRUE);
  else useIntenalApp=kTRUE;
}

//______________________________________________________________________________
Long_t TRRint::ProcessLine(std::string line )
{
  if(useIntenalApp) return gApplication->ProcessLine(line.c_str());
  else return r->ProcessLine(line.c_str());
}



ROOTR_MODULE(ROOTR_TRRint) {
    
    Rcpp::class_<ROOT::R::TRRint>( "TRRint" )
    .constructor<std::string,std::vector<std::string> >()
    .method( "ProcessLine",&ROOT::R::TRRint::ProcessLine)
    ;
}