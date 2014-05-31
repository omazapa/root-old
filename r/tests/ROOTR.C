//script to test Modules
#include<TRInterface.h>

void ROOTR()
{
   ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
   r.SetVerbose(kFALSE);
//    r.Parse("TRGraph <- ROOTR$TRGraph") ;
//    r.Parse("x<-seq(0,2*pi,by=.1)");
//    r.Parse("c1<-ROOTR$TRCanvas('c1','dlnorm')");
//    r.Parse("u <-TRGraph(length(x),x,dlnorm(x))") ;//TGraph(int,double*,double*)
//    r.Parse("u$Draw('')");
   
//    r.Parse("c2<-ROOTR$TRCanvas('c2')");
//    r.Parse("o<- ROOTR$TRF1('dilog','TMath::DiLog(x)')");
//    r.Parse("o$Draw('')");
//    
//    r.Parse("c3<-ROOTR$TRCanvas('c3')");
//    r.Parse("i <- ROOTR$TRF1('f2','myFunc(x)')");
//    r.Parse("print(i$Eval(0))");
//    r.Parse("print(i$Eval(c(0,1)))");
//    r.Parse("i$Draw()");
   
//    r.Parse("gApp<-ROOTR$TRRint('ROOTR')");
//    r.Parse("gApp$ProcessLine('#include<Math/SpecFuncMathMore.h>')");
   
//    r.Parse("print(i$Eval(0))");
//    r.Parse("print(i$Eval(c(0,1)))");
//    r.Parse("i$Draw()");
}
