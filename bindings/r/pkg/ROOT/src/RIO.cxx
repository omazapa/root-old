#include<RIO.h>


//______________________________________________________________________________
ROOT::R::TRFile::TRFile(TString fname, TString option , TString ftitle, Int_t compress): TFile(fname.Data(), option.Data(), ftitle.Data(), compress)
{

}

ROOTR_MODULE(RIO)
{

   ROOT::R::class_<ROOT::R::TRFile>("TFile", "TFile class to manipulate ROOT's files.")
   .constructor<TString>()
   .constructor<TString , TString>()
   .constructor<TString , TString, TString>()
   .constructor<TString , TString, TString , Int_t>()
   .method("Map", (void (ROOT::R::TRFile::*)())&ROOT::R::TRFile::Map)
   .method("ls", (void (ROOT::R::TRFile::*)(TString))&ROOT::R::TRFile::ls)
   .method("Flush", (void (ROOT::R::TRFile::*)())&ROOT::R::TRFile::Flush)
   .method("Close", (void (ROOT::R::TRFile::*)(TString))&ROOT::R::TRFile::Close)
   .method("Close", (void (ROOT::R::TRFile::*)())&ROOT::R::TRFile::Close)
   .method("Get", &ROOT::R::TRFile::Get<ROOT::R::TRObjectPtr>);
}
