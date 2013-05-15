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
#ifndef ROOT_Mpi_TOp
#define ROOT_Mpi_TOp
#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#ifdef __CINT__
namespace MPI {
   class Op;
   class Datatype;
   typedef void User_function(const void* invec, void* inoutvec, int len, const Datatype& datatype);
}
struct MPI_Op;

#else
#include<mpi.h>
#endif
#include<TObject.h>
namespace ROOT {
   namespace Mpi {
      typedef MPI::User_function  User_function;
      class TComm;
      class TWin;
      class TOp: public TObject {
         friend class TComm;
         friend class TWin;
      protected:
         MPI::Op fOp;
      public:
         TOp() {}
         TOp(MPI_Op op) {
            fOp = op;
         }
         TOp(const MPI::Op& op) {
            fOp = op;
         }
         TOp(const TOp& op): TObject(op) {
            fOp = op.fOp;
         }

         TOp& operator=(const MPI_Op& op) {
            fOp = op;
            return *this;
         }

         TOp& operator=(const MPI::Op& op) {
            fOp = op;
            return *this;
         }

         TOp& operator=(const TOp& op) {
            fOp = op.fOp;
            return *this;
         }

         virtual void Init(User_function *func, Bool_t commute);
         virtual void Free();
         ClassDef(TOp, 1)
      };
      R__EXTERN ROOT::Mpi::TOp MAX;    //maximun
      R__EXTERN ROOT::Mpi::TOp MIN;    //minimum
      R__EXTERN ROOT::Mpi::TOp SUM;    //sum
      R__EXTERN ROOT::Mpi::TOp PROD;   //product
      R__EXTERN ROOT::Mpi::TOp LAND;   //logical and
      R__EXTERN ROOT::Mpi::TOp BAND;   //bit-wise and
      R__EXTERN ROOT::Mpi::TOp LOR;    //logical or
      R__EXTERN ROOT::Mpi::TOp BOR;    //bit-wise or
      R__EXTERN ROOT::Mpi::TOp LXOR;   //logical xor
      R__EXTERN ROOT::Mpi::TOp BXOR;   //bit-wise xor
      R__EXTERN ROOT::Mpi::TOp MAXLOC; //max value and location
      R__EXTERN ROOT::Mpi::TOp MINLOC; //min value and location
   }
}
#endif
