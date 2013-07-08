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
#include<TRObjectProxy.h>
#include<vector>
//______________________________________________________________________________
/* Begin_Html
<center><h2>TRObjectProxy class</h2></center>

<p>
The TRObjectProxy's class lets you to get ROOT's objects from R's objects.<br>
It have some basic template methods to convert R's objects into ROOT datatypes<br>
<UL>
<LI>ToScalar(): That let you get Double_t and Int_t
<LI>ToArray():  To get TArray class objects
<LI>ToVector(): To get TVectorT class objects
<LI>ToMatrix(): To get TMatrixT class objects
</UL>
</p>
A simple example<br>
<p>

</p>
<hr>
End_Html
#include<TRInterface.h>
void Proxy()
{
ROOT::R::TRObjectProxy obj;
obj=gR->ParseEval("seq(1,10)");
#if defined(__ACLIC__)
//for ACLiC support you should to set the template type
TVectorD v=obj.ToVector<Double_t>();
#else
TVectorD v=obj.ToVector();
#endif
v.Print();
}
*/

using namespace ROOT::R;
ClassImp(TRObjectProxy)

//______________________________________________________________________________
TRObjectProxy::TRObjectProxy(SEXP xx): x(xx) { }

//______________________________________________________________________________
TString TRObjectProxy::ToString()
{
   return TString(::Rcpp::as<std::string>(x));
}

//______________________________________________________________________________
void TRObjectProxy::operator=(SEXP xx)
{
   x = xx;
}

