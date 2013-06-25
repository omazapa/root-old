//Example based  in
//http://root.cern.ch/root/html/tutorials/fit/NumericalMinimization.C.html
//http://stat.ethz.ch/R-manual/R-devel/library/stats/html/optim.html
//Author: Omar Zapata

#include<TRInterface.h>

//in the next function the pointer *double should be change by TVectorD, because the pointer has no
//sense into R enviroment.
Double_t RosenBrock(const TVectorD xx )
{
  const Double_t x = xx[0];
  const Double_t y = xx[1];
  const Double_t tmp1 = y-x*x;
  const Double_t tmp2 = 1-x;
  return 100*tmp1*tmp1+tmp2*tmp2;
}

TVectorD RosenBrockGrad(const TVectorD xx )
{
  const Double_t x = xx[0];
  const Double_t y = xx[1];
  TVectorD grad(2);
  grad[0]=-400 * x * (y - x * x) - 2 * (1 - x);
  grad[1]=200 * (y - x * x);
  return grad;
}


void NumericalMinimization()
{
#if defined(__CINT__) && !defined(__MAKECINT__) 
  cout << "WARNING: This tutorial can run only using ACliC, you must run it by doing: " << endl;
  cout << "\t .x $ROOTSYS/tutorials/r/NumericalMinimization.C+" << endl; 
  return;
#endif
 gR->SetVerbose(kFALSE);//Set this KTRUE to show R messages
 
 //passsing RosenBrock funtion to R
 gR->assign(ROOT::R::TRFunction(RosenBrock),"RosenBrock");
 
 //passsing RosenBrockGrad funtion to R
 gR->assign(ROOT::R::TRFunction(RosenBrockGrad),"RosenBrockGrad");
 
 //the option "method" could be "Nelder-Mead", "BFGS", "CG", "L-BFGS-B", "SANN","Brent"
 //the option "control" let you put some constraints like 
 //"maxit" The maximum number of iterations
 //"abstol" The absolute convergence tolerance.
 //"reltol" Relative convergence tolerance.
 gR->parse("result <- optim( c(0.01,0.01), RosenBrock,method='BFGS',control = list(maxit = 1000000) )");
 
 //Getting result from R
 TVectorD  min=gR->parseEval("result$par").toVector<Double_t>();
 
 //printing results
 std::cout<<"-----------------------------------------"<<std::endl;
 std::cout<<"Minimum x="<<min[0]<<" y="<<min[1]<<std::endl;
 std::cout<<"Value at minimum ="<<RosenBrock(min)<<std::endl;
 
 //using the hessian
 gR->parse("optimHess(result$par, RosenBrock, RosenBrockGrad)");
 gR->parse("hresult <- optim(c(-1.2,1), RosenBrock, NULL, method = 'BFGS', hessian = TRUE)");
 //getting the min calculated with the hessian
 TVectorD  hmin=gR->parseEval("hresult$par").toVector<Double_t>();

 //printing results
 std::cout<<"-----------------------------------------"<<std::endl;
 std::cout<<"Minization with the Hessian"<<endl;
 std::cout<<"Minimum x="<<hmin[0]<<" y="<<hmin[1]<<std::endl;
 std::cout<<"Value at minimum ="<<RosenBrock(hmin)<<std::endl;
 
}