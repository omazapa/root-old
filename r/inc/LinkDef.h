// @(#)root/mpi:$Id: LinkDef.h  -- :: $
// Author: Omar Zapata   29/05/2013

/*************************************************************************
 * Copyright (C) 2013 , Omar Andres Zapata Mesa           .              *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifdef __CINT__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

//classes
#pragma link C++ class ROOT::R::TRFunction+;
#pragma link C++ class ROOT::R::TRFunction::TRFunction(Double_t (*fun)(Double_t));

#pragma link C++ class ROOT::R::TRInterface+;
#pragma link C++ function ROOT::R::TRInterface::Assign<Int_t>(const Int_t&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<Double_t>(const Double_t&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<Float_t>(const Float_t&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<TString>(const TString&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<TVectorD>(const TVectorD&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<TMatrixD>(const TMatrixD&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<std::vector<Double_t> >(const std::vector<Double_t>&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<std::vector<Float_t> >(const std::vector<Float_t>&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<std::vector<Int_t> >(const std::vector<Int_t>&,const TString&);

#if __cplusplus > 199711L
#pragma link C++ function ROOT::R::TRInterface::Assign<std::array<Double_t> >(const std::array<Double_t>&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<std::array<Float_t> >(const std::array<Float_t>&,const TString&);
#pragma link C++ function ROOT::R::TRInterface::Assign<std::array<Int_t> >(const std::array<Int_t>&,const TString&);
#endif

#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(Int_t&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(Double_t&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(Float_t&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(TString&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(TVectorD&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(TMatrixD&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(std::vector<Double_t>&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(std::vector<Float_t>&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(std::vector<Int_t>&);

#if __cplusplus > 199711L
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(std::array<Double_t>&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(std::array<Float_t>&);
#pragma link C++ function ROOT::R::TRInterface::Binding::operator=(std::array<Int_t>&);
#endif

#pragma link C++ class ROOT::R::TRObjectProxy+;

// #pragma link C++ global gR;

#endif
