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
#include<TRequest.h>
#include<mpi.h>


using namespace ROOT::Mpi;
ClassImp(TRequest)
//______________________________________________________________________________
TRequest::TRequest(): Request() {}

//______________________________________________________________________________
TRequest::TRequest(MPI_Request i) : Request(i) { }

//______________________________________________________________________________
TRequest::TRequest(const MPI::Request& r) : Request(r) { }

//______________________________________________________________________________
TRequest& TRequest::operator=(const TRequest& r)
{
   mpi_request = r.mpi_request;
   return *this;
}

//______________________________________________________________________________
Bool_t TRequest::operator== (const TRequest &a)
{
   return (Bool_t)(mpi_request == a.mpi_request);
}

//______________________________________________________________________________
Bool_t TRequest::operator!= (const TRequest &a)
{
   return (Bool_t)!(*this == a);
}

//______________________________________________________________________________
TRequest& TRequest::operator= (const MPI_Request &i)
{
   mpi_request = i;
   return *this;
}

//______________________________________________________________________________
void TRequest::Wait(TStatus &status)
{
   Request::Wait(status);
}

//______________________________________________________________________________
void TRequest::Wait()
{
   Request::Wait();
}

//______________________________________________________________________________
Bool_t TRequest::Test(TStatus &status)
{
   return Request::Test(status);
}

//______________________________________________________________________________
Bool_t TRequest::Test()
{
   return Request::Test();
}

//______________________________________________________________________________
void TRequest::Free(void)
{
   Request::Free();
}

//______________________________________________________________________________
Int_t TRequest::Waitany(Int_t count, TRequest array[], TStatus& status)
{
   return Request::Waitany(count, array, status);
}

//______________________________________________________________________________
Int_t TRequest::Waitany(Int_t count, TRequest array[])
{
   return Request::Waitany(count, array);

}

//______________________________________________________________________________
Bool_t TRequest::Testany(Int_t count, TRequest array[], Int_t& index, TStatus& status)
{
   return Request::Testany(count, array, index, status);
}

//______________________________________________________________________________
Bool_t TRequest::Testany(Int_t count, TRequest array[], Int_t& index)
{
   return Request::Testany(count, array, index);
}

//______________________________________________________________________________
void TRequest::Waitall(Int_t count, TRequest req_array[], TStatus stat_array[])
{
   Request::Waitall(count, req_array, stat_array);
}

//______________________________________________________________________________
void TRequest::Waitall(Int_t count, TRequest req_array[])
{
   Request::Waitall(count, req_array);
}

//______________________________________________________________________________
Bool_t TRequest::Testall(Int_t count, TRequest req_array[], TStatus stat_array[])
{
   return Request::Testall(count, req_array, stat_array);
}

//______________________________________________________________________________
Bool_t TRequest::Testall(Int_t count, TRequest req_array[])
{
   return Request::Testall(count, req_array);
}

//______________________________________________________________________________
Int_t TRequest::Waitsome(Int_t incount, TRequest req_array[], Int_t array_of_indices[], TStatus stat_array[])
{
   return Request::Waitsome(incount, req_array, array_of_indices, stat_array);
}

//______________________________________________________________________________
Int_t TRequest::Waitsome(Int_t incount, TRequest req_array[], Int_t array_of_indices[])
{
   return Request::Waitsome(incount, req_array, array_of_indices);
}

//______________________________________________________________________________
Int_t TRequest::Testsome(Int_t incount, TRequest req_array[], Int_t array_of_indices[], TStatus stat_array[])
{
   return Request::Testsome(incount, req_array, array_of_indices, stat_array);
}

//______________________________________________________________________________
Int_t TRequest::Testsome(Int_t incount, TRequest req_array[], Int_t array_of_indices[])
{
   return Request::Testsome(incount, req_array, array_of_indices);
}

//______________________________________________________________________________
void TRequest::Cancel(void) const
{
   Request::Cancel();
}

//______________________________________________________________________________
Bool_t TRequest::Get_status(TStatus& status) const
{
   return Request::Get_status(status);
}

//______________________________________________________________________________
Bool_t TRequest::Get_status() const
{
   return Request::Get_status();
}


ClassImp(TPrequest)

//______________________________________________________________________________
void TPrequest::Start()
{
   (void)MPI_Start(&mpi_request);
}

//______________________________________________________________________________
void TPrequest::Startall(int count, TPrequest array_of_requests[])
{
   MPI_Request* mpi_requests = new MPI_Request[count];
   int i;
   for (i = 0; i < count; i++) {
      mpi_requests[i] = array_of_requests[i];
   }
   (void)MPI_Startall(count, mpi_requests);
   for (i = 0; i < count; i++) {
      array_of_requests[i].mpi_request = mpi_requests[i] ;
   }
   delete [] mpi_requests;
}

ClassImp(TGrequest)
//______________________________________________________________________________
TGrequest TGrequest::Start(Query_function *query_fn, Free_function *free_fn, Cancel_function *cancel_fn, void *extra)
{
   MPI_Request grequest = 0;
   Intercept_data_t *new_extra = new TGrequest::Intercept_data_t;

   new_extra->id_extra = extra;
   new_extra->id_cxx_query_fn = query_fn;
   new_extra->id_cxx_free_fn = free_fn;
   new_extra->id_cxx_cancel_fn = cancel_fn;
   (void) MPI_Grequest_start(ompi_mpi_cxx_grequest_query_fn_intercept,
                             ompi_mpi_cxx_grequest_free_fn_intercept,
                             ompi_mpi_cxx_grequest_cancel_fn_intercept,
                             new_extra, &grequest);

   return(grequest);
}

//______________________________________________________________________________
void TGrequest::Complete()
{
   (void) MPI_Grequest_complete(mpi_request);
}
