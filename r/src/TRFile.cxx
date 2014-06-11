#include<TRFile.h>
#include<TRF1.h>
#include<TRCanvas.h>
#include<TRGraph.h>


using namespace ROOT::R;
ClassImp(TRFile)
//______________________________________________________________________________
TRFile::TRFile(): TFile()
{
}

//______________________________________________________________________________
TRFile::TRFile(const char *fname, Option_t *option , const char *ftitle, Int_t compress): TFile(fname, option, ftitle, compress)
{

}

ROOTR_MODULE(ROOTR_TRFile)
{

   ROOT::R::class_<ROOT::R::TRFile>("TRFile", "TFile class to manipulate ROOT's files.")
   .constructor<const char *, Option_t *, const char *, Int_t>()
   .method("Map", (void (ROOT::R::TRFile::*)())&ROOT::R::TRFile::Map)
   .method("ls", (void (ROOT::R::TRFile::*)(Option_t *))&ROOT::R::TRFile::ls)
   .method("Flush", (void (ROOT::R::TRFile::*)())&ROOT::R::TRFile::Flush)
   .method("Close", (void (ROOT::R::TRFile::*)(Option_t *))&ROOT::R::TRFile::Close)
   .method("Close", (void (ROOT::R::TRFile::*)())&ROOT::R::TRFile::Close)
   .method("Get", &ROOT::R::TRFile::Get<ROOT::R::TRF1>)
   .method("Get", &ROOT::R::TRFile::Get<ROOT::R::TRGraph>)
//    .method("Get", &ROOT::R::TRFile::Get<ROOT::R::TRCanvas>)//TRCanvas no supported at the moment
   ;
}