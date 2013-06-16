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
<LI>toScalar(): That let you get Double_t and Int_t
<LI>toArray():  To get TArray class objects
<LI>toVector(): To get TVectorT class objects
<LI>toMatrix(): To get TMatrixT class objects
</UL>
</p>
A simple example<br>
<p>

</p>
<hr>
End_Html
ROOT::R::TRObjectProxy obj;
obj=gR->parseEval("seq(1,10)");
TVectorD v=obj.toVector();
v.Print();
return v;
*/

// namespace Rcpp {
// namespace traits {
//   template <typename T> SEXP wrap( const TMatrixT<T> &m)
//   {
//      Int_t rows = m.GetNrows();
//      Int_t cols = m.GetNcols();
//      T *data = new T[rows * cols];
//      m.GetMatrix2Array(data, "F"); //ROOT have a bug here(Fixed)
//      NumericMatrix mat(m.GetNrows(),m.getNcols(),data);
//      return mat;
//   }
//
//   template <typename T> SEXP wrap( const TVectorT<T>& v)
//   {
//     Int_t size=v.GetNoElements();
//     T *data=v.GetMatrixArray();
// //     std::vector<T> vec(data, data + sizeof(T)*size );
//     NumericVector vec(size,data);
//     return vec;
//   }
// }
// }

using namespace ROOT::R;
ClassImp(TRObjectProxy)

//______________________________________________________________________________
TRObjectProxy::TRObjectProxy(SEXP xx): x(xx) { }

//______________________________________________________________________________
TString TRObjectProxy::toString()
{
   return TString(::Rcpp::as<std::string>(x));
}

//______________________________________________________________________________
void TRObjectProxy::operator=(SEXP xx)
{
   x = xx;
}
