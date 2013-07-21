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

#include<TIntracomm.h>
#include<TIntercomm.h>
#include<TInfo.h>

namespace ROOT {
   namespace Mpi {
      //Global Comm
      TIntracomm COMM_WORLD = MPI::COMM_WORLD;
   }
}


using namespace ROOT::Mpi;
ClassImp(TIntracomm)

//______________________________________________________________________________
TIntracomm::TIntracomm(const TIntracomm& comm): TComm(comm)
{
}

//______________________________________________________________________________
// TIntracomm::TIntracomm(const MPI::Intracomm &comm)
// {
//    TComm::fComm = comm;
//
//    //initialize the communications world with an object from mpi in c++
// }

//______________________________________________________________________________
TIntracomm& TIntracomm::Clone() const
{
   MPI_Comm newcomm;
   (void)MPI_Comm_dup((MPI_Comm)fComm, &newcomm);
   TIntracomm *newintracomm = new TIntracomm(newcomm);
   return  *newintracomm;
}



//______________________________________________________________________________
TIntracomm TIntracomm::Dup() const
{
   MPI_Comm newcomm;

   MPI_Comm_dup((MPI_Comm)TComm::fComm, &newcomm);
   const TIntracomm newintracomm(newcomm);
   return  newintracomm;
}

//______________________________________________________________________________
TIntracomm TIntracomm::Create(const TGroup& group) const
{
   MPI_Comm newcomm;
   MPI_Comm_create((MPI_Comm)TComm::fComm, group, &newcomm);
   const TIntracomm newintracomm(newcomm);
   return  newintracomm;
}

//______________________________________________________________________________
TIntracomm TIntracomm::Split(int color, int key) const
{
   MPI_Comm newcomm;
   MPI_Comm_split((MPI_Comm)TComm::fComm, color, key, &newcomm);
   const TIntracomm newintracomm(newcomm);
   return  newintracomm;
}

//______________________________________________________________________________
TIntercomm TIntracomm::Create_intercomm(int local_leader, const TIntracomm& peer_comm, int remote_leader, int tag) const
{
   MPI_Comm newintercomm;
   MPI_Intercomm_create((MPI_Comm)TComm::fComm, local_leader, (MPI_Comm)peer_comm.TComm::fComm, remote_leader, tag, &newintercomm);
   return TIntercomm(newintercomm);
}

//______________________________________________________________________________
TIntercomm TIntracomm::Accept(const char* port_name, const TInfo& info, int root)const
{
   MPI_Comm newcomm;
   MPI_Comm_accept(const_cast<char *>(port_name), info.fInfo, root, (MPI_Comm)TComm::fComm, &newcomm);
   return TIntercomm(newcomm);
}

//______________________________________________________________________________
TIntercomm TIntracomm::Connect(const char* port_name, const TInfo& info, int root)const
{
   MPI_Comm newcomm;
   MPI_Comm_connect(const_cast<char *>(port_name), info.fInfo, root, (MPI_Comm)TComm::fComm, &newcomm);
   return TIntercomm(newcomm);
}

//______________________________________________________________________________
TIntercomm TIntracomm::Spawn(const char* command, const char* argv[], int maxprocs, const TInfo& info, int root) const
{
   MPI_Comm newcomm;
   MPI_Comm_spawn(const_cast<char *>(command), const_cast<char **>(argv), maxprocs, info.fInfo, root, (MPI_Comm)TComm::fComm, &newcomm,
                  (int *)MPI_ERRCODES_IGNORE);
   return TIntercomm(newcomm);
}

//______________________________________________________________________________
TIntercomm TIntracomm::Spawn(const char* command, const char* argv[], int maxprocs, const TInfo& info, int root, int array_of_errcodes[]) const
{
   MPI_Comm newcomm;
   MPI_Comm_spawn(const_cast<char *>(command), const_cast<char **>(argv), maxprocs,
                  info.fInfo, root, (MPI_Comm)TComm::fComm, &newcomm, array_of_errcodes);
   return TIntercomm(newcomm);
}

//______________________________________________________________________________
TIntercomm TIntracomm::Spawn_multiple(int count, const char* array_of_commands[], const char** array_of_argv[],
                                      const int array_of_maxprocs[], const TInfo array_of_info[], int root)
{
   MPI_Comm newcomm;

   MPI_Info *array_of_mpi_info = new MPI_Info[count];
   for (Int_t i = 0; i < count; i++) {
      array_of_mpi_info[i] = array_of_info[i].fInfo;
   }

   MPI_Comm_spawn_multiple(count, const_cast<char **>(array_of_commands),
                           const_cast<char ***>(array_of_argv),
                           const_cast<int *>(array_of_maxprocs),
                           array_of_mpi_info, root,
                           (MPI_Comm)TComm::fComm, &newcomm, (int *)MPI_ERRCODES_IGNORE);
   delete[] array_of_mpi_info;

   return TIntercomm(newcomm);
}

//______________________________________________________________________________
TIntercomm TIntracomm::Spawn_multiple(int count, const char* array_of_commands[], const char** array_of_argv[],
                                      const int array_of_maxprocs[], const TInfo array_of_info[], int root,
                                      int array_of_errcodes[])
{
   MPI_Comm newcomm;
   MPI_Info *array_of_mpi_info = new MPI_Info[count];
   for (Int_t i = 0; i < count; i++) {
      array_of_mpi_info[i] = array_of_info[i].fInfo;
   }

   MPI_Comm_spawn_multiple(count, const_cast<char **>(array_of_commands),
                           const_cast<char ***>(array_of_argv),
                           const_cast<int *>(array_of_maxprocs),
                           array_of_mpi_info, root,
                           (MPI_Comm)TComm::fComm, &newcomm, array_of_errcodes);
   delete[] array_of_mpi_info;
   return TIntercomm(newcomm);
}
