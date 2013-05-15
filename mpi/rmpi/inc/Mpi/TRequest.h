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

#ifndef ROOT_Mpi_TRequest
#define ROOT_Mpi_TRequest

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif

#ifdef __CINT__
namespace MPI {
   class Request;
   class Prequest;
   class Grequest;
   class Status;
}
struct MPI_Request;
#else
#include<mpi.h>
#include<Mpi/TStatus.h>
#endif
namespace ROOT {
   namespace Mpi {
      class TStatus;
      class TRequest: public MPI::Request {
      public:
         using MPI::Request::Wait;
         using MPI::Request::Test;
         using MPI::Request::Get_status;
         TRequest();
         virtual ~TRequest() {}
         TRequest(MPI_Request i);
         TRequest(const MPI::Request& r);

         TRequest& operator=(const TRequest& r);

         Bool_t operator== (const TRequest &a);
         Bool_t operator!= (const TRequest &a);

         TRequest& operator= (const MPI_Request &i);
         operator MPI_Request() const {
            return mpi_request;
         }

         virtual void Wait(TStatus &status);

         virtual void Wait();

         virtual Bool_t Test(TStatus &status);

         virtual Bool_t Test();

         virtual void Free(void);

         static Int_t Waitany(Int_t count, TRequest array[], TStatus& status);

         static Int_t Waitany(Int_t count, TRequest array[]);

         static Bool_t Testany(Int_t count, TRequest array[], Int_t& index, TStatus& status);

         static Bool_t Testany(Int_t count, TRequest array[], Int_t& index);

         static void Waitall(Int_t count, TRequest req_array[], TStatus stat_array[]);

         static void Waitall(Int_t count, TRequest req_array[]);

         static Bool_t Testall(Int_t count, TRequest req_array[], TStatus stat_array[]);

         static Bool_t Testall(Int_t count, TRequest req_array[]);

         static Int_t Waitsome(Int_t incount, TRequest req_array[], Int_t array_of_indices[], TStatus stat_array[]) ;

         static Int_t Waitsome(Int_t incount, TRequest req_array[], Int_t array_of_indices[]);

         static Int_t Testsome(Int_t incount, TRequest req_array[], Int_t array_of_indices[], TStatus stat_array[]);

         static Int_t Testsome(Int_t incount, TRequest req_array[], Int_t array_of_indices[]);

         virtual void Cancel(void) const;

         virtual Bool_t Get_status(TStatus& status) const;

         virtual Bool_t Get_status() const;

         operator MPI::Request() const {
            return mpi_request;
         }
         ClassDef(TRequest, 1)
      };

      class TPrequest: public TRequest {
      public:
         TPrequest() { }
         TPrequest(const TRequest& p) : TRequest(p) { }
         TPrequest(const MPI::Request& p) : TRequest(p) { }
         TPrequest(const MPI_Request &i) : TRequest(i) { }
         virtual ~TPrequest() { }

         TPrequest& operator=(const TRequest& r) {
            mpi_request = r;
            return *this;
         }
         TPrequest& operator=(const TPrequest& r) {
            mpi_request = r.mpi_request;
            return *this;
         }

         TPrequest& operator=(const MPI::Prequest& r) {
            mpi_request = (MPI_Request)r;
            return *this;
         }

         virtual void Start();
         static void Startall(int count, TPrequest array_of_requests[]);

         ClassDef(TPrequest, 2)
      };

      class TGrequest: public TRequest {
      public:
         typedef Int_t Query_function(void *, TStatus&);
         typedef Int_t Free_function(void *);
         typedef Int_t Cancel_function(void *, Bool_t);

         TGrequest() {}
         TGrequest(const TRequest& req) : TRequest(req) {}
         TGrequest(const MPI_Request &req) : TRequest(req) {}
         virtual ~TGrequest() {}

         TGrequest& operator=(const TRequest& req) {
            mpi_request = req;
            return(*this);
         }

         TGrequest& operator=(const TGrequest& req) {
            mpi_request = req.mpi_request;
            return(*this);
         }

         static TGrequest Start(Query_function *, Free_function *, Cancel_function *, void *);

         virtual void Complete();
         //
         // Type used for intercepting Generalized requests in the C++ layer so
         // that the type can be converted to C++ types before invoking the
         // user-specified C++ callbacks.
         //
         struct Intercept_data_t {
            void *id_extra;
            TGrequest::Query_function *id_cxx_query_fn;
            TGrequest::Free_function *id_cxx_free_fn;
            TGrequest::Cancel_function *id_cxx_cancel_fn;
         };

         ClassDef(TGrequest, 2)
      };
   }//end namespace Mpi
}//end namespace ROOT


#endif
