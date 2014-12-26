/*************************************************************************
 * Copyright (C) 2013-2014, Omar Andres Zapata Mesa                      *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#include<TRMethodCall.h>
#include<TROOT.h>
#include<TRInterface.h>
//______________________________________________________________________________
/* Begin_Html

}
*/

using namespace ROOT::R;

//______________________________________________________________________________
TRMethodCall::TRMethodCall(TString  cl, TString method, TString params):TMethodCall(TClass::GetClass(cl.Data(),true),method.Data(),params.Data()){}

// kLong, kDouble, kString, kOther, kNone
//______________________________________________________________________________
SEXP TRMethodCall::Execute(TString obj_name)
{
    
    
    if(this->ReturnType()==kLong){
        Long_t result;
        TMethodCall::Execute(gROOT->FindObject(obj_name.Data()),result);
        return Rcpp::wrap(result);        
    } 

    if(this->ReturnType()==kDouble){
        Double_t result;
        TMethodCall::Execute(gROOT->FindObject(obj_name.Data()),result);
        return Rcpp::wrap(result);        
    } 
    
    if(this->ReturnType()==kString){
        char *result=new char[4096];
        TMethodCall::Execute(gROOT->FindObject(obj_name.Data()),&result);
        return Rcpp::wrap(TString(result));        
    }
    
    if(this->ReturnType()==kOther){
        TMethodCall::Execute(gROOT->FindObject(obj_name.Data()));
        return Rcpp::wrap(R_NilValue);       
    }
    
    if(this->ReturnType()==kNone){
        TMethodCall::Execute(gROOT->FindObject(obj_name.Data()));
        return Rcpp::wrap(R_NilValue);       
    }
    return Rcpp::wrap(R_NilValue);
 }

//______________________________________________________________________________
TRMethodCall::EReturnType	TRMethodCall::ReturnType()
{
    return (TRMethodCall::EReturnType)TMethodCall::ReturnType();
}


namespace Rcpp {
template<> SEXP wrap(const TRMethodCall::EReturnType  &s)
{
    return Rcpp::wrap((int)s);
}
template<> TRMethodCall::EReturnType as(SEXP c)
{
    return Rcpp::as<ROOT::R::TRMethodCall::EReturnType>(c);
}

}

ROOTR_EXPOSED_CLASS_INTERNAL(TRMethodCall)

ROOTR_MODULE(ROOTR_TRMethodCall)
{

    ROOT::R::class_<ROOT::R::TRMethodCall>("TRMethodCall", "Method or function calling interface.")
    .constructor<TString, TString, TString >()
    .method("Execute",(SEXP (ROOT::R::TRMethodCall::*)(TString))(&ROOT::R::TRMethodCall::Execute))
    .method("ReturnType",&ROOT::R::TRMethodCall::ReturnType);

    Rcpp::enum_<ROOT::R::TRMethodCall::EReturnType, TRMethodCall>("EReturnType")
    .value("kLong", ROOT::R::TRMethodCall::kLong)
    .value("kDouble",   ROOT::R::TRMethodCall::kDouble)
    .value("kString",  ROOT::R::TRMethodCall::kString)
    .value("kOther",  ROOT::R::TRMethodCall::kOther)
    .value("kNone",  ROOT::R::TRMethodCall::kNone);

}

void ROOT::R::TRMethodCall::Load()
{
ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
r["TRMethodCall"]<<LOAD_ROOTR_MODULE(ROOTR_TRMethodCall);
}
