//Example based  in
//http://cran.r-project.org/web/packages/DEoptim/DEoptim.pdf
//Please install the R package DEoptim before run this example.
//Author: Omar Zapata

#include<TRInterface.h>
#include<TBenchmark.h>
#include<math.h>
#include<stdlib.h>
//In the next function the *double pointer should be changed by a TVectorD datatype,
//because the pointer has no meaning in the R enviroment.
//This is a generalization of the RosenBrock function, with the min xi=1 and i>0.
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

//the min xi=0 i>0
Double_t Rastrigin(const TVectorD xx)
{
  int length=xx.GetNoElements();
  Double_t result=10*length;
  for(int i=0;i<length;i++)
  {
    result+=xx[i]*xx[i]-10*cos(6.2831853*xx[i]);
  }
  return result;
}

void GlobalMinimization()
{
 TBenchmark bench;
 ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
 //loading DEoptim
 r.Parse("suppressMessages(library(DEoptim, quietly = TRUE))");
//  r.Parse("require(DEoptim)"); //this prints information about authors
 
//  passing RosenBrock function to R
 r["GenRosenBrock"]=ROOT::R::TRFunction(GenRosenBrock);

 //maximun number of iterations 
 r["MaxIter"]=5000;
 //n = size of vector that is an argument for GenRosenBrock
 r["n"]=3;
 //lower limits
 r.Parse("ll<-rep(-25, n)");
 //upper limits
 r.Parse("ul<-rep(25, n)");
 
 bench.Start("GlobalMinimizationRosenBrock");
 //calling minimization and timing it.
 r.Parse("result1<-DEoptim(fn=GenRosenBrock,lower=ll,upper=ul,control=list(NP=10*n,itermax=MaxIter,trace=FALSE))");
 std::cout<<"-----------------------------------------"<<std::endl;
 std::cout<<"RosenBrock's minimum in: "<<std::endl;
 r.Parse("print(result1$optim$bestmem)");
 std::cout<<"Bechmark Times"<<std::endl;
//  printing times
 bench.Show("GlobalMinimizationRosenBrock");

 
 //passing RosenBrock function to R
 r["Rastrigin"]=ROOT::R::TRFunction(Rastrigin);
 //maximun number of iterations 
 r["MaxIter"]=2000;
 //n = size of a vector which is an argument for Rastrigin
 r["n"]=3;
 //lower limits
 r.Parse("ll<-rep(-5, n)");
 //upper limits
 r.Parse("ul<-rep(5, n)");
 
 bench.Start("GlobalMinimizationRastrigin");
 //calling minimization and timing it.
 r.Parse("result2<-DEoptim(fn=Rastrigin,lower=ll,upper=ul,control=list(NP=10*n,itermax=MaxIter,trace=FALSE))");
 std::cout<<"-----------------------------------------"<<std::endl;
 std::cout<<"Rastrigin's minimum in: "<<std::endl;
 r.Parse("print(result2$optim$bestmem)");
 std::cout<<"Bechmark Times"<<std::endl;
 //printing times
 bench.Show("GlobalMinimizationRastrigin");
 r.Parse("x11(title='RosenBrock Convergence')");
 r.Parse("plot(result1,type='o',pch='.')");
 r.Parse("x11(title='Rastrigin Convergence')");
 r.Parse("plot(result2,type='o',pch='.')");
//  r.Parse("print(result1)");
}
