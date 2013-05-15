/*************************************************************************
* Copyright (C) 2012,  Gfif Developers                                   *
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

#include<TErrhandler.h>

namespace ROOT {
   namespace Mpi {
      const TErrhandler  ERRORS_ARE_FATAL = MPI::ERRORS_ARE_FATAL;
      const TErrhandler  ERRORS_RETURN = MPI::ERRORS_RETURN;
      const TErrhandler  ERRORS_THROW_EXCEPTIONS = MPI::ERRORS_THROW_EXCEPTIONS;
   }
}

using namespace ROOT::Mpi;

ClassImp(TErrhandler)
//______________________________________________________________________________
TErrhandler::TErrhandler(): Errhandler() {}


//______________________________________________________________________________
TErrhandler::TErrhandler(const MPI_Errhandler &err): Errhandler(err) {}

//______________________________________________________________________________
TErrhandler::TErrhandler(const MPI::Errhandler &err): Errhandler(err) {}

//______________________________________________________________________________
TErrhandler::TErrhandler(const TErrhandler& err) : Errhandler(err), TObject(err) { }

//______________________________________________________________________________
void TErrhandler::Free()
{
   Errhandler::Free();
}


