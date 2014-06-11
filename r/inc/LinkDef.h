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

#pragma link C++ class ROOT::R::TRObjectProxy+;

#pragma link C++ class ROOT::R::TRGraph+;
#pragma link C++ class ROOT::R::TRCanvas+;
#pragma link C++ class ROOT::R::TRF1+;
#pragma link C++ class ROOT::R::TRRint+;
#pragma link C++ class ROOT::R::TRSystem+;
#pragma link C++ class ROOT::R::TRFile+;

#endif
