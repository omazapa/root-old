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

#include<TGraphcomm.h>
#include<TIntracomm.h>
using namespace ROOT::Mpi;
ClassImp(TGraphcomm)

//______________________________________________________________________________
TGraphcomm::TGraphcomm() {}

//______________________________________________________________________________
TGraphcomm::TGraphcomm(const MPI_Comm& data)
{
   Int_t status = 0;
   if (MPI::Is_initialized() && (data != MPI_COMM_NULL)) {
      MPI_Topo_test(data, &status) ;
      if (status == MPI_GRAPH)
         TComm::fComm = data;
      else
         TComm::fComm = MPI_COMM_NULL;
   } else {
      TComm::fComm = data;
   }
}

//______________________________________________________________________________
TGraphcomm::TGraphcomm(const TGraphcomm& data): TIntracomm(data) {}

//______________________________________________________________________________
TGraphcomm TGraphcomm::Dup() const
{
   MPI_Comm newcomm;
   MPI_Comm_dup((MPI_Comm)TComm::fComm, &newcomm);
   return TGraphcomm(newcomm);
}

//______________________________________________________________________________
TGraphcomm& TGraphcomm::Clone() const
{
   MPI_Comm newcomm;
   MPI_Comm_dup((MPI_Comm)TComm::fComm, &newcomm);
   TGraphcomm * dup = new TGraphcomm(newcomm);
   return *dup;
}

//______________________________________________________________________________
void TGraphcomm::Get_dims(Int_t nnodes[], Int_t nedges[]) const
{
   MPI_Graphdims_get((MPI_Comm)TComm::fComm, nnodes, nedges);
}

//______________________________________________________________________________
void TGraphcomm::Get_topo(Int_t maxindex, Int_t maxedges, Int_t index[], Int_t edges[]) const
{
   MPI_Graph_get((MPI_Comm)TComm::fComm, maxindex, maxedges, index, edges);
}

//______________________________________________________________________________
Int_t TGraphcomm::Get_neighbors_count(Int_t rank) const
{
   Int_t nneighbors;
   MPI_Graph_neighbors_count((MPI_Comm)TComm::fComm, rank, &nneighbors);
   return nneighbors;
}

//______________________________________________________________________________
void TGraphcomm::Get_neighbors(Int_t rank, Int_t maxneighbors, Int_t neighbors[]) const
{
   MPI_Graph_neighbors((MPI_Comm)TComm::fComm, rank, maxneighbors, neighbors);
}

//______________________________________________________________________________
Int_t TGraphcomm::Map(Int_t nnodes, const Int_t index[], const Int_t edges[]) const
{
   Int_t newrank;
   MPI_Graph_map((MPI_Comm)TComm::fComm, nnodes, const_cast<int *>(index), const_cast<int *>(edges), &newrank);
   return newrank;

}
