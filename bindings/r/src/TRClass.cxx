/*************************************************************************
 * Copyright (C) 2013-2014, Omar Andres Zapata Mesa                      *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#include<TRClass.h>
//______________________________________________________________________________
/* Begin_Html

}
*/

using namespace ROOT::R;

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

ROOTR_EXPOSED_CLASS_INTERNAL(TRClass)


ROOTR_MODULE(ROOTR_TRClass)
{
    Rcpp::enum_<TRClass::EState, TRClass>("EState")
    .value("kNoInfo", TRClass::kNoInfo)
    .value("kForwardDeclared", TRClass::kForwardDeclared)
    .value("kEmulated", TRClass::kEmulated)
    .value("kInterpreted", TRClass::kInterpreted)
    .value("kHasTClassInit", TRClass::kHasTClassInit)
    .value("kLoaded", TRClass::kLoaded)
    .value("kNamespaceForMeta", TRClass::kNamespaceForMeta);

    ROOT::R::class_<ROOT::R::TRClass>("TRClass", "The ROOT global object gROOT contains a list of all defined \
                                      classes. This list is build when a reference to a class dictionary \
                                      is made. When this happens, the static \"class\"::Dictionary() \
                                      function is called to create a TClass object describing the class.")
    .constructor<TString, Bool_t>()
    .constructor<TString,Version_t,Bool_t>()
    .constructor<TString,Version_t,TRClass::EState,Bool_t>();

}
