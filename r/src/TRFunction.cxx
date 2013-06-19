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
<center><h2>InternalFunction class</h2></center>

<p>
The TRFunction's class lets you to pass ROOT functions to R enviroment<br>
</p>
A simple example<br>
<p>

</p>
<hr>
End_Html
 TF1 f2("f1","TMath::DiLog(x)");
 gR->assign(ROOT::R::TRFunction(f2), "f2");
 gR->parse("print(f2(2))");
*/


using namespace ROOT::R;
// ClassImp(TRFunction)
TF1 TRFunction::f1;
//______________________________________________________________________________
TRFunction::TRFunction(const TF1 &fun)
{
   f1 = fun;
   if (fun.GetNpar() == 0) f = new Rcpp::InternalFunction((Double_t (*)(Double_t))this->functor1);
   else f = new Rcpp::InternalFunction((Double_t (*)(TVectorD, TVectorD))this->functor1par);
}

//______________________________________________________________________________
TRFunction::TRFunction(const TRFunction &fun)
{
   f = fun.f;
   f1 = fun.f1;
}

//______________________________________________________________________________
TRFunction::TRFunction(Rcpp::InternalFunction fun): f(&fun) {}
