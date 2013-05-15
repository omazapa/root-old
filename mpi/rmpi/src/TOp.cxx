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

#include<TOp.h>
#include<mpi.h>


namespace ROOT {
   namespace Mpi {
      TOp  MAX = MPI::MAX;  //maximun
      TOp  MIN = MPI::MIN;  //minimum
      TOp  SUM = MPI::SUM;  //sum
      TOp  PROD = MPI::PROD; //product
      TOp  LAND = MPI::LAND; //logical and
      TOp  BAND = MPI::BAND; //bit-wise and
      TOp  LOR = MPI::LOR;  //logical or
      TOp  BOR = MPI::BOR;  //bit-wise or
      TOp  LXOR = MPI::LXOR; //logical xor
      TOp  BXOR = MPI::BXOR; //bit-wise xor
      TOp  MAXLOC = MPI::MAXLOC; //max value and location
      TOp  MINLOC = MPI::MINLOC; //min value and location*/

   }
}

using namespace ROOT::Mpi;
ClassImp(TOp)

//______________________________________________________________________________
void TOp::Init(User_function *func, Bool_t commute)
{
   fOp.Init(func, commute);
}

//______________________________________________________________________________
void TOp::Free()
{
   fOp.Free();
}

