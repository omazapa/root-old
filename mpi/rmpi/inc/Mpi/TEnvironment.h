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

#ifndef ROOT_Mpi_TEnvironment
#define ROOT_Mpi_TEnvironment

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#include<TObject.h>

#if defined(__CINT__) || defined(__MAKECINT__)
namespace MPI {
   void Init(int, char**);
}
#else
#include<mpi.h>
#endif
namespace ROOT {

   namespace Mpi {

      class TEnvironment: public TObject {
      public:
         TEnvironment();
         TEnvironment(int &argc, char **&argv);
         ~TEnvironment();

         void Finalize();
         ClassDef(TEnvironment, 1)
      };
   }

}

#endif
