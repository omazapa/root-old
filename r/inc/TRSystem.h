// @(#)root/r:$Id$
// Author: Omar Zapata   11/06/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRSYSTEM
#define ROOT_R_TRSYSTEM

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_TSystem
#include<TSystem.h>
#endif

#ifndef ROOT_TThread
#include<TThread.h>
#endif


//________________________________________________________________________________________________________
/**
   This is TSystem class for R


   @ingroup R
*/
namespace ROOT {
   namespace R {

      class TRSystem: public TSystem {
      private:
         TThread *th;
      public:
         TRSystem();
         ~TRSystem() {
            if (th) delete th;
         }
         void ProcessEventsLoop();

         ClassDef(TRSystem, 0)
      };
   }
}

ROOTR_EXPOSED_CLASS_INTERNAL(TRSystem)

#endif
