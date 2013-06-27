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
#ifndef ROOT_R_TRInterface
#define ROOT_R_TRInterface

#ifndef ROOT_R_TRObjectProxy
#include<TRObjectProxy.h>
#endif

#ifndef ROOT_R_TFunction
#include<TRFunction.h>
#endif

//utility macro to create easily method from R function in the TRInterface
#define R_FUNCTION(func) inline void func(TString opt){ \
      TString code=#func;\
      code+="("+opt+")";\
      parse(code.Data());}

/**
   @defgroup R R Interface for Statistical Computing
   \ref ROOTR was implemented using the
   <A HREF="http://www.r-project.org/">R Project</A> library and the modules
   <A HREF="http://cran.r-project.org/web/packages/Rcpp/index.html">Rcpp</A> and
   <A HREF="http://cran.r-project.org/web/packages/RInside/index.html">RInside</A>
   @ingroup R
 */

/**
   @defgroup R R Interface for Statistical Computing
   @ingroup R
 */

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TRInterface                                                          //
//                                                                      //
// R Interface class for Statistical Computing.                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

namespace ROOT {
   namespace R {
      class TRInterface: public RInside, public TObject {
      public:
         TRInterface(const int argc = 0, const char *const argv[] = NULL, const bool loadRcpp = false, const bool verbose = true, const bool interactive = false);
         ~TRInterface() {}

         void SetVerbose(Bool_t status);
         Int_t parseEval(const TString &code, TRObjectProxy  &ans); // parse line, return in ans; error code rc
         //throws on error if exception is kTRUE
         void  parse(const TString &code, Bool_t exception = kTRUE);

         TRObjectProxy parseEval(const TString &code, Bool_t exception = kTRUE);

         template<typename T >void assign(const T &var, const TString & name);
         void assign(const TRFunction &fun, const TString & name);
         //utility methods for plots
	 
         void Xwin(TString opt = "");//calls X11/quartz/windows to init graphical system
         R_FUNCTION(plot)
         R_FUNCTION(points)
         R_FUNCTION(lines)
         R_FUNCTION(text)
         R_FUNCTION(abline)
         R_FUNCTION(segments)
         R_FUNCTION(curve)
	 	 
         //NOTE:this method should be improved to support TObjects
         //A new class TREnvironment/TRBinding should be created.
         Rcpp::Environment::Binding operator[](const TString& name);
         ClassDef(TRInterface, 1) //
      };

#ifndef __CINT__
      template<typename T >void TRInterface::assign(const T &var, const TString & name)
      {
         // This method lets you pass variables from ROOT to R.
         // The template T should be a supported ROOT datatype and
         // the TString's name is the name of the variable in the R enviroment.
         RInside::assign(var, name.Data());
      }

#endif
   }
}
R__EXTERN ROOT::R::TRInterface *gR;

#endif