//script to test Modules
#include<TRInterface.h>
#include<TRMethodCall.h>
#include<TRObject.h>
#include<TMath.h>
#include<TF1.h>
#include<TROOT.h>

//namespace Rcpp {
//   template<> SEXP wrap(const TF1 &obj)
//   {
////      return Rcpp::wrap(ROOT::R::TRObject((TObject)obj));
//       return ROOT::R::TRObject((TObject)obj);
//   }
////   template<> TF1 as(SEXP obj)
////   {
////      return (TF1)ROOT::R::TRObject(obj);
////   }
//}

void MethodCall()
{
   ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
   ROOT::R::TRMethodCall::Load();
   ROOT::R::TRObject::Load();
   
   
   r.SetVerbose(true);
   r["f"]<<(ROOT::R::TRObject)*f;
   r<<"print(f$ClassName())";
   r["f"]>>o;
   
   gROOT->ProcessLine("TF1 *f=new TF1(\"f\",\"sin(x)\")");
   r["f"]<<(ROOT::R::TRObject)*gROOT->FindObject("f");
   r<<"print(f$ClassName())";

   r<<"TRMethodCall <- TRMethodCall$TRMethodCall";
   
   r<<"u <- new(TRMethodCall,'TF1','Draw','')";
   r<<"u$Execute(f)";
   r<<"u$ExecuteStr('f')";
}
