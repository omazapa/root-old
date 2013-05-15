/*************************************************************************
* Copyright (C) 2010-2012,  Gfif Developers                              *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* http://gfifdev.udea.edu.co                                             *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* and Sigifredo Escobar Gomez                                            *
* All rights reserved.                                                   *
*                                                                        *
*                                                                        *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
*************************************************************************/

#include<Mpi/TFile.h>
#include <TInfo.h>

using namespace ROOT::Mpi;

ClassImp(TFile)

// from the I/o chapter of MPI - 2

//______________________________________________________________________________
void TFile::Delete(const Char_t* filename, const TInfo& info)
{
   MPI::File::Delete(filename, info.fInfo);
}

//______________________________________________________________________________
Int_t TFile::Get_amode() const
{
   return fFile.Get_amode();
}

//______________________________________________________________________________
Bool_t TFile::Get_atomicity() const
{
   return fFile.Get_atomicity();
}

//______________________________________________________________________________
Offset TFile::Get_byte_offset(const Offset disp) const
{
   return fFile.Get_byte_offset(disp);
}

//______________________________________________________________________________
TGroup TFile::Get_group() const
{
   return fFile.Get_group();
}

//______________________________________________________________________________
TInfo TFile::Get_info() const
{
   return fFile.Get_info();
}

//______________________________________________________________________________
Offset TFile::Get_position() const
{
   return fFile.Get_position();
}

//______________________________________________________________________________
Offset TFile::Get_position_shared() const
{
   return fFile.Get_position_shared();
}

//______________________________________________________________________________
Offset TFile::Get_size() const
{
   return fFile.Get_size();
}

//______________________________________________________________________________
Aint TFile::Get_type_extent(const TDatatype& datatype) const
{
   return fFile.Get_type_extent(datatype);
}

//______________________________________________________________________________
void TFile::Get_view(Offset& disp, TDatatype& etype, TDatatype& filetype, Char_t* datarep) const
{
   fFile.Get_view(disp, etype.fDatatype, filetype.fDatatype, datarep);
}

//______________________________________________________________________________
TRequest TFile::Iread(void* buf, Int_t count, const TDatatype& datatype)
{
   return fFile.Iread(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
TRequest TFile::Iread_at(Offset offset, void* buf, Int_t count, const TDatatype& datatype)
{
   return fFile.Iread_at(offset, buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
TRequest TFile::Iread_shared(void* buf, Int_t count, const TDatatype& datatype)
{
   return fFile.Iread_shared(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
TRequest TFile::Iwrite(const void* buf, Int_t count, const TDatatype& datatype)
{
   return fFile.Iwrite(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
TRequest TFile::Iwrite_at(Offset offset, const void* buf, Int_t count,  const TDatatype& datatype)
{
   return fFile.Iwrite_at(offset, buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
TRequest TFile::Iwrite_shared(const void* buf, Int_t count, const TDatatype& datatype)
{
   return fFile.Iwrite_shared(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
ROOT::Mpi::TFile TFile::Open(const TIntracomm& comm, const Char_t* filename, Int_t amode, const TInfo& info)
{
   return MPI::File::Open(comm.fComm, filename, amode, info.fInfo);
}

//______________________________________________________________________________
void TFile::Preallocate(Offset size)
{
   fFile.Preallocate(size);
}

//______________________________________________________________________________
void TFile::Read(void* buf, Int_t count, const TDatatype& datatype)
{
   fFile.Read(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Read(void* buf, Int_t count, const TDatatype& datatype, TStatus& status)
{
   fFile.Read(buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Read_all(void* buf, Int_t count, const TDatatype& datatype)
{
   fFile.Read_all(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Read_all(void* buf, Int_t count, const TDatatype& datatype, TStatus& status)
{
   fFile.Read_all(buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Read_all_begin(void* buf, Int_t count, const TDatatype& datatype)
{
   fFile.Read_all_begin(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Read_all_end(void* buf)
{
   fFile.Read_all_end(buf);
}

//______________________________________________________________________________
void TFile::Read_all_end(void* buf, TStatus& status)
{
   fFile.Read_all_end(buf, status);
}

//______________________________________________________________________________
void TFile::Read_at(Offset offset, void* buf, Int_t count,  const TDatatype& datatype)
{
   fFile.Read_at(offset, buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Read_at(Offset offset, void* buf, Int_t count,
                    const TDatatype& datatype, TStatus& status)
{
   fFile.Read_at(offset, buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Read_at_all(Offset offset, void* buf, Int_t count,
                        const TDatatype& datatype)
{
   fFile.Read_at_all(offset, buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Read_at_all(Offset offset, void* buf, Int_t count,
                        const TDatatype& datatype, TStatus& status)
{
   fFile.Read_at_all(offset, buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Read_at_all_begin(Offset offset, void* buf, Int_t count,
                              const TDatatype& datatype)
{
   fFile.Read_at_all_begin(offset, buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Read_at_all_end(void* buf)
{
   fFile.Read_at_all_end(buf);
}

//______________________________________________________________________________
void TFile::Read_at_all_end(void* buf, TStatus& status)
{
   fFile.Read_at_all_end(buf, status);
}

//______________________________________________________________________________
void TFile::Read_ordered(void* buf, Int_t count,
                         const TDatatype& datatype)
{
   fFile.Read_ordered(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Read_ordered(void* buf, Int_t count,
                         const TDatatype& datatype,
                         TStatus& status)
{
   fFile.Read_ordered(buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Read_ordered_begin(void* buf, Int_t count,
                               const TDatatype& datatype)
{
   fFile.Read_ordered_begin(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Read_ordered_end(void* buf)
{
   fFile.Read_ordered_end(buf);
}

//______________________________________________________________________________
void TFile::Read_ordered_end(void* buf, TStatus& status)
{
   fFile.Read_ordered_end(buf, status);
}

//______________________________________________________________________________
void TFile::Read_shared(void* buf, Int_t count,
                        const TDatatype& datatype)
{
   fFile.Read_shared(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Read_shared(void* buf, Int_t count,
                        const TDatatype& datatype, TStatus& status)
{
   fFile.Read_shared(buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Seek(Offset offset, Int_t whence)
{
   fFile.Seek(offset, whence);
}

//______________________________________________________________________________
void TFile::Seek_shared(Offset offset, Int_t whence)
{
   fFile.Seek_shared(offset, whence);
}

//______________________________________________________________________________
void TFile::Set_atomicity(Bool_t flag)
{
   fFile.Set_atomicity(flag);
}

//______________________________________________________________________________
void TFile::Set_info(const TInfo& info)
{
   fFile.Set_info(info.fInfo);
}

//______________________________________________________________________________
void TFile::Set_size(Offset size)
{
   fFile.Set_size(size);
}

//______________________________________________________________________________
void TFile::Set_view(Offset disp,  const TDatatype& etype,
                     const TDatatype& filetype, const Char_t* datarep,
                     const TInfo& info)
{
   fFile.Set_view(disp, etype, filetype, datarep, info.fInfo);
}

//______________________________________________________________________________
void TFile::Sync()
{
   fFile.Sync();
}

//______________________________________________________________________________
void TFile::Write(const void* buf, Int_t count, const TDatatype& datatype)
{
   fFile.Write(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Write(const void* buf, Int_t count, const TDatatype& datatype, TStatus& status)
{
   fFile.Write(buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Write_all(const void* buf, Int_t count,
                      const TDatatype& datatype)
{
   fFile.Write_all(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Write_all(const void* buf, Int_t count,
                      const TDatatype& datatype, TStatus& status)
{
   fFile.Write_all(buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Write_all_begin(const void* buf, Int_t count,
                            const TDatatype& datatype)
{
   fFile.Write_all_begin(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Write_all_end(const void* buf)
{
   fFile.Write_all_end(buf);
}

//______________________________________________________________________________
void TFile::Write_all_end(const void* buf, TStatus& status)
{
   fFile.Write_all_end(buf, status);
}

//______________________________________________________________________________
void TFile::Write_at(Offset offset,  const void* buf, Int_t count,
                     const TDatatype& datatype)
{
   fFile.Write_at(offset, buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Write_at(Offset offset,  const void* buf, Int_t count,
                     const TDatatype& datatype, TStatus& status)
{
   fFile.Write_at(offset, buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Write_at_all(Offset offset,  const void* buf, Int_t count,
                         const TDatatype& datatype)
{
   fFile.Write_at_all(offset, buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Write_at_all(Offset offset,  const void* buf, Int_t count,
                         const TDatatype& datatype,
                         TStatus& status)
{
   fFile.Write_at_all(offset, buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Write_at_all_begin(Offset offset, const void* buf,
                               Int_t count,  const TDatatype& datatype)
{
   fFile.Write_at_all_begin(offset, buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Write_at_all_end(const void* buf)
{
   fFile.Write_at_all_end(buf);
}

//______________________________________________________________________________
void TFile::Write_at_all_end(const void* buf, TStatus& status)
{
   fFile.Write_at_all_end(buf, status);
}

//______________________________________________________________________________
void TFile::Write_ordered(const void* buf, Int_t count, const TDatatype& datatype)
{
   fFile.Write_ordered(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Write_ordered(const void* buf, Int_t count,
                          const TDatatype& datatype, TStatus& status)
{
   fFile.Write_ordered(buf, count, datatype.fDatatype, status);
}

//______________________________________________________________________________
void TFile::Write_ordered_begin(const void* buf, Int_t count, const TDatatype& datatype)
{
   fFile.Write_ordered_begin(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Write_ordered_end(const void* buf)
{
   fFile.Write_ordered_end(buf);
}

//______________________________________________________________________________
void TFile::Write_ordered_end(const void* buf, TStatus& status)
{
   fFile.Write_ordered_end(buf, status);
}

//______________________________________________________________________________
void TFile::Write_shared(const void* buf, Int_t count, const TDatatype& datatype)
{
   fFile.Write_shared(buf, count, datatype.fDatatype);
}

//______________________________________________________________________________
void TFile::Write_shared(const void* buf, Int_t count, const TDatatype& datatype, TStatus& status)
{
   fFile.Write_shared(buf, count, datatype.fDatatype, status);
}

//
// Errhandler
//

//______________________________________________________________________________
TErrhandler TFile::Create_errhandler(Errhandler_function* function)
{
   return MPI::File::Create_errhandler(function);
}
TErrhandler TFile::Get_errhandler() const
{
   return fFile.Get_errhandler();
}

//______________________________________________________________________________
void TFile::Set_errhandler(const TErrhandler& errhandler) const
{
   fFile.Set_errhandler(errhandler);
}

//______________________________________________________________________________
void TFile::Call_errhandler(Int_t errorcode) const
{
   fFile.Call_errhandler(errorcode);
}

