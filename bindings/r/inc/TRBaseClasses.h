// @(#)root/r:$Id$
// Author: Omar Zapata   3/01/2015


/*************************************************************************
 * Copyright (C)  2015, Omar Andres Zapata Mesa                          *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_R_BaseClasses
#define ROOT_R_BaseClasses

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

#ifndef ROOT_TList
#include<TList.h>
#endif

#ifndef ROOT_TClass
#include<TClass.h>
#endif

#ifndef ROOT_TMethod
#include<TMethod.h>
#endif

namespace ROOT {
   namespace R {
      class TRObject: public TObject {
      public:
         TRObject():TObject(){};
         TRObject(const TObject &obj):TObject(obj){};
         TRObject(const TRObject &obj):TObject(obj){};
         TString ClassName(){return TObject::ClassName();}
         TString GetName(){return TObject::GetName();}
         
      };
      
      class TRMethod:public TMethod
      {
      public:
          TRMethod(const TMethod &obj):TMethod(obj){}
          TRMethod(const TRMethod &obj):TMethod(obj){}
          TString ClassName(){return TMethod::ClassName();}
          TString GetName(){return TMethod::GetName();}
          
      };
   }
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRObject)
ROOTR_EXPOSED_CLASS_INTERNAL(TRMethod)

namespace ROOT
{
    namespace R
    {
          typedef Rcpp::XPtr<TRObject> TRObjectPtr;
    }
}

namespace ROOT
{
    namespace R
    {
class TRList:public TList
{
public:
    TRList():TList(){}
    TRList(TRObjectPtr obj):TList(obj){}
    TRList(const TList *obj)
    {
        TIter next(obj);
        TObject *tobj;
        while((tobj = next()))
        {
            TList::Add(tobj);
        }
    }
    TRList(const TRList &obj)
    {
        TIter next(&obj);
        TObject *tobj;
        while((tobj = next()))
        {
            TList::Add(tobj);
        }
    }
    
    inline Int_t GetSize(){return TList::GetSize();}
    TRMethod At(Int_t i){return *(TRMethod*)TList::At(i);}
};

typedef Rcpp::XPtr<TRList> TRListPtr;
}
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRList)



namespace ROOT
{
namespace R
{
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
    TRList	GetListOfAllPublicMethods(Bool_t s){return TRList(TClass::GetListOfAllPublicMethods(s)); }
};

}
}
ROOTR_EXPOSED_CLASS_INTERNAL(TRClass)


#endif
