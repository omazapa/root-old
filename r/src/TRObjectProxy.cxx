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
  x=xx;
}

