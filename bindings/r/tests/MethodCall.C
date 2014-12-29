//script to test Modules
#include<TRInterface.h>
#include<TRMethodCall.h>
#include<TRObject.h>
#include<TRef.h>
#include<TMath.h>
#include<TF1.h>
#include<TROOT.h>

//ROOTR_EXPOSED_CLASS(TObject)

//RCPP_MODULE(ROOTR_TObject)
//{
//
//   Rcpp::class_<TObject>("TObject", "Mother of all ROOT objects.")
//   .constructor()
//   .method("ClassName",&TObject::ClassName);
//}



//ROOTR_EXPOSED_CLASS(TRRef)
//RCPP_MODULE(ROOTR_TRRef)
//{
//
//   Rcpp::class_<TRRef>("TRef", "Persistent Reference link to a TObject")
//   .constructor<TObject &>()
//   .method("GetObject",&TRRef::GetObject);
//}


void MethodCall()
{
   ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
   ROOT::R::TRMethodCall::Load();
   ROOT::R::TRObject::Load();

   TF1 *f=new TF1("f","sin(x)");
   ROOT::R::TRRef ref(f);
//  r["ROOTR_TObject"]<<LOAD_ROOTR_MODULE(ROOTR_TObject);
//  r["ROOTR_TRRef"]<<LOAD_ROOTR_MODULE(ROOTR_TRRef);

  
   r.SetVerbose(true);
   r<<"TRMethodCall <- TRMethodCall$TRMethodCall";
   r<<"TRRef <- ROOTR_TRRef$TRRef";
   r<<"TObject <- ROOTR_TObject$TObject";

//   r["f"]<<(ROOT::R::TRObject)*f;
//   r<<"print(f$ClassName())";
//   r["f"]>>o;
//   
//   gROOT->ProcessLine("TF1 *f=new TF1(\"f\",\"sin(x)\")");
//   r["f"]<<(ROOT::R::TRObject)*gROOT->FindObject("f");
//   r<<"print(f$ClassName())";

//   r<<"g <- new(TObject)";
   r["ref"]<<ref;
   r<<"f <- ref$GetObject()";
   r<<"u <- new(TRMethodCall,'TF1','Draw','')";
//   r<<"u$Execute(f)";
   r<<"u$Execute(ref)";
//   r<<"u$ExecuteStr('f')";
}
