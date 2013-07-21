/*************************************************************************
* Copyright (C) 2010-2013,  Gfif Developers                              *
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

#ifndef ROOT_Mpi_TComm
#define ROOT_Mpi_TComm

/**
   @defgroup Mpi Message Passing Interface
   Message Passing Interface mainly from the \ref RMpi and implemented using the
   <A HREF="http://www.open-mpi.org/">OpenMPI</A> library
 */


/**
   @defgroup Communication Communication class
   @ingroup Communication
 */



#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif

#include<queue>
#include<iostream>
#if defined(__CINT__) || defined(__MAKECINT__)
namespace MPI {
   class Comm_Null;
   class Comm;
   class Intracomm;
   class Intercomm;
   class Graphcomm;
   class Cartcomm;
   class Datatype;
   class Errhandler;
   class Group;
   class Op;
   class Request;
   class Grequest;
   class Status;
   class Info;
   class Win;
   class File;
   Intracomm COMM_WORLD;
}
namespace std {
   class queue<Int_t>;
   class queue<Float_t>;
   class queue<Double_t>;
   class queue<Long_t>;
   class queue<Char_t>;

   class queue<Int_t*>;
   class queue<Float_t*>;
   class queue<Double_t*>;
   class queue<Long_t*>;
   class queue<Char_t*>;

   class queue<TMpiMessage*>;
}
struct MPI_Comm;
typedef void Errhandler_function(Comm&, int*, ...);
typedef int (MPI_Comm_copy_attr_function)(MPI_Comm, int, void *, void *, void *, int *);
typedef int (MPI_Comm_delete_attr_function)(MPI_Comm, int, void *, void *);
#else
#include<mpi.h>
#endif

#include"TEnvironment.h"
#include"TMpiMessage.h"
#include"TErrhandler.h"
#include"TOp.h"
#include"TRequest.h"
#include"MTypes.h"
#include"TMpiException.h"
#include<TClass.h>

namespace MPI {
   class Status;
}

namespace ROOT {
   namespace Mpi {

      class TCommCore: public MPI::Comm {
      public:
         TCommCore(): Comm() {}
         TCommCore(const MPI_Comm &comm): Comm(comm) {}
         TCommCore(const MPI::Comm &comm): Comm(comm) {}

         TCommCore& Clone() const {
            MPI_Comm newcomm;
            MPI_Comm_dup((MPI_Comm)*this, &newcomm);
            TCommCore *comm = new TCommCore(newcomm);
            return *comm;
         }

      };


      class TDatatype;
      class TIntercomm;
//____________________________________________________________________________
      /**
         Class describing a communication methods, p2p, collective and non-bloking.
         The class have facilities to communicate objects too using c++ templates,
         but not all TObjects are supported, then to use this methods you should to use \ref TMpiMessage

         @ingroup Communication
       */
      class TComm: public TObject {
         friend class TDatatype;
      public:
         using TObject::Compare;
         using TObject::Clone;
         TComm() {}
         TComm(const MPI_Comm &comm);
         TComm(const MPI::Comm& data);
         virtual TObject* Clone(const Char_t* data)const {
            return TObject::Clone(data);
         }
         virtual ~TComm() {};
         //World values
         inline Int_t Get_rank() {
            return fComm.Get_rank();
         }
         inline Int_t Get_size() {
            return fComm.Get_size();
         }

         typedef void Errhandler_function(MPI::Comm&, int*, ...);
         typedef int Copy_attr_function(const MPI::Comm& oldcomm, int comm_keyval,
                                        void* extra_state, void* attribute_val_in,
                                        void* attribute_val_out,
                                        bool& flag);
         typedef int Delete_attr_function(MPI::Comm& comm, int comm_keyval,
                                          void* attribute_val,
                                          void* extra_state);

//
// Point-to-Point
//

         virtual void Send(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual void Recv(void *buf, Int_t count, const TDatatype & datatype, Int_t source, Int_t tag, TStatus & status) const;


         virtual void Recv(void *buf, Int_t count, const TDatatype & datatype, Int_t source, Int_t tag) const;

         virtual void Bsend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual void Ssend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const ;

         virtual void Rsend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual TRequest Isend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual TRequest Ibsend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual TRequest Issend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual TRequest Irsend(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual TRequest Irecv(void *buf, Int_t count, const TDatatype & datatype, Int_t source, Int_t tag) const;

         virtual Bool_t Iprobe(Int_t source, Int_t tag, TStatus & status) const;

         virtual Bool_t Iprobe(Int_t source, Int_t tag) const;

         virtual void Probe(Int_t source, Int_t tag, TStatus & status) const;

         virtual void Probe(Int_t source, Int_t tag) const;

         virtual TPrequest Send_init(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual TPrequest Bsend_init(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual TPrequest Ssend_init(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual TPrequest Rsend_init(const void *buf, Int_t count, const TDatatype & datatype, Int_t dest, Int_t tag) const;

         virtual TPrequest Recv_init(void *buf, Int_t count, const TDatatype & datatype, Int_t source, Int_t tag) const;

         virtual void Sendrecv(const void *sendbuf, Int_t sendcount, const TDatatype & sendtype, Int_t dest, Int_t sendtag, void *recvbuf, Int_t recvcount,
                               const TDatatype & recvtype, Int_t source, Int_t recvtag, TStatus & status) const;

         virtual void Sendrecv(const void *sendbuf, Int_t sendcount, const TDatatype & sendtype, Int_t dest, Int_t sendtag,
                               void *recvbuf, Int_t recvcount, const TDatatype & recvtype, Int_t source,
                               Int_t recvtag) const;

         virtual void Sendrecv_replace(void *buf, Int_t count, const TDatatype & datatype, Int_t dest,
                                       Int_t sendtag, Int_t source, Int_t recvtag, TStatus & status) const;

         virtual void Sendrecv_replace(void *buf, Int_t count, const TDatatype & datatype, Int_t dest,
                                       Int_t sendtag, Int_t source, Int_t recvtag) const;

//
// Groups, Contexts, and Communicators
//

         TGroup Get_group() const;

         virtual Int_t Get_size() const;

         virtual Int_t Get_rank() const;

         static Int_t Compare(const TComm & comm1, const TComm & comm2);

         virtual TComm& Clone() const = 0;

         virtual void Free(void);

         virtual Bool_t Is_inter() const;


//
// Collective Communication
//
// Up in Comm because as of MPI-2, they are common to intracomm and
// intercomm -- with the exception of Scan and Exscan, which are not
// defined on intercomms.
//

         virtual void
         Barrier() const;

         virtual void
         Bcast(void *buffer, Int_t count,
               const TDatatype& datatype, Int_t root) const;

         virtual void
         Gather(const void *sendbuf, Int_t sendcount,
                const TDatatype & sendtype,
                void *recvbuf, Int_t recvcount,
                const TDatatype & recvtype, Int_t root) const;

         virtual void
         Gatherv(const void *sendbuf, Int_t sendcount,
                 const TDatatype & sendtype, void *recvbuf,
                 const Int_t recvcounts[], const Int_t displs[],
                 const TDatatype & recvtype, Int_t root) const;

         virtual void
         Scatter(const void *sendbuf, Int_t sendcount,
                 const TDatatype & sendtype,
                 void *recvbuf, Int_t recvcount,
                 const TDatatype & recvtype, Int_t root) const;

         virtual void
         Scatterv(const void *sendbuf, const Int_t sendcounts[],
                  const Int_t displs[], const TDatatype & sendtype,
                  void *recvbuf, Int_t recvcount,
                  const TDatatype & recvtype, Int_t root) const;

         virtual void
         Allgather(const void *sendbuf, Int_t sendcount,
                   const TDatatype & sendtype, void *recvbuf,
                   Int_t recvcount, const TDatatype & recvtype) const;

         virtual void
         Allgatherv(const void *sendbuf, Int_t sendcount,
                    const TDatatype & sendtype, void *recvbuf,
                    const Int_t recvcounts[], const Int_t displs[],
                    const TDatatype & recvtype) const;

         virtual void
         Alltoall(const void *sendbuf, Int_t sendcount,
                  const TDatatype & sendtype, void *recvbuf,
                  Int_t recvcount, const TDatatype & recvtype) const;

         virtual void
         Alltoallv(const void *sendbuf, const Int_t sendcounts[],
                   const Int_t sdispls[], const TDatatype & sendtype,
                   void *recvbuf, const Int_t recvcounts[],
                   const Int_t rdispls[], const TDatatype & recvtype) const;

         virtual void
         Alltoallw(const void *sendbuf, const Int_t sendcounts[],
                   const Int_t sdispls[], const TDatatype sendtypes[],
                   void *recvbuf, const Int_t recvcounts[],
                   const Int_t rdispls[], const TDatatype recvtypes[]) const;

         virtual void
         Reduce(const void *sendbuf, void *recvbuf, Int_t count,
                const TDatatype & datatype, const TOp & op,
                Int_t root) const;


         virtual void
         Allreduce(const void *sendbuf, void *recvbuf, Int_t count,
                   const TDatatype & datatype, const TOp & op) const;

         virtual void
         Reduce_scatter(const void *sendbuf, void *recvbuf,
                        Int_t recvcounts[],
                        const TDatatype & datatype,
                        const TOp & op) const;

//
// Process Creation
//

         virtual void Disconnect();

         static TIntercomm Get_parent();

         static TIntercomm Join(const Int_t fd);

//
// External Interfaces
//

         virtual void Get_name(Char_t * comm_name, Int_t& resultlen) const;

         virtual void Set_name(const Char_t* comm_name);

//
// Process Topologies
//

         virtual Int_t Get_topology() const;

//
// Environmental Inquiry
//

         virtual void Abort(Int_t errorcode);

//
// Errhandler
//

         static TErrhandler Create_errhandler(Errhandler_function* function);

         virtual void Set_errhandler(const TErrhandler& errhandler);

         TErrhandler Get_errhandler() const;

         void Call_errhandler(Int_t errorcode) const;

//
// Keys and Attributes
//

// Need 4 overloaded versions of this function because per the
// MPI-2 spec, you can mix-n-match the C predefined functions with
// C++ functions.
         static Int_t Create_keyval(Copy_attr_function* comm_copy_attr_fn, Delete_attr_function* comm_delete_attr_fn, void* extra_state);
         static Int_t Create_keyval(MPI_Comm_copy_attr_function* comm_copy_attr_fn, MPI_Comm_delete_attr_function* comm_delete_attr_fn, void* extra_state);
         static Int_t Create_keyval(Copy_attr_function* comm_copy_attr_fn, MPI_Comm_delete_attr_function* comm_delete_attr_fn, void* extra_state);
         static Int_t Create_keyval(MPI_Comm_copy_attr_function* comm_copy_attr_fn, Delete_attr_function* comm_delete_attr_fn, void* extra_state);

         static void Free_keyval(Int_t& comm_keyval);

         virtual void Set_attr(Int_t comm_keyval, const void* attribute_val) const;

         virtual Bool_t Get_attr(Int_t comm_keyval, void* attribute_val) const;

         virtual void Delete_attr(Int_t comm_keyval);

         /**************************
         *Not Mpi Standard methods *
         ***************************/

         //----- PoInt_t-to-poInt_t communication

         //----- send/recv prototypes

         template<class ClassType> void SendObject(const ClassType &obj, Int_t dest, Int_t tag);
         template<class ClassType> void RecvObject(ClassType &obj, Int_t source, Int_t tag);

         template<class ClassType> void SendObject(const ClassType *obj, Int_t count, Int_t dest, Int_t tag);
         template<class ClassType> void RecvObject(ClassType *obj, Int_t count, Int_t source, Int_t tag);

         //----- send/recv prototypes non-bloking

         template<class ClassType> TRequest ISendObject(const ClassType &obj, Int_t dest, Int_t tag);
         template<class ClassType> TRequest ISsendObject(const ClassType &obj, Int_t dest, Int_t tag);
         template<class ClassType> TRequest IRsendObject(const ClassType &obj, Int_t dest, Int_t tag);
         template<class ClassType> TRequest IRecvObject(ClassType &obj, Int_t source, Int_t tag);

         //----- Collective prototypes
         template<class ClassType> void BcastObject(ClassType &obj, Int_t root);
         template<class ClassType> void BcastObject(ClassType *obj, Int_t count, Int_t root);

         template<class ClassType> void GatherObject(const ClassType &sendobj, ClassType *recvobjs, Int_t root);
         template<class ClassType> void ScatterObject(const ClassType *sendobjs, ClassType &obj, Int_t root);

         //----- Collective prototypes to All
         template<class ClassType> void AllGatherObject(const ClassType &sendobj, ClassType *recvobjs);

         //internal cache variables.
      protected:
         TCommCore fComm;

         ClassDef(TComm, 1) //
      };
      template<> void TComm::SendObject(const ROOT::Mpi::TMpiMessage& obj, Int_t dest, Int_t tag);
      template<> void TComm::SendObject(const ROOT::Mpi::TMpiMessage *obj, Int_t count, Int_t dest, Int_t tag);
      template<> void TComm::RecvObject(ROOT::Mpi::TMpiMessage& obj, Int_t source, Int_t tag);
      template<> void TComm::RecvObject(ROOT::Mpi::TMpiMessage *obj, Int_t count, Int_t source, Int_t tag);

      template<> TRequest TComm::ISendObject(const ROOT::Mpi::TMpiMessage &obj, Int_t dest, Int_t tag);
      template<> TRequest TComm::ISsendObject(const ROOT::Mpi::TMpiMessage &obj, Int_t dest, Int_t tag);
      template<> TRequest TComm::IRsendObject(const ROOT::Mpi::TMpiMessage &obj, Int_t dest, Int_t tag);
      template<> TRequest TComm::IRecvObject(ROOT::Mpi::TMpiMessage &obj, Int_t source, Int_t tag);


      template<> void TComm::BcastObject(ROOT::Mpi::TMpiMessage &obj, Int_t root);
      template<> void TComm::BcastObject(ROOT::Mpi::TMpiMessage *obj, Int_t count, Int_t root);

      template<> void TComm::GatherObject(const ROOT::Mpi::TMpiMessage &sendobj, ROOT::Mpi::TMpiMessage *recvobjs, Int_t root);
      template<> void TComm::ScatterObject(const ROOT::Mpi::TMpiMessage *sendobjs, ROOT::Mpi::TMpiMessage &recvobj, Int_t root);

      template<> void TComm::AllGatherObject(const ROOT::Mpi::TMpiMessage &sendobj, ROOT::Mpi::TMpiMessage *recvobjs);

#ifndef __CINT__
      //______________________________________________________________________________
      template<class ClassType> void TComm::SendObject(const  ClassType &obj, Int_t dest, Int_t tag)
      {
         TMpiMessage * smsg = new TMpiMessage();
         smsg->SetWriteMode();
         smsg->Reset();

#ifdef  __SUNPRO_CC
         smsg->WriteObject<const ClassType>(&obj);
#else
         smsg->WriteObject(&obj);
#endif
         const Int_t size = smsg->BufferSize();
         const Char_t *buffer = smsg->Buffer();
         std::cout << "Size = " << size << std::endl;
         Send(&size, 1, INT, dest, tag);
         Send(buffer, size, CHAR, dest, tag);
         delete smsg;
      }

      //______________________________________________________________________________
      template<class ClassType> void TComm::RecvObject(ClassType &obj, Int_t source, Int_t tag)
      {
         Int_t size;
         Recv(&size, 1, INT, source, tag);
         std::cout << "Size = " << size << std::endl;
         Char_t *buffer = new Char_t[size];
         Recv(buffer, size, CHAR, source, tag);
         TMpiMessage * rmsg = new TMpiMessage();
         rmsg->SetBuffer(buffer, size, kFALSE);
         rmsg->SetReadMode();
         rmsg->Reset();
         ClassType * obj_tmp = (ClassType *)rmsg->ReadObject(obj.Class());
         memcpy(&obj, obj_tmp, sizeof(ClassType));
         delete rmsg;
      }

      //______________________________________________________________________________
      template<class ClassType> void TComm::SendObject(const ClassType *obj, Int_t count, Int_t dest, Int_t tag)
      {
         for (Int_t i = 0; i < count; i++) SendObject(obj[i], dest, tag);
      }

      //______________________________________________________________________________
      template<class ClassType> void TComm::RecvObject(ClassType *obj, Int_t count, Int_t source, Int_t tag)
      {
         for (Int_t i = 0; i < count; i++) RecvObject(obj[i], source, tag);
      }

      //______________________________________________________________________________
      template <class ClassType> void TComm::BcastObject(ClassType &obj, Int_t root)
      {
         Int_t size;
         Char_t *buffer;
         if (Get_rank() == root) {
            TMpiMessage * smsg = new TMpiMessage();
            smsg->SetWriteMode();
            smsg->Reset();
#ifdef  __SUNPRO_CC
            smsg->WriteObject<ClassType>(&obj);
#else
            smsg->WriteObject(&obj);
#endif
            size = smsg->BufferSize();
            buffer = new Char_t[size];
            memcpy(buffer, smsg->Buffer(), size * sizeof(Char_t));
            delete smsg;
         }
         Bcast(&size, 1, INT, root);

         if (Get_rank() != root) {
            buffer = new Char_t[size];
         }
         Bcast(buffer, size, CHAR, root);

         TMpiMessage * rmsg = new TMpiMessage();
         rmsg->SetBuffer(buffer, size, kFALSE);
         rmsg->SetReadMode();
         rmsg->Reset();
         ClassType * obj_tmp = (ClassType *)rmsg->ReadObject(obj.Class());
         memcpy(&obj, obj_tmp, sizeof(ClassType));
         delete rmsg;
      }

      //______________________________________________________________________________
      template<class ClassType> void TComm::BcastObject(ClassType *obj, Int_t count, Int_t root)
      {
         for (Int_t i = 0; i < count; i++) BcastObject(obj[i], root);
      }

      //______________________________________________________________________________
      template<class ClassType> void TComm::GatherObject(const ClassType &sendobj, ClassType *recvobjs, Int_t root)
      {
         if (Get_rank() == root) {
            for (Int_t i = 0; i < Get_size(); i++) {
               if (i != root) {
                  TMpiMessage * rmsg = new TMpiMessage();
                  RecvObject(*rmsg, i, root);
                  ClassType * obj_tmp = (ClassType *)rmsg->ReadObject(recvobjs[i].Class());
                  memcpy(&recvobjs[i], obj_tmp, sizeof(ClassType));
                  delete rmsg;
               }
            }
            memcpy(&recvobjs[root], &sendobj, sizeof(ClassType));
         } else {
            TMpiMessage * smsg = new TMpiMessage();
#ifdef  __SUNPRO_CC
            smsg->WriteObject<const ClassType>(&sendobj);
#else
            smsg->WriteObject(&sendobj);
#endif
            SendObject(*smsg, root, root);
            delete smsg;
         }
      }

      //______________________________________________________________________________
      template<class ClassType> void TComm::ScatterObject(const ClassType *sendobjs, ClassType &recvobj, Int_t root)
      {
         if (Get_rank() == root) {
            for (Int_t i = 0; i < Get_size(); i++) {
               if (i != root) SendObject(sendobjs[i], i, root);
            }
            memcpy(&recvobj, &sendobjs[root], sizeof(ClassType));
         } else {
            RecvObject(recvobj, root, root);
         }
      }

      //______________________________________________________________________________
      template<class ClassType> TRequest TComm::ISendObject(const ClassType &obj, Int_t dest, Int_t tag)
      {
         TMpiMessage * smsg = new TMpiMessage();
#ifdef  __SUNPRO_CC
         smsg->WriteObject<const ClassType>(&obj);
#else
         smsg->WriteObject(&obj);
#endif
         Int_t size = smsg->BufferSize();
         Char_t *buffer = smsg->Buffer();
         TRequest req = Isend(&size, 1, ROOT::Mpi::INT, dest, tag);
         req = Isend(buffer, size, ROOT::Mpi::CHAR, dest, tag);
         delete smsg;
         return req;
      }

      //______________________________________________________________________________
      template<class ClassType> TRequest TComm::ISsendObject(const ClassType &obj, Int_t dest, Int_t tag)
      {
         TMpiMessage * smsg = new TMpiMessage();
#ifdef  __SUNPRO_CC
         smsg->WriteObject<const ClassType>(&obj);
#else
         smsg->WriteObject(&obj);
#endif
         Int_t size = smsg->BufferSize();
         Char_t *buffer = smsg->Buffer();
         TRequest req = Issend(&size, 1, ROOT::Mpi::INT, dest, tag);
         req = Issend(buffer, size, ROOT::Mpi::CHAR, dest, tag);
         delete smsg;
         return req;
      }

      //______________________________________________________________________________
      template<class ClassType> TRequest TComm::IRsendObject(const ClassType &obj, Int_t dest, Int_t tag)
      {
         TMpiMessage * smsg = new TMpiMessage();
#ifdef  __SUNPRO_CC
         smsg->WriteObject<const ClassType>(&obj);
#else
         smsg->WriteObject(&obj);
#endif
         Int_t size = smsg->BufferSize();
         Char_t *buffer = smsg->Buffer();
         TRequest req = Irsend(&size, 1, ROOT::Mpi::INT, dest, tag);
         req = Irsend(buffer, size, ROOT::Mpi::CHAR, dest, tag);
         delete smsg;
         return req;
      }

      //______________________________________________________________________________
      template<class ClassType> TRequest TComm::IRecvObject(ClassType &obj, Int_t source, Int_t tag)
      {
         Int_t size;
         TRequest req = Irecv(&size, 1, ROOT::Mpi::INT, source, tag);
         req.Wait();
         Char_t *buffer = new Char_t[size];
         req = Irecv(buffer, size, ROOT::Mpi::CHAR, source, tag);
         req.Wait();
         TMpiMessage * rmsg = new TMpiMessage();
         rmsg->SetBuffer(buffer, size, kFALSE);
         rmsg->SetReadMode();
         rmsg->Reset();
         ClassType * obj_tmp = (ClassType *)rmsg->ReadObject(obj.Class());
         memcpy(&obj, obj_tmp, sizeof(ClassType));
         delete rmsg;
         return req;

      }

      //______________________________________________________________________________
      template<class ClassType> void TComm::AllGatherObject(const ClassType &sendobj, ClassType *recvobjs)
      {
         for (Int_t i = 0; i < Get_size(); i++) GatherObject(sendobj, recvobjs, i);
      }



#endif//__CINT__


   }//end namespace Mpi
}//end namespace ROOT

#endif
