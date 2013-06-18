// @(#)root/r:$Id$
// Author: Omar Zapata   16/06/2013

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
#ifndef ROOT_R_TRFunction
#define ROOT_R_TRFunction

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

//________________________________________________________________________________________________________
/**
   This is a class to pass functions from ROOT to R


   @ingroup R
*/

namespace ROOT {
   namespace R {
      class TRInterface;
      class TRFunction:public TObject{
	friend class TRInterface;
      private:
	Rcpp::InternalFunction *f;
	static TF1 f1;
	static Double_t ifun1(Double_t x){return f1(x);}
      public:
         typedef Double_t (*GenFuncG)(const Double_t*,const Double_t*);
         typedef Double_t (*GenFunc0)();
         typedef Double_t (*GenFunc10)(Double_t);
         typedef Double_t (*GenFunc110)(Double_t,Double_t);
         typedef Double_t (*GenFunc1110)(Double_t,Double_t, Double_t);

	TRFunction(){f=NULL;}
	TRFunction(TF1 fun);
	template<class T> TRFunction(T fun)
	{
	  f=new Rcpp::InternalFunction(fun);
	}
      };
   }
}
#endif