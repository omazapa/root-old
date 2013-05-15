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
#ifndef ROOT_Mpi_TDatatype
#define ROOT_Mpi_TDatatype
#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#include<TObject.h>

#ifdef __CINT__
namespace MPI {
   class Datatype;
}
struct  MPI_Datatype;
typedef int (MPI_Type_copy_attr_function)(MPI_Datatype, int, void *, void *, void *, int *);
typedef int (MPI_Type_delete_attr_function)(MPI_Datatype, int, void *, void *);
#else
#include<mpi.h>
#include<Mpi/MTypes.h>
#endif
namespace ROOT {
   namespace Mpi {
      class TComm;
      class TStatus;
      class TDatatype : public TObject {
         friend class ROOT::Mpi::TStatus;
         friend class ROOT::Mpi::TFile;
         friend class ROOT::Mpi::TComm;
      protected:
         MPI::Datatype fDatatype;
      public:
         TDatatype();
         TDatatype(const MPI::Datatype& dt);
         TDatatype(const TDatatype& dt);
         TDatatype(const MPI_Datatype &data);
         inline virtual ~TDatatype() {}

         inline TDatatype& operator=(const TDatatype& dt) {
            fDatatype = dt.fDatatype;
            return *this;
         }


         inline Bool_t operator== (const TDatatype &a) const {
            return (Bool_t)(fDatatype == a.fDatatype);
         }

         inline Bool_t operator!= (const TDatatype &a) const {
            return (Bool_t) !(*this == a);
         }

         inline TDatatype& operator= (const MPI_Datatype &dt) {
            fDatatype = dt;
            return *this;
         }

         inline TDatatype& operator= (const MPI::Datatype &dt) {
            fDatatype = dt;
            return *this;
         }

         inline operator MPI_Datatype() const {
            return (MPI_Datatype)fDatatype;
         }

         inline operator MPI::Datatype() const {
            return fDatatype;
         }

         inline operator TDatatype() const {
            return *this;
         }

         typedef Int_t Copy_attr_function(const MPI::Datatype& oldtype, Int_t type_keyval, void* extra_state,
                                          const void* attribute_val_in, void* attribute_val_out, Bool_t& flag);

         typedef Int_t Delete_attr_function(MPI::Datatype& type, Int_t type_keyval, void* attribute_val, void* extra_state);
         TDatatype Create_contiguous(Int_t count) const;

         TDatatype Create_vector(Int_t count, Int_t blocklength, Int_t stride) const;

         TDatatype  Create_indexed(Int_t count, const Int_t array_of_blocklengths[], const Int_t array_of_displacements[]) const;

         static TDatatype Create_struct(Int_t count, const Int_t array_of_blocklengths[], const Aint array_of_displacements[],
                                        const TDatatype array_if_types[]);

         TDatatype Create_hindexed(Int_t count, const Int_t array_of_blocklengths[], const Aint array_of_displacements[]) const;

         TDatatype Create_hvector(Int_t count, Int_t blocklength, Aint stride) const;

         TDatatype Create_indexed_block(Int_t count, Int_t blocklength, const Int_t array_of_blocklengths[]) const;

         TDatatype Create_resized(const Aint lb, const Aint extent) const;

         virtual Int_t Get_size() const;

         virtual void Get_extent(Aint& lb, Aint& extent) const;

         virtual void Get_true_extent(Aint&, Aint&) const;

         virtual void Commit();

         virtual void Free();

         virtual void Pack(const void* inbuf, Int_t incount, void *outbuf,
                           Int_t outsize, Int_t& position, const TComm &comm) const;

         virtual void Unpack(const void* inbuf, Int_t insize, void *outbuf, Int_t outcount,
                             Int_t& position, const TComm& comm) const;

         virtual Int_t Pack_size(Int_t incount, const TComm& comm) const;

         TDatatype Create_subarray(Int_t ndims, const Int_t array_of_sizes[], const Int_t array_of_subsizes[],
                                   const Int_t array_of_starts[], Int_t order)const;

         TDatatype Dup() const;

         static Int_t Create_keyval(Copy_attr_function* type_copy_attr_fn,
                                    Delete_attr_function* type_delete_attr_fn,
                                    void* extra_state);
         static Int_t Create_keyval(MPI_Type_copy_attr_function* type_copy_attr_fn,
                                    MPI_Type_delete_attr_function* type_delete_attr_fn,
                                    void* extra_state);
         static Int_t Create_keyval(Copy_attr_function* type_copy_attr_fn,
                                    MPI_Type_delete_attr_function* type_delete_attr_fn,
                                    void* extra_state);
         static Int_t Create_keyval(MPI_Type_copy_attr_function* type_copy_attr_fn,
                                    Delete_attr_function* type_delete_attr_fn,
                                    void* extra_state);

         virtual void Delete_attr(Int_t type_keyval);

         static void Free_keyval(Int_t& type_keyval);

         virtual Bool_t Get_attr(Int_t type_keyval, void* attribute_val) const;

         virtual void Get_contents(Int_t max_integers, Int_t max_addresses,
                                   Int_t max_datatypes, Int_t array_of_integers[],
                                   Aint array_of_addresses[],
                                   TDatatype array_of_datatypes[]) const;

         virtual void Get_envelope(Int_t& num_integers, Int_t& num_addresses,
                                   Int_t& num_datatypes, Int_t& combiner) const;

         virtual void Get_name(Char_t* type_name, Int_t& resultlen) const;

         virtual void Set_attr(Int_t type_keyval, const void* attribute_val);

         virtual void Set_name(const Char_t* type_name);

         ClassDef(TDatatype, 1) //
      };

      R__EXTERN const ROOT::Mpi::TDatatype CHAR;
      R__EXTERN const ROOT::Mpi::TDatatype SHORT;
      R__EXTERN const ROOT::Mpi::TDatatype INT;
      R__EXTERN const ROOT::Mpi::TDatatype LONG;
      R__EXTERN const ROOT::Mpi::TDatatype SIGNED_CHAR;
      R__EXTERN const ROOT::Mpi::TDatatype UNSIGNED_CHAR;
      R__EXTERN const ROOT::Mpi::TDatatype UNSIGNED_SHORT;
      R__EXTERN const ROOT::Mpi::TDatatype UNSIGNED;
      R__EXTERN const ROOT::Mpi::TDatatype UNSIGNED_LONG;
      R__EXTERN const ROOT::Mpi::TDatatype FLOAT;
      R__EXTERN const ROOT::Mpi::TDatatype DOUBLE;
      R__EXTERN const ROOT::Mpi::TDatatype LONG_DOUBLE;
      R__EXTERN const ROOT::Mpi::TDatatype BYTE;
      R__EXTERN const ROOT::Mpi::TDatatype PACKED;
      R__EXTERN const ROOT::Mpi::TDatatype WCHAR;

   }
}
#endif
