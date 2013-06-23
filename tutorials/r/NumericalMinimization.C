//Example taken from 
//http://root.cern.ch/root/html/tutorials/fit/NumericalMinimization.C.html

#include<TRInterface.h>

//in the next function *double should be change by TVectorD, beacuse the pointer has no
//sense into R enviroment.
Double_t RosenBrock(const TVectorD xx )
{
  const Double_t x = xx[0];
  const Double_t y = xx[1];
  const Double_t tmp1 = y-x*x;
  const Double_t tmp2 = 1-x;
  return 100*tmp1*tmp1+tmp2*tmp2;
}

void NumericalMinimization()
{
#if defined(__CINT__) && !defined(__MAKECINT__) 
  cout << "WARNING: This tutorial can run only using ACliC, you must run it by doing: " << endl;
  cout << "\t .x $ROOTSYS/tutorials/r/NumericalMinimization.C+" << endl; 
  return;
#endif
 gR->SetVerbose(kFALSE);//Set this KTRUE to show R messages
 gR->assign(ROOT::R::TRFunction(RosenBrock),"RosenBrock");
 //the option mothod could be "Nelder-Mead", "BFGS", "CG", "L-BFGS-B", "SANN","Brent"
 gR->parse("result <- optim( c(0,0), RosenBrock,method='BFGS' )");
 TVectorD  min=gR->parseEval("result$par").toVector<Double_t>();
 
 std::cout<<"Minimum x="<<min[0]<<" y="<<min[1]<<std::endl;
 std::cout<<"Value at minimum ="<<RosenBrock(min)<<std::endl;
}