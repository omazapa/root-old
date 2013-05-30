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
#include<Rtypes.h>
#include<TObject.h>
#include<string>
#include<TArrayD.h>
#include<TVectorD.h>
#include<TMatrixD.h>
#include<TRObjectProxy.h>
#ifndef __CINT__
#include <RInside.h>
#include <Rcpp.h>
#include<string>
#else
class RInside;
namespace Rcpp
{
 class InternalFunction;
 class Environment;
 class Environment::Binding;
}
#endif
#include<TObject.h>
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
      
      template<typename T >void assign(const T &obj,const TString & name);      
      
      //utility methods for plots
      inline void x11(){ parseEvalQ("x11()");}
      void plot(TString code);
      void lines(TString code);
      void text(TString code);
      
      //NOTE:this method should be improved to support TObjects
      //May  a new class TREnvironment/TRBinding should be created.
      Rcpp::Environment::Binding operator[]( const TString& name );
      ClassDef(TRInterface, 0) // 
    };
    template<> void TRInterface::assign(const Double_t &value,const TString & name);
    template<> void TRInterface::assign(const Int_t &value,const TString & name);
    //Objects Assignation
    template<> void TRInterface::assign(const TArrayD &obj,const TString & name);
    template<> void TRInterface::assign(const TVectorD &obj,const TString & name);
    template<> void TRInterface::assign(const TMatrixD &obj,const TString & name);
    template<> void TRInterface::assign(const TString &obj,const TString & name);


  }
}
#endif