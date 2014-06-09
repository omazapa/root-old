// @(#)root/r:$Id$
// Author: Omar Zapata   30/05/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRRINT
#define ROOT_R_TRRINT

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_TRint
#include<TRint.h>
#endif
//________________________________________________________________________________________________________
/**
   This is TRint class for R


   @ingroup R
*/

namespace ROOT {
   namespace R {

      class TRRint: public TObject {
      public:
         TRRint();
         TRRint(const char* name, std::vector<std::string> args);
         ~TRRint() {
            delete gApplication;
         }
         Long_t ProcessLine(const char* line);
	 void Run(Bool_t retrn = kFALSE);

         ClassDef(TRRint, 0)
      };
   }
}



#endif
