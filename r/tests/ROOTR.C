//script to test Modules
#include<TRInterface.h>
#include<TMath.h>
#include<TRGraph.h>

void ROOTR()
{
   gR->SetVerbose(kFALSE);
   gR->Parse("TRGraph <- ROOTR$TRGraph") ;
   gR->Parse("x<-seq(0,2*pi,by=.1)");
   gR->Parse("u <- new(TRGraph,length(x),x,sin(x))") ;//TGraph(int,double*,double*)
   gR->Parse("u$Draw('')");
}
