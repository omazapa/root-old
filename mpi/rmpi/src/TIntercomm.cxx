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

#include<TIntercomm.h>
#include<TIntracomm.h>
using namespace ROOT::Mpi;
ClassImp(TIntercomm)

//______________________________________________________________________________
TIntercomm::TIntercomm(const TIntercomm& comm): TComm(comm)
{
}

//______________________________________________________________________________
TIntercomm::TIntercomm(MPI::Intercomm comm)
{
   TComm::fComm = comm;
}

//______________________________________________________________________________
TIntercomm& TIntercomm::Clone() const
{
   MPI_Comm newcomm;
   MPI_Comm_dup(TComm::fComm, &newcomm);
   TIntercomm *newintercomm = new TIntercomm(newcomm);
   return  *newintercomm;
}

//______________________________________________________________________________
TIntracomm TIntercomm::Merge(bool high)
{
   MPI_Comm newcomm;
   MPI_Intercomm_merge((MPI_Comm)TComm::fComm, (int)high, &newcomm);
   return TIntracomm(newcomm);
}

//______________________________________________________________________________
Int_t TIntercomm::Get_remote_size() const
{
   Int_t size;
   MPI_Comm_remote_size((MPI_Comm)TComm::fComm, &size);
   return size;

}

//______________________________________________________________________________
TGroup TIntercomm::Get_remote_group() const
{
   MPI_Group group;
   MPI_Comm_remote_group((MPI_Comm)TComm::fComm, &group);
   return TGroup(group);

}

//______________________________________________________________________________
TIntercomm TIntercomm::Dup() const
{
   MPI_Comm newcomm;

   MPI_Comm_dup((MPI_Comm)TComm::fComm, &newcomm);
   const TIntercomm newintracomm(newcomm);
   return  newintracomm;
}

//______________________________________________________________________________
TIntercomm TIntercomm::Create(const TGroup& group) const
{
   MPI_Comm newcomm;
   MPI_Comm_create(TComm::fComm, group, &newcomm);
   const TIntercomm newintracomm(newcomm);
   return  newintracomm;
}

//______________________________________________________________________________
TIntercomm TIntercomm::Split(int color, int key) const
{
   MPI_Comm newcomm;
   MPI_Comm_split((MPI_Comm)TComm::fComm, color, key, &newcomm);
   const TIntercomm newintracomm(newcomm);
   return  newintracomm;
}
