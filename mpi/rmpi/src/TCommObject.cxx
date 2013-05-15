/*************************************************************************
 * Copyright (C) 2010-2012,  Gfif Developers                              *
 * Grupo de Fenomenologia de Interacciones Fundamentales                  *
 * http://gfif.udea.edu.co                                                *
 * División de ciencias de la computación Gfifdev                         *
 * http://gfifdev.udea.edu.co                                             *
 * Class Created and MaInt_tained By Omar Andres Zapata Mesa              *
 * All rights reserved.                                                   *
 *                                                                        *
 * some contributions Sigifredo Escobar 2010                            *
 * For the list of contributors see $ROOTSYS/README/CREDITS.              *
 *************************************************************************/

#include<Mpi/TComm.h>
#include <TMatrixD.h>
#include<Mpi/TDatatype.h>
#include<Mpi/TGroup.h>
#include <Mpi/TMpiMessage.h>
namespace ROOT {
   namespace Mpi {

      //______________________________________________________________________________
      template<> void TComm::SendObject(const TMpiMessage &obj, Int_t dest, Int_t tag)
      {
         Int_t size = obj.BufferSize();
         Char_t *buffer = obj.Buffer();
         Send(&size, 1, INT, dest, tag);
         Send(buffer, size, CHAR, dest, tag);
      }

      template<> void TComm::SendObject(const ROOT::Mpi::TMpiMessage *obj, Int_t count, Int_t dest, Int_t tag)
      {
         for (Int_t i = 0; i < count; i++) SendObject(obj[i], dest, tag);
      }

      //______________________________________________________________________________
      template<> void TComm::RecvObject(TMpiMessage &obj, Int_t source, Int_t tag)
      {
         Int_t size;
         Recv(&size, 1, INT, source, tag);
         Char_t *buffer = new Char_t[size];
         Recv(buffer, size, CHAR, source, tag);
         obj.SetBuffer(buffer, size, kFALSE);
         obj.SetReadMode();
         obj.Reset();
      }
      template<> void TComm::RecvObject(ROOT::Mpi::TMpiMessage *obj, Int_t count, Int_t source, Int_t tag)
      {
         for (Int_t i = 0; i < count; i++) RecvObject(obj[i], source, tag);
      }

      //______________________________________________________________________________
      template<> void TComm::BcastObject(ROOT::Mpi::TMpiMessage &obj, Int_t root)
      {
         Int_t size;
         if (Get_rank() == root) {
            size = obj.BufferSize();
         }
         Bcast(&size, 1, INT, root);
         Char_t *buffer = new Char_t[size];
         if (Get_rank() == root) {
            buffer = obj.Buffer();
         }
         Bcast(buffer, size, CHAR, root);
         if (Get_rank() != root) {
            obj.SetBuffer(buffer, size, kFALSE);
         }
         obj.SetReadMode();
         obj.Reset();
      }
      template<> void TComm::BcastObject(ROOT::Mpi::TMpiMessage *obj, Int_t count, Int_t root)
      {
         for (Int_t i = 0; i < count; i++) BcastObject(obj[i], root);
      }

      //______________________________________________________________________________
      template<> void TComm::GatherObject(const ROOT::Mpi::TMpiMessage &sendobj, ROOT::Mpi::TMpiMessage *recvobjs, Int_t root)
      {
         if (Get_rank() == root) {
            for (Int_t i = 0; i < Get_size(); i++) {
               if (i != root) {
                  RecvObject(recvobjs[i], i, ROOT::Mpi::TAG_UB);
                  recvobjs[i].SetReadMode();
                  recvobjs[i].Reset();
               }
            }
            recvobjs[root].SetBuffer(sendobj.Buffer(), sendobj.BufferSize(), kFALSE);
            recvobjs[root].SetReadMode();
            recvobjs[root].Reset();
         } else {
            SendObject(sendobj, root, ROOT::Mpi::TAG_UB);
         }
      }

      //______________________________________________________________________________
      template<> void TComm::ScatterObject(const ROOT::Mpi::TMpiMessage *sendobjs, ROOT::Mpi::TMpiMessage &recvobj, Int_t root)
      {
         if (Get_rank() == root) {
            for (Int_t i = 0; i < Get_size(); i++) {
               if (i != root) SendObject(sendobjs[i], i, root);
            }
            recvobj.SetBuffer(sendobjs[root].Buffer(), sendobjs[root].BufferSize(), kFALSE);
            recvobj.SetReadMode();
            recvobj.Reset();
         } else {
            RecvObject(recvobj, root, root);
         }
      }

      //______________________________________________________________________________
      template<> TRequest TComm::ISendObject(const ROOT::Mpi::TMpiMessage &obj, Int_t dest, Int_t tag)
      {
         Int_t size = obj.BufferSize();
         Char_t * buffer = obj.Buffer();
         TRequest req = Isend(&size, 1, ROOT::Mpi::INT, dest, tag);
         req = Isend(buffer, size, ROOT::Mpi::CHAR, dest, tag);
         return req;
      }

      //______________________________________________________________________________
      template<> TRequest TComm::ISsendObject(const ROOT::Mpi::TMpiMessage &obj, Int_t dest, Int_t tag)
      {
         Int_t size = obj.BufferSize();
         Char_t * buffer = obj.Buffer();
         TRequest req = Issend(&size, 1, ROOT::Mpi::INT, dest, tag);
         req = Issend(buffer, size, ROOT::Mpi::CHAR, dest, tag);
         return req;
      }

      //______________________________________________________________________________
      template<> TRequest TComm::IRsendObject(const ROOT::Mpi::TMpiMessage &obj, Int_t dest, Int_t tag)
      {
         Int_t size = obj.BufferSize();
         Char_t * buffer = obj.Buffer();
         TRequest req = Irsend(&size, 1, ROOT::Mpi::INT, dest, tag);
         req = Irsend(buffer, size, ROOT::Mpi::CHAR, dest, tag);
         return req;
      }

      //______________________________________________________________________________
      template<> TRequest TComm::IRecvObject(ROOT::Mpi::TMpiMessage &obj, Int_t source, Int_t tag)
      {
         Int_t size;
         TRequest req = Irecv(&size, 1, ROOT::Mpi::INT, source, tag);
         req.Wait();
         Char_t *buffer = new Char_t[size];
         req = Irecv(buffer, size, ROOT::Mpi::CHAR, source, tag);
         req.Wait();
         obj.SetBuffer(buffer, size, kFALSE);
         obj.SetReadMode();
         obj.Reset();
         return req;
      }

      //______________________________________________________________________________
      template<> void TComm::AllGatherObject(const ROOT::Mpi::TMpiMessage &sendobj, ROOT::Mpi::TMpiMessage *recvobjs)
      {
         for (Int_t i = 0; i < Get_size(); i++) GatherObject(sendobj, recvobjs, i);
      }

   }
}
