/*************************************************************************
 * Copyright (C)2012,  Gfif Developers                                   *
 * Grupo de Fenomenologia de Interacciones Fundamentales                 *
 * http://gfif.udea.edu.co                                               *
 * División de ciencias de la computación Gfifdev                        *
 * http://gfifdev.udea.edu.co                                            *
 * Class Created and Maintained By Omar Andres Zapata Mesa               *
 * All rights reserved.                                                  *
 *                                                                       *
 *                                                                       *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#include<TWin.h>
#include<TInfo.h>
using namespace ROOT::Mpi;
ClassImp(TWin)

//
// Errhandler
//
//______________________________________________________________________________
TErrhandler TWin::Create_errhandler(Errhandler_function* function)
{
   return   MPI::Win::Create_errhandler(function);
}

//______________________________________________________________________________
TErrhandler TWin::Get_errhandler() const
{
   return fWin.Get_errhandler();
}

//______________________________________________________________________________
void TWin::Set_errhandler(const TErrhandler& errhandler) const
{
   fWin.Set_errhandler(errhandler);
}


//
// One sided communication
//
//______________________________________________________________________________
void TWin::Accumulate(const void* origin_addr, Int_t origin_count,
                      const TDatatype& origin_datatype,
                      Int_t target_rank, Aint target_disp,
                      Int_t target_count,
                      const TDatatype& target_datatype,
                      const TOp& op) const
{
   fWin.Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op.fOp);
}

//______________________________________________________________________________
void TWin::Complete() const
{
   fWin.Complete();
}

//______________________________________________________________________________
TWin TWin::Create(const void* base, Aint size, Int_t disp_unit, const TInfo& info, const TIntracomm& comm)
{
   return MPI::Win::Create(base, size, disp_unit, info.fInfo, comm.fComm);
}

//______________________________________________________________________________
void TWin::Fence(Int_t assert) const
{
   fWin.Fence(assert);
}

//______________________________________________________________________________
void TWin::Free()
{
   fWin.Free();
}

//______________________________________________________________________________
void TWin::Get(const void *origin_addr, Int_t origin_count,
               const TDatatype& origin_datatype, Int_t target_rank,
               Aint target_disp, Int_t target_count,
               const TDatatype& target_datatype) const
{
   fWin.Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype);
}

//______________________________________________________________________________
TGroup TWin::Get_group() const
{
   return  fWin.Get_group();
}

//______________________________________________________________________________
void TWin::Lock(Int_t lock_type, Int_t rank, Int_t assert) const
{
   fWin.Lock(lock_type, rank, assert);
}

//______________________________________________________________________________
void TWin::Post(const TGroup& group, Int_t assert) const
{
   fWin.Post(group.fGroup, assert);
}

//______________________________________________________________________________
void TWin::Put(const void* origin_addr, Int_t origin_count,
               const TDatatype& origin_datatype, Int_t target_rank,
               Aint target_disp, Int_t target_count,
               const TDatatype& target_datatype) const
{
   fWin.Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype);
}

//______________________________________________________________________________
void TWin::Start(const TGroup& group, Int_t assert) const
{
   fWin.Start(group.fGroup, assert);
}

//______________________________________________________________________________
Bool_t TWin::Test() const
{
   return fWin.Test();
}

//______________________________________________________________________________
void TWin::Unlock(Int_t rank) const
{
   fWin.Unlock(rank);
}

//______________________________________________________________________________
void TWin::Wait() const
{
   fWin.Wait();
}

//
// External Interfaces
//
//______________________________________________________________________________
void TWin::Call_errhandler(Int_t errorcode) const
{
   fWin.Call_errhandler(errorcode);
}

//______________________________________________________________________________
Int_t TWin::Create_keyval(Copy_attr_function* win_copy_attr_fn,
                          Delete_attr_function* win_delete_attr_fn,
                          void* extra_state)
{
   return MPI::Win::Create_keyval(win_copy_attr_fn, win_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
Int_t TWin::Create_keyval(MPI_Win_copy_attr_function* win_copy_attr_fn,
                          MPI_Win_delete_attr_function* win_delete_attr_fn,
                          void* extra_state)
{
   return MPI::Win::Create_keyval(win_copy_attr_fn, win_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
Int_t TWin::Create_keyval(Copy_attr_function* win_copy_attr_fn,
                          MPI_Win_delete_attr_function* win_delete_attr_fn,
                          void* extra_state)
{
   return MPI::Win::Create_keyval(win_copy_attr_fn, win_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
Int_t TWin::Create_keyval(MPI_Win_copy_attr_function* win_copy_attr_fn,
                          Delete_attr_function* win_delete_attr_fn,
                          void* extra_state)
{
   return MPI::Win::Create_keyval(win_copy_attr_fn, win_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
void TWin::Delete_attr(Int_t win_keyval)
{
   fWin.Delete_attr(win_keyval);
}

//______________________________________________________________________________
void TWin::Free_keyval(Int_t& win_keyval)
{
   MPI::Win::Free_keyval(win_keyval);
}

//______________________________________________________________________________
Bool_t TWin::Get_attr(const TWin& win, Int_t win_keyval, void* attribute_val) const
{
   return fWin.Get_attr(win.fWin, win_keyval, attribute_val);
}

//______________________________________________________________________________
Bool_t TWin::Get_attr(Int_t win_keyval, void* attribute_val) const
{
   return fWin.Get_attr(win_keyval, attribute_val);
}

//______________________________________________________________________________
void TWin::Get_name(Char_t* win_name, Int_t& resultlen) const
{
   fWin.Get_name(win_name, resultlen);
}

//______________________________________________________________________________
void TWin::Set_attr(Int_t win_keyval, const void* attribute_val)
{
   fWin.Set_attr(win_keyval, attribute_val);
}

//______________________________________________________________________________
void TWin::Set_name(const Char_t* win_name)
{
   fWin.Set_name(win_name);
}
