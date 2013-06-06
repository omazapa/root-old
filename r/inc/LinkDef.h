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
#pragma link C++ class ROOT::R::TRInterface+;
#pragma link C++ class ROOT::R::TRObjectProxy+;

#pragma link C++ function  ROOT::R::TRObjectProxy::toScalar<Double_t>();
#pragma link C++ function  ROOT::R::TRObjectProxy::toScalar<Float_t>();
#pragma link C++ function  ROOT::R::TRObjectProxy::toScalar<Int_t>();

#pragma link C++ function  ROOT::R::TRObjectProxy::toVector<Double_t>();
#pragma link C++ function  ROOT::R::TRObjectProxy::toVector<Float_t>();

#pragma link C++ function  ROOT::R::TRObjectProxy::toArray<TArrayD,Double_t>();
#pragma link C++ function  ROOT::R::TRObjectProxy::toArray<TArrayF,Float_t>();
#pragma link C++ function  ROOT::R::TRObjectProxy::toArray<TArrayI,Int_t>();

#pragma link C++ function  ROOT::R::TRObjectProxy::toMatrix<Double_t>();

#pragma link C++ global gR;

#endif
