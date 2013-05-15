/*************************************************************************
 * Copyright (C) 2012,  Gfif Developers                                   *
 * Grupo de Fenomenologia de Interacciones Fundamentales                  *
 * http://gfif.udea.edu.co                                                *
 * División de ciencias de la computación Gfifdev                         *
 * http://gfifdev.udea.edu.co                                             *
 * Class Created and MaInt_tained By Omar Andres Zapata Mesa              *
 * All rights reserved.                                                   *
 *                                                                        *
 *                                                                        *
 * For the list of contributors see $ROOTSYS/README/CREDITS.              *
 *************************************************************************/

#include<Mpi/TCartcomm.h>
#include<Mpi/TIntracomm.h>
using namespace ROOT::Mpi;
ClassImp(TCartcomm)

TCartcomm::TCartcomm(const MPI_Comm& data)
{
   Int_t status = 0;
   if (MPI::Is_initialized() && (data != MPI_COMM_NULL)) {
      MPI_Topo_test(data, &status) ;
      if (status == MPI_CART)
         TComm::fComm = data;
      else
         TComm::fComm = MPI_COMM_NULL;
   } else {
      TComm::fComm = data;
   }
}


TCartcomm::TCartcomm() {}



TCartcomm::TCartcomm(const TCartcomm& data): TIntracomm(data) {}

TCartcomm TCartcomm::Dup() const
{
   MPI_Comm newcomm;
   MPI_Comm_dup((MPI_Comm)TComm::fComm, &newcomm);
   return TCartcomm(newcomm);
}

TCartcomm& TCartcomm::Clone() const
{
   MPI_Comm newcomm;
   MPI_Comm_dup((MPI_Comm)TComm::fComm, &newcomm);
   TCartcomm * dup = new TCartcomm(newcomm);
   return *dup;
}

Int_t TCartcomm::Get_dim() const
{
   Int_t ndims;
   MPI_Cartdim_get((MPI_Comm)TComm::fComm, &ndims);
   return ndims;

}

void TCartcomm::Get_topo(Int_t maxdims, Int_t dims[], Bool_t periods[], Int_t coords[]) const
{
   Int_t *int_periods = new Int_t [maxdims];
   Int_t i;
   for (i = 0; i < maxdims; i++) {
      int_periods[i] = (Int_t)periods[i];
   }
   MPI_Cart_get((MPI_Comm)TComm::fComm, maxdims, dims, int_periods, coords);
   for (i = 0; i < maxdims; i++) {
      periods[i] = Bool_t(int_periods[i]);
   }
   delete [] int_periods;
}

Int_t TCartcomm::Get_cart_rank(const Int_t coords[]) const
{
   Int_t rank;
   MPI_Cart_rank((MPI_Comm)TComm::fComm, const_cast<Int_t *>(coords), &rank);
   return rank;

}

void TCartcomm::Get_coords(Int_t rank, Int_t maxdims, Int_t coords[]) const
{
   MPI_Cart_coords((MPI_Comm)TComm::fComm, rank, maxdims, coords);
}

void TCartcomm::Shift(Int_t direction, Int_t disp, Int_t &rank_source, Int_t &rank_dest) const
{
   MPI_Cart_shift((MPI_Comm)TComm::fComm, direction, disp, &rank_source, &rank_dest);
}

TCartcomm TCartcomm::Sub(const Bool_t remain_dims[])
{
   Int_t ndims;
   MPI_Cartdim_get((MPI_Comm)TComm::fComm, &ndims);
   Int_t* int_remain_dims = new Int_t[ndims];
   for (Int_t i = 0; i < ndims; i++) {
      int_remain_dims[i] = (Int_t)remain_dims[i];
   }
   MPI_Comm newcomm;
   MPI_Cart_sub((MPI_Comm)TComm::fComm, int_remain_dims, &newcomm);
   delete [] int_remain_dims;
   return TCartcomm(newcomm);

}

Int_t TCartcomm::Map(Int_t ndims, const Int_t dims[], const Bool_t periods[]) const
{
   Int_t *int_periods = new Int_t [ndims];
   for (Int_t i = 0; i < ndims; i++) {
      int_periods[i] = (Int_t) periods[i];
   }
   Int_t newrank;
   MPI_Cart_map((MPI_Comm)TComm::fComm, ndims, const_cast<Int_t *>(dims), int_periods, &newrank);
   delete [] int_periods;
   return newrank;
}

