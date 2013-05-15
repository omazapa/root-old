/*************************************************************************
* Copyright (C) 2012 Gfif Developers                                     *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* http://gfifdev.udea.edu.co                                             *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
*                                                                        *
* For the list of contributors see /README/CREDITS.                      *
*************************************************************************/
#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

#pragma link C++ namespace ROOT;
#pragma link C++ namespace ROOT::Mpi;

#pragma link C++ function ROOT::Mpi::Attach_buffer(void*, Int_t);
#pragma link C++ function ROOT::Mpi::Detach_buffer(void*& );
#pragma link C++ function ROOT::Mpi::Compute_dims(Int_t , Int_t , Int_t*);
#pragma link C++ function ROOT::Mpi::Add_error_class();
#pragma link C++ function ROOT::Mpi::Add_error_code(Int_t );
#pragma link C++ function ROOT::Mpi::Add_error_string(Int_t , const Char_t* );
#pragma link C++ function ROOT::Mpi::Get_processor_name(Char_t* , Int_t& );
#pragma link C++ function ROOT::Mpi::Get_error_string(Int_t , Char_t* , Int_t& );
#pragma link C++ function ROOT::Mpi::Get_error_class(Int_t);
#pragma link C++ function ROOT::Mpi::Wtime();
#pragma link C++ function ROOT::Mpi::Wtick();
#pragma link C++ function ROOT::Mpi::Is_initialized();
#pragma link C++ function ROOT::Mpi::Is_finalized();
#pragma link C++ function ROOT::Mpi::Init_thread(Int_t &, Char_t**&, Int_t);
#pragma link C++ function ROOT::Mpi::Init_thread(Int_t );
#pragma link C++ function ROOT::Mpi::Is_thread_main();
#pragma link C++ function ROOT::Mpi::Query_thread();
#pragma link C++ function ROOT::Mpi::Alloc_mem(Aint , const ROOT::Mpi::TInfo& );
#pragma link C++ function ROOT::Mpi::Free_mem(void* );
#pragma link C++ function ROOT::Mpi::Close_port(const Char_t* );
#pragma link C++ function ROOT::Mpi::Lookup_name(const Char_t* , const ROOT::Mpi::TInfo& , Char_t* );
#pragma link C++ function ROOT::Mpi::Open_port(const TInfo& , Char_t* );
#pragma link C++ function ROOT::Mpi::Publish_name(const Char_t*,const ROOT::Mpi::TInfo&,const Char_t* );
#pragma link C++ function ROOT::Mpi::Unpublish_name(const Char_t*,const ROOT::Mpi::TInfo&,const Char_t* );
#pragma link C++ function ROOT::Mpi::Pcontrol(const Int_t , ...);
#pragma link C++ function ROOT::Mpi::Get_address(void* );
#endif
