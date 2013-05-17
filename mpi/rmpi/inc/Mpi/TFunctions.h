/*************************************************************************
 * Copyright (C) 2012,  Gfif Developers                                   *
 * Grupo de Fenomenologia de Interacciones Fundamentales                  *
 * http://gfif.udea.edu.co                                                *
 * División de ciencias de la computación Gfifdev                         *
 * http://gfifdev.udea.edu.co                                             *
 * Class Created and MaInt_tained By Omar Andres Zapata Mesa                *
 * All rights reserved.                                                   *
 *                                                                        *
 *                                                                        *
 * For the list of contributors see $ROOTSYS/README/CREDITS.              *
 *************************************************************************/

#ifndef ROOT_Mpi_TFunctions
#define ROOT_Mpi_TFunctions

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#include<TInfo.h>
#include<MTypes.h>

namespace ROOT {

   namespace Mpi {
      void Attach_buffer(void* buffer, Int_t size);

      Int_t Detach_buffer(void*& buffer);

      //
      // Process Topologies
      //

      void Compute_dims(Int_t nnodes, Int_t ndims, Int_t dims[]);

      //
      // Environmental Inquiry
      //

      Int_t Add_error_class();

      Int_t Add_error_code(Int_t errorclass);

      void Add_error_string(Int_t errorcode, const Char_t* string);

      void Get_processor_name(Char_t* name, Int_t& resultlen);

      void Get_error_string(Int_t errorcode, Char_t* string, Int_t& resultlen);

      Int_t Get_error_class(Int_t errorcode);

      Double_t Wtime();

      Double_t Wtick();
    
      void Init(int& argc, char**& argv);

      void Init();
      
      void InitializeIntercepts();

      void Real_init();
      
      void Finalize();

      Bool_t Is_initialized();

      Bool_t Is_finalized();

      //
      // External Interfaces
      //

      Int_t Init_thread(Int_t &argc, Char_t**&argv, Int_t required);

      Int_t Init_thread(Int_t required);

      Bool_t Is_thread_main();

      Int_t Query_thread();


      //
      // Miscellany
      //


      void* Alloc_mem(Aint size, const TInfo& info);


      void Free_mem(void* base);

      //
      // Process Creation
      //

      void Close_port(const Char_t* port_name);


      void Lookup_name(const Char_t* service_name, const TInfo& info, Char_t* port_name);


      void Open_port(const TInfo& info, Char_t* port_name);


      void Publish_name(const Char_t* service_name, const TInfo& info, const Char_t* port_name);

      void Unpublish_name(const Char_t* service_name, const TInfo& info, const Char_t* port_name);

      //
      // Profiling
      //

      void Pcontrol(const Int_t level, ...);

      // void Get_version(Int_t& version, Int_t& subversion);

      Aint Get_address(void* location);
   }
}
#endif
