//Example based  in
//http://cran.r-project.org/web/packages/DEoptim/DEoptim.pdf
//Author: Omar Zapata

#include<TRInterface.h>
#include<TBenchmark.h>
#include<math.h>
#include<stdlib.h>
//in the next function the pointer *double should be change by TVectorD, because the pointer has no
//sense into R enviroment. It is a Generalization or RosenBrock
Double_t GenRosenBrock(const TVectorD xx )
{
  int length=xx.GetNoElements();
  
  Double_t result=0;
  for(int i=0;i<(length-1);i++)
  {
    result+=pow(1-xx[i],2)+100*pow(xx[i+1]-pow(xx[i],2),2);
  }
  return result;
}

void GlobalMinimization()
{
#if defined(__CINT__) && !defined(__MAKECINT__) 
  cout << "WARNING: This tutorial can run only using ACliC, you must run it by doing: " << endl;
  cout << "cd  $ROOTSYS/tutorials/r/" << endl; 
  cout << "\t .x GlobalMinimization.C+" << endl; 
  return;
#endif
 TBenchmark bench;
 ROOT::R::TRInterface r=gR->Instance();
 //loading DEoptim
 r.Parse("require(DEoptim)");
 
//  passsing RosenBrock funtion to R
 r["GenRosenBrock"]=ROOT::R::TRFunction(GenRosenBrock);
 
//maximun of iterations 
 r["MaxIter"]=5000;
//n = of argument(vector) for GenRosenBrock
 r["n"]=6;
 //lower limits
 r.Parse("ll<-rep(-25, n)");
 //upper limits
 r.Parse("ul<-rep(25, n)");
 
 bench.Start("GlobalMinimization");
 //calling minimization in sequential with one core and timing it.
 r.Parse("result<-DEoptim(fn=GenRosenBrock,lower=ll,upper=ul,control=list(NP=10*n,itermax=MaxIter))");
 r.Parse("result");
 
 std::cout<<"-----------------------------------------"<<std::endl;
 std::cout<<"Bechmark Times"<<std::endl;
//  printing times
 bench.Show("GlobalMinimization");
}
