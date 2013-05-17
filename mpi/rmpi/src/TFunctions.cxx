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
//NOTE:based in functions.h from OpenMpi, see CREDITS!
//several modifications to support CINT

#include<Mpi/TFunctions.h>
#include <string.h>
#include<mpi.h>

// using namespace ROOT::Mpi;
namespace ROOT {
   namespace Mpi {
      //______________________________________________________________________________
      void Attach_buffer(void* buffer, Int_t size)
      {
         (void)MPI_Buffer_attach(buffer, size);
      }

      //______________________________________________________________________________
      Int_t Detach_buffer(void*& buffer)
      {
         Int_t size;
         (void)MPI_Buffer_detach(&buffer, &size);
         return size;
      }

      //______________________________________________________________________________
      void Compute_dims(Int_t nnodes, Int_t ndims, Int_t dims[])
      {
         (void)MPI_Dims_create(nnodes, ndims, dims);
      }

      //______________________________________________________________________________
      Int_t Add_error_class()
      {
         Int_t errcls;
         (void)MPI_Add_error_class(&errcls);
         return errcls;
      }

      //______________________________________________________________________________
      Int_t Add_error_code(Int_t errorclass)
      {
         Int_t errcode;
         (void)MPI_Add_error_code(errorclass, &errcode);
         return errcode;
      }

      //______________________________________________________________________________
      void Add_error_string(Int_t errorcode, const Char_t* string)
      {
         (void)MPI_Add_error_string(errorcode, const_cast<Char_t *>(string));
      }

      //______________________________________________________________________________
      void Get_processor_name(Char_t* name, Int_t& resultlen)
      {
         (void)MPI_Get_processor_name(name, &resultlen);
      }

      //______________________________________________________________________________
      void Get_error_string(Int_t errorcode, Char_t* string, Int_t& resultlen)
      {
         (void)MPI_Error_string(errorcode, string, &resultlen);
      }

      //______________________________________________________________________________
      Int_t Get_error_class(Int_t errorcode)
      {
         Int_t errorclass;
         (void)MPI_Error_class(errorcode, &errorclass);
         return errorclass;
      }

      //______________________________________________________________________________
      Double_t Wtime()
      {
         return (MPI_Wtime());
      }

      //______________________________________________________________________________
      Double_t Wtick()
      {
         return (MPI_Wtick());
      }
      
      //______________________________________________________________________________
      void Real_init()
      {
	    MPI::Real_init();
       }


      //______________________________________________________________________________
      void Init(int& argc, char**& argv)
      {
	MPI::Init(argc,argv);
      }

      //______________________________________________________________________________
      void Init()
      {
	MPI::Init();
       }

      //______________________________________________________________________________
      void InitializeIntercepts()
      {
	MPI::InitializeIntercepts();
      }

      //______________________________________________________________________________
      Bool_t Is_initialized()
      {
         Int_t t;
         (void)MPI_Initialized(&t);
         return (Bool_t)(t);
      }
      
      //______________________________________________________________________________
       void Finalize()
       {
	(void)MPI_Finalize(); 
       }

      //______________________________________________________________________________
      Bool_t Is_finalized()
      {
         Int_t t;
         (void)MPI_Finalized(&t);
         return Bool_t(t);
      }

      //______________________________________________________________________________
      Int_t Init_thread(Int_t required)
      {
         Int_t provided;
         (void) MPI_Init_thread(0, NULL, required, &provided);
         MPI::Real_init();
         return provided;
      }

      //______________________________________________________________________________
      Int_t Init_thread(Int_t& argc, Char_t**& argv, Int_t required)
      {
         Int_t provided;
         (void) MPI_Init_thread(&argc, &argv, required, &provided);
         MPI::Real_init();
         return provided;
      }


      //______________________________________________________________________________
      Bool_t Is_thread_main()
      {
         Int_t flag;
         (void) MPI_Is_thread_main(&flag);
         return (Bool_t)(flag == 1);
      }


      //______________________________________________________________________________
      Int_t Query_thread()
      {
         Int_t provided;
         (void) MPI_Query_thread(&provided);
         return provided;
      }

      //______________________________________________________________________________
      void* Alloc_mem(Aint size, const TInfo& info)
      {
         void* baseptr;
         (void) MPI_Alloc_mem(size, info.Dup(), &baseptr);
         return baseptr;
      }


      //______________________________________________________________________________
      void Free_mem(void* base)
      {
         (void) MPI_Free_mem(base);
      }

      //______________________________________________________________________________
      void Close_port(const Char_t* port_name)
      {
         (void) MPI_Close_port(const_cast<Char_t *>(port_name));
      }


      //______________________________________________________________________________
      void Lookup_name(const Char_t * service_name, const TInfo& info, Char_t* port_name)
      {
         (void) MPI_Lookup_name(const_cast<Char_t *>(service_name), info.Dup(), port_name);
      }


      //______________________________________________________________________________
      void Open_port(const TInfo& info, Char_t* port_name)
      {
         (void) MPI_Open_port(info.Dup(), port_name);
      }


      //______________________________________________________________________________
      void Publish_name(const Char_t* service_name, const TInfo& info, const Char_t* port_name)
      {
         (void) MPI_Publish_name(const_cast<Char_t *>(service_name), info.Dup(),
                                 const_cast<Char_t *>(port_name));
      }


      //______________________________________________________________________________
      void Unpublish_name(const Char_t* service_name, const TInfo& info, const Char_t* port_name)
      {
         (void)MPI_Unpublish_name(const_cast<Char_t *>(service_name), info.Dup(),
                                  const_cast<Char_t *>(port_name));
      }

      //______________________________________________________________________________
      void Pcontrol(const Int_t level, ...)
      {
         va_list ap;
         va_start(ap, level);

         (void)MPI_Pcontrol(level, ap);
         va_end(ap);
      }


      //______________________________________________________________________________
      Aint Get_address(void* location)
      {
         Aint ret;
         MPI_Get_address(location, &ret);
         return ret;
      }

   }
}
