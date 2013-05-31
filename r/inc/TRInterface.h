// @(#)root/r:$Id$
// Author: Omar Zapata   29/05/2013

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
#ifndef __TRInterface_H__
#define __TRInterface_H__
//ROOT headers
#include<TRObjectProxy.h>
//std headers
#include<string>
//R headers
#ifndef __CINT__
#include <RInside.h>
#include <Rcpp.h>
#else
class RInside;
namespace Rcpp
{
 class InternalFunction;
 class Environment;
 class Environment::Binding;
}
#endif

namespace ROOT
{
  namespace R{
    class TRInterface:public RInside,public TObject
    {
    public:
      TRInterface(const int argc, const char *const argv[], const bool loadRcpp=false, const bool verbose=true, const bool interactive=false);
      ~TRInterface(){}
      
      Int_t parseEval(const TString &code, TRObjectProxy  &ans); // parse line, return in ans; error code rc
      //throws on error if exception is kTRUE
      void  parse(const TString &code,Bool_t exception=kTRUE);
      
      TRObjectProxy parseEval(const TString &code,Bool_t exception=kTRUE);
      
      template<typename T >void assign(const T &var,const TString & name);      
      
      //utility methods for plots
      inline void x11(){ parseEvalQ("x11()");}
      void plot(TString code);
      void lines(TString code);
      void text(TString code);
      
      //NOTE:this method should be improved to support TObjects
      //May  a new class TREnvironment/TRBinding should be created.
      Rcpp::Environment::Binding operator[]( const TString& name );
      ClassDef(TRInterface, 1) // 
    };
    template<> void TRInterface::assign<Double_t>(const Double_t &value,const TString & name);
    template<> void TRInterface::assign<Int_t>(const Int_t &value,const TString & name);
    //Objects Assignation
    template<> void TRInterface::assign<TArrayD>(const TArrayD &obj,const TString & name);
    template<> void TRInterface::assign<TVectorD>(const TVectorD &obj,const TString & name);
    template<> void TRInterface::assign<TMatrixD>(const TMatrixD &obj,const TString & name);
    template<> void TRInterface::assign<TString>(const TString &obj,const TString & name);

#ifndef __CINT__
template<typename T >void TRInterface::assign(const T &var,const TString & name)
{
  RInside::assign(var,name.Data());
}

#endif    

  }
}
#endif