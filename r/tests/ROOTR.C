//script to test Modules
#include<TRInterface.h>

Double_t myFunc(Double_t x)
{
  return cos(x);
}

void ROOTR()
{
   ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
   r.SetVerbose(kFALSE);
   r<<"x<-seq(0,2*pi,by=.1)";
   r<<"c1<-TCanvas('c1','dlnorm')";
   r<<"u <-TGraph(length(x),x,dlnorm(x))" ;//TGraph(int,double*,double*)
   r<<"u$Draw()";
   
   r<<"c2<-TCanvas('c2','DiLog from TMath')";
   r<<"o<- TF1('dilog','TMath::DiLog(x)')";
   r<<"o$Draw('')";
 
   r<<"c3<-TCanvas('c3','Cust')";
   r<<"i <- TF1('f2','[0]*myFunc([1]*x)')"; 
   r<<"i$SetRange(0,2*pi)";
   r<<"i$SetParameter(0,4)";
   r<<"i$SetParameter(1,pi/2)";
   r<<"print(i$Eval(0))";
   r<<"print(i$Eval(c(0,pi)))";
   r<<"i$Draw()";
   
//    r<<"gApp<-TRint('ROOTR')";
//    r<<"gApp$ProcessLine('cout<<\"Calling cout from TRint\"<<endl;')";
   
}
