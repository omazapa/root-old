/*************************************************************************
* Copyright (C) 2012,  Gfif Developers                              *
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
#include<TIntercomm.h>
#include<TGroup.h>
using namespace ROOT::Mpi;

//
// Point-to-Point
//

//______________________________________________________________________________
void TComm::Send(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   fComm.Send(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
void TComm::Recv(void *buf, Int_t count, const TDatatype & datatype, Int_t source, Int_t tag, TStatus & status) const
{
   fComm.Recv(buf, count, datatype, source, tag, status);
}

//______________________________________________________________________________
void TComm::Recv(void *buf, Int_t count, const TDatatype & datatype, Int_t source, Int_t tag) const
{
   fComm.Recv(buf, count, datatype, source, tag);
}

//______________________________________________________________________________
void TComm::Bsend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   fComm.Bsend(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
void TComm::Ssend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   fComm.Ssend(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
void TComm::Rsend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   fComm.Rsend(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
TRequest TComm::Isend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   return  fComm.Isend(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
TRequest TComm::Ibsend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   return  fComm.Ibsend(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
TRequest TComm::Issend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   return  fComm.Issend(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
TRequest TComm::Irsend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   return  fComm.Irsend(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
TRequest TComm::Irecv(void *buf, Int_t count, const TDatatype & datatype, Int_t source, Int_t tag) const
{
   return fComm.Irecv(buf, count, datatype, source, tag);
}

//______________________________________________________________________________
Bool_t TComm::Iprobe(Int_t source, Int_t tag, TStatus & status) const
{
   return fComm.Iprobe(source, tag, status);
}

//______________________________________________________________________________
Bool_t TComm::Iprobe(Int_t source, Int_t tag) const
{
   return fComm.Iprobe(source, tag);
}

//______________________________________________________________________________
void TComm::Probe(Int_t source, Int_t tag, TStatus & status) const
{
   fComm.Probe(source, tag, status);
}

//______________________________________________________________________________
void TComm::Probe(Int_t source, Int_t tag) const
{
   fComm.Probe(source, tag);
}

//______________________________________________________________________________
TPrequest TComm::Send_init(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   return fComm.Send_init(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
TPrequest TComm::Bsend_init(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   return fComm.Bsend_init(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
TPrequest TComm::Ssend_init(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   return fComm.Ssend_init(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
TPrequest TComm::Rsend_init(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const
{
   return fComm.Rsend_init(buf, count, datatype, dest, tag);
}

//______________________________________________________________________________
TPrequest TComm::Recv_init(void *buf, Int_t count, const TDatatype & datatype, Int_t source, Int_t tag) const
{
   return fComm.Recv_init(buf, count, datatype, source, tag);
}

//______________________________________________________________________________
void TComm::Sendrecv(const void *sendbuf, Int_t sendcount, const TDatatype & sendtype, Int_t dest, Int_t sendtag, void *recvbuf, Int_t recvcount,
                     const TDatatype & recvtype, Int_t source, Int_t recvtag, TStatus & status) const
{
   fComm.Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, status);
}

//______________________________________________________________________________
void TComm::Sendrecv(const void *sendbuf, Int_t sendcount, const TDatatype & sendtype, Int_t dest, Int_t sendtag,
                     void *recvbuf, Int_t recvcount, const TDatatype & recvtype, Int_t source,
                     Int_t recvtag) const
{
   fComm.Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag);
}

//______________________________________________________________________________
void TComm::Sendrecv_replace(void *buf, Int_t count, const TDatatype & datatype, Int_t dest,
                             Int_t sendtag, Int_t source, Int_t recvtag, TStatus & status) const
{
   fComm.Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, status);
}

//______________________________________________________________________________
void TComm::Sendrecv_replace(void *buf, Int_t count, const TDatatype & datatype, Int_t dest,
                             Int_t sendtag, Int_t source, Int_t recvtag) const
{
   fComm.Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag);
}


//
// Groups, Contexts, and Communicators
//

//______________________________________________________________________________
TGroup TComm::Get_group() const
{
   return fComm.Get_group();
}


//______________________________________________________________________________
Int_t TComm::Get_size() const
{
   return fComm.Get_size();
}

//______________________________________________________________________________
Int_t TComm::Get_rank() const
{
   return fComm.Get_rank();
}

//______________________________________________________________________________
Int_t TComm::Compare(const TComm & comm1, const TComm & comm2)
{

   return TCommCore::Compare(comm1.fComm, comm2.fComm);
}

//______________________________________________________________________________
void TComm::Free(void)
{
   fComm.Free();
}

//______________________________________________________________________________
Bool_t TComm::Is_inter() const
{
   return fComm.Is_inter();
}

//
// Collective Communication
//
// Up in Comm because as of MPI-2, they are common to intracomm and
// intercomm -- with the exception of Scan and Exscan, which are not
// defined on intercomms.
//

//______________________________________________________________________________
void  TComm::Barrier() const
{
   fComm.Barrier();
}


//______________________________________________________________________________
void  TComm::Bcast(void *buffer, Int_t count, const TDatatype& datatype, Int_t root) const
{
   fComm.Bcast(buffer, count, datatype, root);
}

//______________________________________________________________________________
void  TComm::Gather(const void *sendbuf, Int_t sendcount,
                    const TDatatype & sendtype,
                    void *recvbuf, Int_t recvcount,
                    const TDatatype & recvtype, Int_t root) const
{
   fComm.Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root);
}

//______________________________________________________________________________
void  TComm::Gatherv(const void *sendbuf, Int_t sendcount, const TDatatype & sendtype, void *recvbuf,
                     const Int_t recvcounts[], const Int_t displs[],
                     const TDatatype & recvtype, Int_t root) const
{
   fComm.Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root);
}

//______________________________________________________________________________
void  TComm::Scatter(const void *sendbuf, Int_t sendcount, const TDatatype & sendtype,
                     void *recvbuf, Int_t recvcount,
                     const TDatatype & recvtype, Int_t root) const
{
   fComm.Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root);
}

//______________________________________________________________________________
void  TComm::Scatterv(const void *sendbuf, const Int_t sendcounts[],
                      const Int_t displs[], const TDatatype & sendtype,
                      void *recvbuf, Int_t recvcount,
                      const TDatatype & recvtype, Int_t root) const
{
   fComm.Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root);
}

//______________________________________________________________________________
void  TComm::Allgather(const void *sendbuf, Int_t sendcount,
                       const TDatatype & sendtype, void *recvbuf,
                       Int_t recvcount, const TDatatype & recvtype) const
{
   fComm.Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype);
}

//______________________________________________________________________________
void TComm::Allgatherv(const void *sendbuf, Int_t sendcount,
                       const TDatatype & sendtype, void *recvbuf,
                       const Int_t recvcounts[], const Int_t displs[],
                       const TDatatype & recvtype) const
{
   fComm.Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype);
}

//______________________________________________________________________________
void  TComm::Alltoall(const void *sendbuf, Int_t sendcount, const TDatatype & sendtype, void *recvbuf,
                      Int_t recvcount, const TDatatype & recvtype) const
{
   fComm.Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype);
}

//______________________________________________________________________________
void  TComm::Alltoallv(const void *sendbuf, const Int_t sendcounts[],
                       const Int_t sdispls[], const TDatatype & sendtype,
                       void *recvbuf, const Int_t recvcounts[],
                       const Int_t rdispls[], const TDatatype & recvtype) const
{
   fComm.Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype);
}

//______________________________________________________________________________
void  TComm::Alltoallw(const void *sendbuf, const Int_t sendcounts[],
                       const Int_t sdispls[], const TDatatype sendtypes[],
                       void *recvbuf, const Int_t recvcounts[],
                       const Int_t rdispls[], const TDatatype recvtypes[]) const
{
   const int comm_size = Get_size();
   MPI::Datatype *recvtypes_core = new MPI::Datatype[comm_size];
   MPI::Datatype *sendtypes_core = new MPI::Datatype[comm_size];

   for (int i = 0; i < comm_size; i++) {
      sendtypes_core[i] = sendtypes[i].fDatatype;
      recvtypes_core[i] = recvtypes[i].fDatatype;
   }

   fComm.Alltoallw(sendbuf, sendcounts, sdispls, sendtypes_core, recvbuf, recvcounts, rdispls, recvtypes_core);

   delete[] recvtypes_core;
   delete[] sendtypes_core;
}

//______________________________________________________________________________
void  TComm::Reduce(const void *sendbuf, void *recvbuf, Int_t count,
                    const TDatatype & datatype, const TOp & op,
                    Int_t root) const
{
   fComm.Reduce(sendbuf, recvbuf, count, datatype, op.fOp, root);
}


//______________________________________________________________________________
void  TComm::Allreduce(const void *sendbuf, void *recvbuf, Int_t count,
                       const TDatatype & datatype, const TOp & op) const
{
   fComm.Allreduce(sendbuf, recvbuf, count, datatype, op.fOp);
}

//______________________________________________________________________________
void  TComm::Reduce_scatter(const void *sendbuf, void *recvbuf, Int_t recvcounts[],
                            const TDatatype & datatype, const TOp & op) const
{
   fComm.Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op.fOp);
}

//
// Process Creation
//

//______________________________________________________________________________
void TComm::Disconnect()
{
   fComm.Disconnect();
}

//______________________________________________________________________________
TIntercomm TComm::Get_parent()
{
   return TCommCore::Get_parent();
}

//______________________________________________________________________________
TIntercomm TComm::Join(const Int_t fd)
{
   return TCommCore::Join(fd);
}

//
// External Interfaces
//

//______________________________________________________________________________
void TComm::Get_name(Char_t * comm_name, Int_t& resultlen) const
{
   fComm.Get_name(comm_name, resultlen);
}

//______________________________________________________________________________
void TComm::Set_name(const Char_t* comm_name)
{
   fComm.Set_name(comm_name);
}

//
// Process Topologies
//

//______________________________________________________________________________
Int_t TComm::Get_topology() const
{
   return fComm.Get_topology();
}

//
// Environmental Inquiry
//

//______________________________________________________________________________
void TComm::Abort(Int_t errorcode)
{
   fComm.Abort(errorcode);
}


//
// Errhandler
//

//______________________________________________________________________________
TErrhandler TComm::Create_errhandler(Errhandler_function* function)
{
   return TCommCore::Create_errhandler(function);
}

//______________________________________________________________________________
void TComm::Set_errhandler(const TErrhandler& errhandler)
{
   fComm.Set_errhandler(errhandler);
}
TErrhandler TComm::Get_errhandler() const
{
   return fComm.Get_errhandler();
}

//______________________________________________________________________________
void TComm::Call_errhandler(Int_t errorcode) const
{
   fComm.Call_errhandler(errorcode);
}

//______________________________________________________________________________
Int_t TComm::Create_keyval(Copy_attr_function* comm_copy_attr_fn, Delete_attr_function* comm_delete_attr_fn, void* extra_state)
{
   return  TCommCore::Create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
Int_t TComm::Create_keyval(MPI_Comm_copy_attr_function* comm_copy_attr_fn, MPI_Comm_delete_attr_function* comm_delete_attr_fn, void* extra_state)
{
   return  TCommCore::Create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
Int_t TComm::Create_keyval(Copy_attr_function* comm_copy_attr_fn, MPI_Comm_delete_attr_function* comm_delete_attr_fn, void* extra_state)
{
   return  TCommCore::Create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
Int_t TComm::Create_keyval(MPI_Comm_copy_attr_function* comm_copy_attr_fn, Delete_attr_function* comm_delete_attr_fn, void* extra_state)
{
   return  TCommCore::Create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
void TComm::Free_keyval(Int_t& comm_keyval)
{
   TCommCore::Free_keyval(comm_keyval);
}

//______________________________________________________________________________
void TComm::Set_attr(Int_t comm_keyval, const void* attribute_val) const
{
   fComm.Set_attr(comm_keyval, attribute_val);
}

//______________________________________________________________________________
Bool_t TComm::Get_attr(Int_t comm_keyval, void* attribute_val) const
{
   return fComm.Get_attr(comm_keyval, attribute_val);
}

//______________________________________________________________________________
void TComm::Delete_attr(Int_t comm_keyval)
{
   fComm.Delete_attr(comm_keyval);
}

