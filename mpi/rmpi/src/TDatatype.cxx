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

#include<Mpi/TDatatype.h>
#include<Mpi/TComm.h>
#include<mpi.h>


namespace ROOT {
   namespace Mpi {
      const ROOT::Mpi::TDatatype CHAR = MPI::CHAR;
      const ROOT::Mpi::TDatatype SHORT = MPI::SHORT;
      const ROOT::Mpi::TDatatype INT = MPI::INT;
      const ROOT::Mpi::TDatatype LONG = MPI::LONG;
      const ROOT::Mpi::TDatatype SIGNED_CHAR = MPI::SIGNED_CHAR;
      const ROOT::Mpi::TDatatype UNSIGNED_CHAR = MPI::UNSIGNED_CHAR;
      const ROOT::Mpi::TDatatype UNSIGNED_SHORT = MPI::UNSIGNED_SHORT;
      const ROOT::Mpi::TDatatype UNSIGNED = MPI::UNSIGNED;
      const ROOT::Mpi::TDatatype UNSIGNED_LONG = MPI::UNSIGNED_LONG;
      const ROOT::Mpi::TDatatype FLOAT = MPI::FLOAT;
      const ROOT::Mpi::TDatatype DOUBLE = MPI::DOUBLE;
      const ROOT::Mpi::TDatatype LONG_DOUBLE = MPI::LONG_DOUBLE;
      const ROOT::Mpi::TDatatype BYTE = MPI::BYTE;
      const ROOT::Mpi::TDatatype PACKED = MPI::PACKED;
      const ROOT::Mpi::TDatatype WCHAR = MPI::WCHAR;
   }
}


using namespace ROOT::Mpi;
ClassImp(TDatatype)

//______________________________________________________________________________
void TDatatype::Free()
{
   fDatatype.Free();
}

//______________________________________________________________________________
TDatatype::TDatatype() { }

//______________________________________________________________________________
TDatatype::TDatatype(const MPI_Datatype &dt)
{
   fDatatype = dt;
}

//______________________________________________________________________________
TDatatype::TDatatype(const MPI::Datatype& dt)
{
   fDatatype = dt;
}

//______________________________________________________________________________
TDatatype::TDatatype(const TDatatype& dt): TObject(dt)
{
   *this = dt;
}

//______________________________________________________________________________
TDatatype TDatatype::Create_contiguous(const Int_t count) const
{
   return fDatatype.Create_contiguous(count);
}

//______________________________________________________________________________
TDatatype TDatatype::Create_vector(Int_t count, Int_t blocklength, Int_t stride) const
{
   return fDatatype.Create_vector(count, blocklength, stride);
}

//______________________________________________________________________________
TDatatype TDatatype::Create_indexed(Int_t count, const Int_t array_of_blocklengths[], const Int_t array_of_displacements[]) const
{
   return fDatatype.Create_indexed(count, array_of_blocklengths, array_of_displacements);
}

//______________________________________________________________________________
TDatatype TDatatype::Create_struct(Int_t count, const Int_t array_of_blocklengths[], const Aint array_of_displacements[],
                                   const TDatatype array_of_types[])
{
   MPI::Datatype *array_of_types_core = new MPI::Datatype[count];
   for (int i = 0; i < count; i++) array_of_types_core[i] = array_of_types[i].fDatatype;

   return MPI::Datatype::Create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types_core);
}

//______________________________________________________________________________
TDatatype TDatatype::Create_hindexed(Int_t count, const Int_t array_of_blocklengths[], const Aint array_of_displacements[]) const
{
   return fDatatype.Create_hindexed(count, array_of_blocklengths, array_of_displacements);
}

//______________________________________________________________________________
TDatatype TDatatype::Create_hvector(Int_t count, Int_t blocklength, Aint stride) const
{
   return fDatatype.Create_hvector(count, blocklength, stride);
}

//______________________________________________________________________________
TDatatype TDatatype::Create_indexed_block(Int_t count, Int_t blocklength, const Int_t array_of_displacements[]) const
{
   return fDatatype.Create_indexed_block(count, blocklength, array_of_displacements);
}

//______________________________________________________________________________
TDatatype TDatatype::Create_resized(const Aint lb, const Aint extent) const
{
   return fDatatype.Create_resized(lb, extent);
}

//______________________________________________________________________________
Int_t TDatatype::Get_size() const
{
   return fDatatype.Get_size();
}

//______________________________________________________________________________
void TDatatype::Get_extent(Aint& lb, Aint& extent) const
{
   fDatatype.Get_extent(lb, extent);
}

//______________________________________________________________________________
void  TDatatype::Get_true_extent(Aint& lb, Aint& extent) const
{
   fDatatype.Get_true_extent(lb, extent);
}

//______________________________________________________________________________
void TDatatype::Commit()
{
   fDatatype.Commit();
}

//______________________________________________________________________________
void TDatatype::Pack(const void* inbuf, Int_t incount, void *outbuf, Int_t outsize,
                     Int_t& position, const TComm &comm) const
{
   fDatatype.Pack(inbuf, incount, outbuf, outsize, position, comm.fComm);
}

//______________________________________________________________________________
void TDatatype::Unpack(const void* inbuf, Int_t insize, void *outbuf, Int_t outcount, Int_t& position,
                       const TComm& comm) const
{
   fDatatype.Unpack(inbuf, insize, outbuf, outcount, position, comm.fComm);
}

//______________________________________________________________________________
Int_t TDatatype::Pack_size(Int_t incount, const TComm& comm) const
{
   return fDatatype.Pack_size(incount, comm.fComm);
}

//______________________________________________________________________________
TDatatype TDatatype::Create_subarray(Int_t ndims, const Int_t array_of_sizes[], const Int_t array_of_subsizes[],
                                     const Int_t array_of_starts[], Int_t order)const
{
   return fDatatype.Create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order);
}
//______________________________________________________________________________
TDatatype TDatatype::Dup() const
{
   return fDatatype.Dup();
}

//______________________________________________________________________________
Int_t TDatatype::Create_keyval(Copy_attr_function* type_copy_attr_fn, Delete_attr_function* type_delete_attr_fn, void* extra_state)
{
   return MPI::Datatype::Create_keyval(type_copy_attr_fn, type_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
Int_t TDatatype::Create_keyval(MPI_Type_copy_attr_function* type_copy_attr_fn, MPI_Type_delete_attr_function* type_delete_attr_fn, void* extra_state)
{
   return MPI::Datatype::Create_keyval(type_copy_attr_fn, type_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
Int_t TDatatype::Create_keyval(TDatatype::Copy_attr_function* type_copy_attr_fn, MPI_Type_delete_attr_function* type_delete_attr_fn, void* extra_state)
{
   return MPI::Datatype::Create_keyval(type_copy_attr_fn, type_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
Int_t TDatatype::Create_keyval(MPI_Type_copy_attr_function* type_copy_attr_fn, TDatatype::Delete_attr_function* type_delete_attr_fn, void* extra_state)
{
   return MPI::Datatype::Create_keyval(type_copy_attr_fn, type_delete_attr_fn, extra_state);
}

//______________________________________________________________________________
void TDatatype::Delete_attr(Int_t type_keyval)
{
   fDatatype.Delete_attr(type_keyval);
}

//______________________________________________________________________________
void TDatatype::Free_keyval(Int_t& type_keyval)
{
   MPI::Datatype::Free_keyval(type_keyval);
}

//______________________________________________________________________________
Bool_t TDatatype::Get_attr(Int_t type_keyval, void* attribute_val) const
{
   return fDatatype.Get_attr(type_keyval, attribute_val);
}

//______________________________________________________________________________
void TDatatype::Get_contents(Int_t max_integers, Int_t max_addresses, Int_t max_datatypes, Int_t array_of_integers[],
                             Aint array_of_addresses[], TDatatype array_of_datatypes[]) const
{
   MPI::Datatype *array_of_datatypes_core = new MPI::Datatype[max_datatypes];
   for (int i = 0; i < max_datatypes; i++) array_of_datatypes_core[i] = array_of_datatypes[i].fDatatype;
   fDatatype.Get_contents(max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes_core);
}

//______________________________________________________________________________
void TDatatype::Get_envelope(Int_t& num_integers, Int_t& num_addresses,
                             Int_t& num_datatypes, Int_t& combiner) const
{
   fDatatype.Get_envelope(num_integers, num_addresses, num_datatypes, combiner);
}

//______________________________________________________________________________
void TDatatype::Get_name(char* type_name, Int_t& resultlen) const
{
   fDatatype.Get_name(type_name, resultlen);
}

//______________________________________________________________________________
void TDatatype::Set_attr(Int_t type_keyval, const void* attribute_val)
{
   fDatatype.Set_attr(type_keyval, attribute_val);
}

//______________________________________________________________________________
void TDatatype::Set_name(const char* type_name)
{
   fDatatype.Set_name(type_name);
}
