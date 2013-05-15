// @(#)root/mpi:$Id: LinkDef.h  -- :: $

/*************************************************************************
 * Copyright (C) 2012 , Omar Andres Zapata Mesa           .               *
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
#pragma link C++ class ROOT::Mpi::TMpiMessage;
#pragma link C++ class ROOT::Mpi::TEnvironment;
#pragma link C++ class ROOT::Mpi::TErrhandler;
#pragma link C++ class+protected ROOT::Mpi::TComm;


#pragma link C++ class ROOT::Mpi::TMpiException;
#pragma link C++ class ROOT::Mpi::TGroup;

#pragma link C++ class ROOT::Mpi::TInfo;

#pragma link C++ class ROOT::Mpi::TIntracomm;
#pragma link C++ class ROOT::Mpi::TIntercomm;
#pragma link C++ class ROOT::Mpi::TCartcomm;
#pragma link C++ class ROOT::Mpi::TGraphcomm;
#pragma link C++ class ROOT::Mpi::TOp;
#pragma link C++ class ROOT::Mpi::TRequest;
#pragma link C++ class ROOT::Mpi::TPrequest;
#pragma link C++ class ROOT::Mpi::TGrequest;
#pragma link C++ class ROOT::Mpi::TStatus;
#pragma link C++ class ROOT::Mpi::TDatatype;

#pragma link C++ class ROOT::Mpi::TWin;
#pragma link C++ typedef ROOT::Mpi::TWin::Copy_attr_function;
#pragma link C++ typedef ROOT::Mpi::TWin::Delete_attr_function;
#pragma link C++ typedef ROOT::Mpi::TWin::Errhandler_function;

#pragma link C++ class ROOT::Mpi::TFile;

/*
 * Global communicator
 */
#pragma link C++ global ROOT::Mpi::COMM_WORLD;

#ifdef USE_FOR_AUTLOADING
#pragma link C++ class ROOT::Mpi;
#endif

#endif
