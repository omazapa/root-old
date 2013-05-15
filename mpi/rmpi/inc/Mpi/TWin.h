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
#ifndef ROOT_Mpi_TWin
#define ROOT_Mpi_TWin
#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#include<TObject.h>
#ifdef __CINT__
namespace MPI {
   class Win;
}
struct MPI_Win;
typedef int (MPI_Win_copy_attr_function)(MPI_Win, int, void *, void *, void *, int *);
typedef int (MPI_Win_delete_attr_function)(MPI_Win, int, void *, void *);
typedef void Errhandler_function(MPI::Win &, Int_t *, ...);

#else
#include<mpi.h>
#include<Mpi/TIntracomm.h>

#endif
namespace ROOT {
   namespace Mpi {
      class TErrhandler;//defined here for CINT
      class TOp;
      class TWin: public TObject {
         friend class TComm;
         friend class TRequest;
      protected:
         MPI::Win fWin;
      public:

         TWin() {};
         TWin(const MPI::Win& win) {
            fWin = win;
         }
         TWin(const MPI_Win &win) {
            fWin = win;
         }
         TWin(const TWin& win): TObject(win) {};

         virtual ~TWin() { }

         TWin& operator=(const MPI::Win& data) {
            fWin = data;
            return *this;
         }

         TWin& operator=(const TWin& data) {
            fWin = data.fWin;
            return *this;
         }

         TWin& operator= (const MPI_Win &i) {
            fWin = i;
            return *this;
         }

         operator MPI_Win() const {
            return (MPI_Win)fWin;
         }

         //
         // User defined functions
         //
         typedef Int_t Copy_attr_function(const MPI::Win& oldwin, Int_t win_keyval,
                                          void* extra_state, void* attribute_val_in,
                                          void* attribute_val_out, Bool_t& flag);

         typedef Int_t Delete_attr_function(MPI::Win& win, Int_t win_keyval,
                                            void* attribute_val, void* extra_state);

         typedef void Errhandler_function(MPI::Win &, Int_t *, ...);

         //
         // Errhandler
         //
         static ROOT::Mpi::TErrhandler Create_errhandler(Errhandler_function* function);

         virtual void Set_errhandler(const TErrhandler& errhandler) const;

         ROOT::Mpi::TErrhandler Get_errhandler() const;

         //
         // One sided communication
         //
         virtual void Accumulate(const void* origin_addr, Int_t origin_count,
                                 const TDatatype& origin_datatype,
                                 Int_t target_rank, Aint target_disp,
                                 Int_t target_count,
                                 const TDatatype& target_datatype,
                                 const TOp& op) const;

         virtual void Complete() const;

         static  ROOT::Mpi::TWin Create(const void* base, Aint size, Int_t disp_unit, const TInfo& info, const TIntracomm& comm);

         virtual void Fence(Int_t assert) const;

         virtual void Free();

         virtual void Get(const void *origin_addr, Int_t origin_count,
                          const TDatatype& origin_datatype, Int_t target_rank,
                          Aint target_disp, Int_t target_count,
                          const TDatatype& target_datatype) const;

         ROOT::Mpi::TGroup Get_group() const;

         virtual void Lock(Int_t lock_type, Int_t rank, Int_t assert) const;

         virtual void Post(const TGroup& group, Int_t assert) const;

         virtual void Put(const void* origin_addr, Int_t origin_count,
                          const TDatatype& origin_datatype, Int_t target_rank,
                          Aint target_disp, Int_t target_count,
                          const TDatatype& target_datatype) const;

         virtual void Start(const TGroup& group, Int_t assert) const;

         virtual Bool_t Test() const;

         virtual void Unlock(Int_t rank) const;

         virtual void Wait() const;

         //
         // External Interfaces
         //
         virtual void Call_errhandler(Int_t errorcode) const;

         // Need 4 overloaded versions of this function because per the
         // MPI-2 spec, you can mix-n-match the C predefined functions with
         // C++ functions.
         static Int_t Create_keyval(Copy_attr_function* win_copy_attr_fn,
                                    Delete_attr_function* win_delete_attr_fn,
                                    void* extra_state);
         static Int_t Create_keyval(MPI_Win_copy_attr_function* win_copy_attr_fn,
                                    MPI_Win_delete_attr_function* win_delete_attr_fn,
                                    void* extra_state);
         static Int_t Create_keyval(Copy_attr_function* win_copy_attr_fn,
                                    MPI_Win_delete_attr_function* win_delete_attr_fn,
                                    void* extra_state);
         static Int_t Create_keyval(MPI_Win_copy_attr_function* win_copy_attr_fn,
                                    Delete_attr_function* win_delete_attr_fn,
                                    void* extra_state);

         virtual void Delete_attr(Int_t win_keyval);

         static void Free_keyval(Int_t& win_keyval);

         Bool_t Get_attr(const TWin& win, Int_t win_keyval, void* attribute_val) const;

         Bool_t Get_attr(Int_t win_keyval, void* attribute_val) const;

         virtual void Get_name(Char_t* win_name, Int_t& resultlen) const;

         virtual void Set_attr(Int_t win_keyval, const void* attribute_val);

         virtual void Set_name(const Char_t* win_name);


         ClassDef(TWin, 0)
      };
   }
}
#endif
