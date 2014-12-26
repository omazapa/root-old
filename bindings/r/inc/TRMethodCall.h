// @(#)root/r:$Id$
// Author: Omar Zapata   25/12/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRMethodCall
#define ROOT_R_TRMethodCall

#ifndef ROOT_TMethodCall
#include<TMethodCall.h>
#endif

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_R_TRClass
#include<TRClass.h>
#endif

#ifndef ROOT_R_TRObjectProxy
#include<TRObjectProxy.h>
#endif
//________________________________________________________________________________________________________
/**
   This is TMethodCall's wrapper class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {
      class TRMethodCall: public TMethodCall {
      public:
        enum EReturnType { kLong, kDouble, kString, kOther, kNone };
      public:
         TRMethodCall(TString cl, TString method, TString params);         
         TRMethodCall(const TMethodCall &m): TMethodCall(m) {}
         
         SEXP Execute(TString obj_name);
         TRMethodCall::EReturnType	ReturnType();
         static void Load();
      };
   }
}

#endif
