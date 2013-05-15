/*************************************************************************
* Copyright (C) 2010-2012,  Gfif Developers                              *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* http://gfifdev.udea.edu.co                                             *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
*                                                                        *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
*************************************************************************/

#include<Mpi/TEnvironment.h>
#include<Mpi/TFunctions.h>
#include<Mpi/TComm.h>

using namespace ROOT::Mpi;

ClassImp(TEnvironment)
//______________________________________________________________________________
TEnvironment::TEnvironment()
{
   //The constructor initialize Mpi's Environment and set the flag bStart like Initizalized
   MPI::Init();
}

//______________________________________________________________________________
TEnvironment::TEnvironment(int &argc, char **&argv)
{
   //The constructor initialize Mpi's Environment and set the flag bStart like Initizalized
   MPI::Init(argc, argv);
}

//______________________________________________________________________________
TEnvironment::~TEnvironment()
{
   //if mpi's environment is initialized then finalize it
   if (!Is_finalized()) {
      MPI::Finalize();
   }
}

//______________________________________________________________________________
void TEnvironment::Finalize()
{
   //Finalize the mpi's environment
   MPI::Finalize();
}