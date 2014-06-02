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
   r<<"TRGraph <- ROOTR$TRGraph";
   r<<"x<-seq(0,2*pi,by=.1)";
   r<<"c1<-ROOTR$TRCanvas('c1','dlnorm')";
   r<<"u <-TRGraph(length(x),x,dlnorm(x))" ;//TGraph(int,double*,double*)
   r<<"u$Draw('')";
   
   r<<"c2<-ROOTR$TRCanvas('c2')";
   r<<"o<- ROOTR$TRF1('dilog','TMath::DiLog(x)')";
   r<<"o$Draw('')";
   
   r<<"c3<-ROOTR$TRCanvas('c3')";
   r<<"i <- ROOTR$TRF1('f2','myFunc(x)')";
   r<<"print(i$Eval(0))";
   r<<"print(i$Eval(c(0,1)))";
   r<<"i$Draw()";
   
   r<<"gApp<-ROOTR$TRRint('ROOTR')";
   r<<"gApp$ProcessLine('cout<<\"Calling cout from TRint\"<<endl;')";
   
}
