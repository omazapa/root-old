//script to test Modules
#include<TRInterface.h>
#include<TRMethodCall.h>
#include<TMath.h>
#include<TF1.h>
#include<TROOT.h>
void MethodCall()
{
   ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
   ROOT::R::TRMethodCall::Load();

   TF1 *f=new TF1("f","sin(x)");
   r.SetVerbose(true);
//   gROOT->ProcessLine("TF1 *f=new TF1(\"f\",\"sin(x)\")");
   r<<"TRMethodCall <- TRMethodCall$TRMethodCall";
   
   r<<"u <- new(TRMethodCall,'TF1','Draw','')";
   r<<"u$Execute('f')";
}
