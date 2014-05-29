//script to test Modules
#include<TRInterface.h>
#include<TMath.h>
#include<TRGraph.h>

Double_t myFunc(Double_t x) {
      return cos(x);
   }

void ROOTR()
{
   ROOT::R::TRInterface *gR=ROOT::R::TRInterface::InstancePtr();
   gR->SetVerbose(kFALSE);
   gR->LoadModule();
   gR->Parse("TRGraph <- ROOTR$TRGraph") ;
   gR->Parse("x<-seq(0,2*pi,by=.1)");
   gR->Parse("c1<-ROOTR$TRCanvas('c1','dlnorm')");
   gR->Parse("u <-TRGraph(length(x),x,dlnorm(x))") ;//TGraph(int,double*,double*)
   gR->Parse("u$Draw('')");
   
   gR->Parse("c2<-ROOTR$TRCanvas('c2')");
   gR->Parse("o<- ROOTR$TRF1('dilog','TMath::DiLog(x)')");
   gR->Parse("o$Draw('')");
   
   gR->Parse("c3<-ROOTR$TRCanvas('c3')");
   gR->Parse("i <- ROOTR$TRF1('f2','myFunc(x)')");
   gR->Parse("print(i$Eval(0))");
   gR->Parse("print(i$Eval(c(0,1)))");
   gR->Parse("i$Draw()");
}
