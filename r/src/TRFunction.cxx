/*************************************************************************
* Copyright (C) 2013,  Gfif Developers                                   *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
*                                                                        *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
*************************************************************************/
#include<TRFunction.h>
//______________________________________________________________________________
/* Begin_Html
<center><h2>TRFunction class</h2></center>

<p>
The TRFunction's class lets you to pass ROOT functions to R environment<br>
</p>
<p>
The next example was based  in <br>
<a href="http://root.cern.ch/root/html/tutorials/fit/NumericalMinimization.C.html">
http://root.cern.ch/root/html/tutorials/fit/NumericalMinimization.C.html
</a><br>
<a href="http://stat.ethz.ch/R-manual/R-devel/library/stats/html/optim.html">
http://stat.ethz.ch/R-manual/R-devel/library/stats/html/optim.html</a><br>

</p>
End_Html
Begin_Latex

Let f(x,y)=(x-1)^{2} + 100(y-x^{2})^{2}, which is called the Rosenbrock
function.

This function is 0 when y = x^{2} , and x = 1, so (1, 1) is a minimum.
Let's get the minimum using optim package from R through ROOT R interface.
In the code this function was called "Double_t RosenBrock(const TVectorD xx )", because for
optim the input in your function deﬁnition must be a single vector.


The Gradient is formed by
#frac{#partial f}{#partial x} =  -400x(y - x^{2}) - 2(1 - x)

#frac{#partial f}{#partial y} =  200(y - x^{2});

In the code "TVectorD RosenBrockGrad(const TVectorD xx )", because
in the same way that RosenBrock's definition the input in your function must be a single vector
and the return too.(see code below)


End_Latex
Begin_Html
<p>
<i style="color:red;">NOTE</i>  The macro requires compilation with ACLiC, to compile it you should to use <br>
a rootlogon.C macro that have the directives for compilation,<br>
you can find it in $ROOTSYS/tutorials/r/ <br>
</p>
<hr>
End_Html

#include<TRInterface.h>

///in the next function the pointer *double should be change by TVectorD, because the pointer has no
///sense into R environment.
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


void Minimization()
{
#if defined(__CINT__) && !defined(__MAKECINT__)
  cout << "WARNING: This tutorial can run only using ACliC, you must run it by doing: " << endl;
  cout << "cd  $ROOTSYS/tutorials/r/" << endl;
  cout << "\t .x Minimization.C+" << endl;
  return;
#endif
 ROOT::R::TRInterface r=gR->Instance();

 //passing RosenBrock function to R
 r["RosenBrock"]=ROOT::R::TRFunction(RosenBrock);

 //passing RosenBrockGrad function to R
 r["RosenBrockGrad"]=ROOT::R::TRFunction(RosenBrockGrad);

 //the option "method" could be "Nelder-Mead", "BFGS", "CG", "L-BFGS-B", "SANN","Brent"
 //the option "control" let you put some constraints like
 //"maxit" The maximum number of iterations
 //"abstol" The absolute convergence tolerance.
 //"reltol" Relative convergence tolerance.
 r.Parse("result <- optim( c(0.01,0.01), RosenBrock,method='BFGS',control = list(maxit = 1000000) )");

 //Getting result from R
 TVectorD  min=r.ParseEval("result$par").ToVector<Double_t>();

 std::cout.precision(8);
 //printing results
 std::cout<<"-----------------------------------------"<<std::endl;
 std::cout<<"Minimum x="<<min[0]<<" y="<<min[1]<<std::endl;
 std::cout<<"Value at minimum ="<<RosenBrock(min)<<std::endl;

 //using the gradient
 r.Parse("optimHess(result$par, RosenBrock, RosenBrockGrad)");
 r.Parse("hresult <- optim(c(-1.2,1), RosenBrock, NULL, method = 'BFGS', hessian = TRUE)");
 //getting the minimum calculated with the gradient
 TVectorD  hmin=r.ParseEval("hresult$par").ToVector<Double_t>();

 //printing results
 std::cout<<"-----------------------------------------"<<std::endl;
 std::cout<<"Minimization with the Gradient"<<endl;
 std::cout<<"Minimum x="<<hmin[0]<<" y="<<hmin[1]<<std::endl;
 std::cout<<"Value at minimum ="<<RosenBrock(hmin)<<std::endl;

}
*/


using namespace ROOT::R;
ClassImp(TRFunction)

//______________________________________________________________________________
TRFunction::TRFunction(const TRFunction &fun): TObject(fun)
{
   f = fun.f;
}