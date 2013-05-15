/*************************************************************************
 * Copyright (C) 2012,  Gfif Developers                                   *
 * Grupo de Fenomenologia de Interacciones Fundamentales                  *
 * http://gfif.udea.edu.co                                                *
 * División de ciencias de la computación Gfifdev                         *
 * http://gfifdev.udea.edu.co                                             *
 * Class Created and MaInt_tained By Omar Andres Zapata Mesa                *
 * All rights reserved.                                                   *
 *                                                                        *
 *                                                                        *
 * For the list of contributors see $ROOTSYS/README/CREDITS.              *
 *************************************************************************/

#ifndef ROOT_Mpi_TCartcomm
#define ROOT_Mpi_TCartcomm

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#include<TObject.h>
#include"TGroup.h"
#include"TIntracomm.h"
namespace ROOT {

   namespace Mpi {
      class TIntracomm;
      class TCartcomm: public TIntracomm {
      private:
         TCartcomm(const MPI_Comm& data);
      public:
         using TComm::Clone;
         TCartcomm();
         TCartcomm(const TCartcomm& data);

         TCartcomm& operator=(const TCartcomm& data) {
            TComm::fComm = data.fComm;
            return *this;
         }

         //
         // Groups, Contexts, and Comms
         //

         TCartcomm Dup() const;

         virtual TCartcomm& Clone() const;


         //
         // Groups, Contexts, and Comms
         //

         virtual Int_t Get_dim() const;

         virtual void Get_topo(Int_t maxdims, Int_t dims[], Bool_t periods[], Int_t coords[]) const;

         virtual Int_t Get_cart_rank(const Int_t coords[]) const;

         virtual void Get_coords(Int_t rank, Int_t maxdims, Int_t coords[]) const;

         virtual void Shift(Int_t direction, Int_t disp, Int_t &rank_source, Int_t &rank_dest) const;

         virtual TCartcomm Sub(const Bool_t remain_dims[]);

         virtual Int_t Map(Int_t ndims, const Int_t dims[], const Bool_t periods[]) const;

         ClassDef(TCartcomm, 3) //
      };
   }

}

#endif
