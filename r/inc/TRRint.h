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
      protected:
         TRint *r;
         Bool_t useIntenalApp;
      public:
         TRRint();
         TRRint(const TRRint &);
         TRRint(std::string name, std::vector<std::string> args);
         ~TRRint() {
            delete r;
         }
         Long_t ProcessLine(std::string line);

         ClassDef(TRRint, 0)
      };
   }
}



#endif
