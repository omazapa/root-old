/*************************************************************************
 * Copyright (C) 2013-2014, Omar Andres Zapata Mesa                      *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#include<TRObjectProxy.h>
#include<vector>
//______________________________________________________________________________
/* Begin_Html
<center><h2>TRObjectProxy class</h2></center>

<p>
The TRObjectProxy class lets you obtain ROOT's objects from R's objects.<br>
It has some basic template methods to convert R's objects into ROOT's datatypes<br>
<UL>
<LI>ToScalar(): Returns Double_t and Int_t
<LI>ToArray():  Returns TArray class objects
<LI>ToVector(): Returns TVectorT class objects
<LI>ToMatrix(): Returns TMatrixT class objects
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
//for ACLiC support you should set the template type
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
TRObjectProxy::TRObjectProxy(SEXP xx): TObject(), x(xx) { }


//______________________________________________________________________________
void TRObjectProxy::operator=(SEXP xx)
{
   x = xx;
}

