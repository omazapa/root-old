// @(#)root/r:$Id$
// Author: Omar Zapata   21/12/2014


/*************************************************************************
 * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_TRClass
#define ROOT_R_TRClass

#ifndef ROOT_TClass
#include<TClass.h>
#endif

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

//________________________________________________________________________________________________________
/**
   This is TClass's wrapper class for R


   @ingroup R
*/

namespace ROOT {
namespace R {
class TRClass: public TClass {
public:
    enum EState {
        kNoInfo,          // The state has not yet been initialized, i.e. the TClass
        // was just created and/or there is no trace of it in the interpreter.
        kForwardDeclared, // The interpreted knows the entity is a class but that's it.
        kEmulated,        // The information about the class only comes from a TStreamerInfo
        kInterpreted,     // The class is described completely/only in the interpreter database.
        kHasTClassInit,   // The class has a TClass proper bootstrap coming from a run
        // through rootcling/genreflex/TMetaUtils and the library
        // containing this dictionary has been loaded in memory.
        kLoaded = kHasTClassInit,
        kNamespaceForMeta // Very transient state necessary to bootstrap namespace entries in ROOT Meta w/o interpreter information
    };

public:
    TRClass():TClass() {};
    TRClass(TString name, Bool_t silent = kFALSE);
    TRClass(TString name, Version_t cversion, Bool_t silent = kFALSE);
    TRClass(TString name, Version_t cversion, TRClass::EState theState, Bool_t silent = kFALSE);
};
}
}
#endif
