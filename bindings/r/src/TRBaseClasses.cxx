/*************************************************************************
 * Copyright (C) 2015, Omar Andres Zapata Mesa                      *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#include<TRBaseClasses.h>
//______________________________________________________________________________
/* Begin_Html
*/


using namespace ROOT::R;

//ClassImp(TRObject)

ROOTR_MODULE(ROOTR_TRObject)
{

   ROOT::R::class_<ROOT::R::TRObject>("TRObject", "Mother of all ROOT objects.")
   .constructor()
   .method("ClassName",&ROOT::R::TRObject::ClassName)
   .method("GetName",&ROOT::R::TRObject::GetName);
}

ROOTR_MODULE(ROOTR_TRMethod)
{

   ROOT::R::class_<ROOT::R::TRMethod>("TRMethod", "Dictionary of a member function (method).")
   .method("ClassName",&ROOT::R::TRMethod::ClassName)
   .method("GetName",&ROOT::R::TRMethod::GetName);
}


//______________________________________________________________________________
TRClass::TRClass(TString name, Bool_t silent):TClass(name.Data(),silent) {}

//______________________________________________________________________________
TRClass::TRClass(TString name, Version_t cversion, Bool_t silent):TClass(name.Data(),cversion,silent) {}

//______________________________________________________________________________
TRClass::TRClass(TString name, Version_t cversion, TRClass::EState theState, Bool_t silent):TClass(name.Data(),cversion,(TClass::EState)theState,silent) {}


namespace Rcpp {
template<> SEXP wrap(const TRClass::EState &s)
{
    return Rcpp::wrap((int)s);
}
template<> TRClass::EState as(SEXP c)
{
    return Rcpp::as<ROOT::R::TRClass::EState>(c);
}

}


ROOTR_MODULE(ROOTR_TRList)
{

    ROOT::R::class_<ROOT::R::TRList>("TRList", "A doubly linked list. All classes inheriting from TObject can be inserted in a TList.")
    .constructor()
    .constructor<ROOT::R::TRObjectPtr>()
    .method("At",&ROOT::R::TRList::At)
    .method("GetSize",&ROOT::R::TRList::GetSize);

}



ROOTR_MODULE(ROOTR_TRClass)
{

    ROOT::R::class_<ROOT::R::TRClass>("TRClass", "The ROOT global object gROOT contains a list of all defined \
                                      classes. This list is build when a reference to a class dictionary \
                                      is made. When this happens, the static \"class\"::Dictionary() \
                                      function is called to create a TClass object describing the class.")
    .constructor<TString, Bool_t>()
    .constructor<TString,Version_t,Bool_t>()
    .constructor<TString,Version_t,TRClass::EState,Bool_t>()
    .method("GetListOfAllPublicMethods",&ROOT::R::TRClass::GetListOfAllPublicMethods);

    Rcpp::enum_<TRClass::EState, TRClass>("EState")
    .value("kNoInfo", TRClass::kNoInfo)
    .value("kForwardDeclared", TRClass::kForwardDeclared)
    .value("kEmulated", TRClass::kEmulated)
    .value("kInterpreted", TRClass::kInterpreted)
    .value("kHasTClassInit", TRClass::kHasTClassInit)
    .value("kLoaded", TRClass::kLoaded)
    .value("kNamespaceForMeta", TRClass::kNamespaceForMeta);

}

