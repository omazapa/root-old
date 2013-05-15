/*************************************************************************
 * Copyright (C)2012,  Gfif Developers                                   *
 * Grupo de Fenomenologia de Interacciones Fundamentales                 *
 * http://gfif.udea.edu.co                                               *
 * División de ciencias de la computación Gfifdev                        *
 * http://gfifdev.udea.edu.co                                            *
 * Class Created and Maintained By Omar Andres Zapata Mesa               *
 * All rights reserved.                                                  *
 *                                                                       *
 *                                                                       *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#ifndef ROOT_Mpi_TErrhandler
#define ROOT_Mpi_TErrhandler
#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#ifdef __CINT__
namespace MPI {
   class Errhandler;
}
struct MPI_Errhandler;
#else
#include<mpi.h>
#endif
#include<TObject.h>

namespace ROOT {
   namespace Mpi {
      class TErrhandler: public MPI::Errhandler, public TObject {
      public:
         TErrhandler();
         TErrhandler(const MPI_Errhandler &err);
         TErrhandler(const MPI::Errhandler &err);
         TErrhandler(const TErrhandler &err);

         inline virtual ~TErrhandler() { }


         inline TErrhandler& operator=(const TErrhandler& e) {
            mpi_errhandler = e.mpi_errhandler;
            return *this;
         }

         inline TErrhandler& operator=(const MPI::Errhandler& e) {
            mpi_errhandler = (MPI_Errhandler)e;
            return *this;
         }

         // comparison
         inline bool operator==(const TErrhandler &a) {
            return (bool)(mpi_errhandler == a.mpi_errhandler);
         }

         inline bool operator!=(const TErrhandler &a) {
            return (bool)!(*this == a);
         }

         // inter-language operability
         inline TErrhandler& operator= (const MPI_Errhandler &i) {
            mpi_errhandler = i;
            return *this;
         }

         inline operator MPI_Errhandler() const {
            return mpi_errhandler;
         }

         virtual void Free();
      protected:
         MPI_Errhandler mpi_errhandler;

         ClassDef(TErrhandler, 1)
      };
      // error-handling specifiers
      R__EXTERN const TErrhandler  ERRORS_ARE_FATAL;
      R__EXTERN const TErrhandler  ERRORS_RETURN;
      R__EXTERN const TErrhandler  ERRORS_THROW_EXCEPTIONS;
   }
}
#endif
