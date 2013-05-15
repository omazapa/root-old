/*************************************************************************
 * Copyright (C) 2010-2012,  Gfif Developers                              *
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

#ifndef ROOT_Mpi_TFile
#define ROOT_Mpi_TFile

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#include<TObject.h>

#ifdef __CINT__
namespace MPI {
   class File;
}
struct MPI_File;
#else
#include<mpi.h>
#endif
#include"MTypes.h"
#include"TIntracomm.h"
namespace ROOT {

   namespace Mpi {
      class TInfo;
      class TDatatype;
      class TRequest;
      class TFile: public TObject {
      protected:
         MPI::File fFile;
      public:
         using TObject::Delete;
         using TObject::Write;
         using TObject::Read;

         TFile() {}
         TFile(const MPI::File& file) {
            fFile = file;
         }
         TFile(const ROOT::Mpi::TFile& file): TObject(file) {
            fFile = file;
         }
         TFile(const MPI_File &file) {
            fFile = file;
         }
         virtual ~TFile() { }

         ROOT::Mpi::TFile& operator=(const MPI::File& file) {
            fFile = file;
            return *this;
         }
         ROOT::Mpi::TFile& operator=(const ROOT::Mpi::TFile& file) {
            fFile = file;
            return *this;
         }
         ROOT::Mpi::TFile& operator=(const MPI_File &file) {
            fFile = file;
            return *this;
         }
         operator MPI_File() const {
            return (MPI_File)fFile;
         }


         // from the I/o chapter of MPI - 2

         inline void Close() {
            fFile.Close();
         }

         static void Delete(const Char_t* filename, const TInfo& info);

         Int_t Get_amode() const;

         Bool_t Get_atomicity() const;

         Offset Get_byte_offset(const Offset disp) const;

         ROOT::Mpi::TGroup Get_group() const;

         ROOT::Mpi::TInfo Get_info() const;

         Offset Get_position() const;

         Offset Get_position_shared() const;

         Offset Get_size() const;

         Aint Get_type_extent(const TDatatype& datatype) const;

         void Get_view(Offset& disp, TDatatype& etype, TDatatype& filetype, Char_t* datarep) const;

         TRequest Iread(void* buf, Int_t count, const TDatatype& datatype);

         TRequest Iread_at(Offset offset, void* buf, Int_t count, const TDatatype& datatype);

         TRequest Iread_shared(void* buf, Int_t count, const TDatatype& datatype);

         TRequest Iwrite(const void* buf, Int_t count, const TDatatype& datatype);

         TRequest Iwrite_at(Offset offset, const void* buf, Int_t count,  const TDatatype& datatype);

         TRequest Iwrite_shared(const void* buf, Int_t count, const TDatatype& datatype);

         static ROOT::Mpi::TFile Open(const TIntracomm& comm, const Char_t* filename, Int_t amode,
                                      const TInfo& info);

         void Preallocate(Offset size);

         void Read(void* buf, Int_t count, const TDatatype& datatype);

         void Read(void* buf, Int_t count, const TDatatype& datatype,
                   TStatus& status);

         void Read_all(void* buf, Int_t count, const TDatatype& datatype);

         void Read_all(void* buf, Int_t count, const TDatatype& datatype, TStatus& status);

         void Read_all_begin(void* buf, Int_t count, const TDatatype& datatype);

         void Read_all_end(void* buf);

         void Read_all_end(void* buf, TStatus& status);

         void Read_at(Offset offset, void* buf, Int_t count,  const TDatatype& datatype);

         void Read_at(Offset offset, void* buf, Int_t count,
                      const TDatatype& datatype, TStatus& status);

         void Read_at_all(Offset offset, void* buf, Int_t count,
                          const TDatatype& datatype);

         void Read_at_all(Offset offset, void* buf, Int_t count,
                          const TDatatype& datatype, TStatus& status);

         void Read_at_all_begin(Offset offset, void* buf, Int_t count,
                                const TDatatype& datatype);

         void Read_at_all_end(void* buf);

         void Read_at_all_end(void* buf, TStatus& status);

         void Read_ordered(void* buf, Int_t count,
                           const TDatatype& datatype);

         void Read_ordered(void* buf, Int_t count,
                           const TDatatype& datatype,
                           TStatus& status);

         void Read_ordered_begin(void* buf, Int_t count,
                                 const TDatatype& datatype);

         void Read_ordered_end(void* buf);

         void Read_ordered_end(void* buf, TStatus& status);

         void Read_shared(void* buf, Int_t count,
                          const TDatatype& datatype);

         void Read_shared(void* buf, Int_t count,
                          const TDatatype& datatype, TStatus& status);

         void Seek(Offset offset, Int_t whence);

         void Seek_shared(Offset offset, Int_t whence);

         void Set_atomicity(Bool_t flag);

         void Set_info(const TInfo& info);

         void Set_size(Offset size);

         void Set_view(Offset disp,  const TDatatype& etype,
                       const TDatatype& filetype, const Char_t* datarep,
                       const TInfo& info);

         void Sync();

         void Write(const void* buf, Int_t count, const TDatatype& datatype);

         void Write(const void* buf, Int_t count, const TDatatype& datatype, TStatus& status);

         void Write_all(const void* buf, Int_t count,
                        const TDatatype& datatype);

         void Write_all(const void* buf, Int_t count,
                        const TDatatype& datatype, TStatus& status);

         void Write_all_begin(const void* buf, Int_t count,
                              const TDatatype& datatype);

         void Write_all_end(const void* buf);

         void Write_all_end(const void* buf, TStatus& status);

         void Write_at(Offset offset,  const void* buf, Int_t count,
                       const TDatatype& datatype);

         void Write_at(Offset offset,  const void* buf, Int_t count,
                       const TDatatype& datatype, TStatus& status);

         void Write_at_all(Offset offset,  const void* buf, Int_t count,
                           const TDatatype& datatype);

         void Write_at_all(Offset offset,  const void* buf, Int_t count,
                           const TDatatype& datatype,
                           TStatus& status);

         void Write_at_all_begin(Offset offset, const void* buf,
                                 Int_t count,  const TDatatype& datatype);

         void Write_at_all_end(const void* buf);

         void Write_at_all_end(const void* buf, TStatus& status);

         void Write_ordered(const void* buf, Int_t count, const TDatatype& datatype);

         void Write_ordered(const void* buf, Int_t count,
                            const TDatatype& datatype, TStatus& status);

         void Write_ordered_begin(const void* buf, Int_t count, const TDatatype& datatype);

         void Write_ordered_end(const void* buf);

         void Write_ordered_end(const void* buf, TStatus& status);

         void Write_shared(const void* buf, Int_t count, const TDatatype& datatype);

         void Write_shared(const void* buf, Int_t count, const TDatatype& datatype, TStatus& status);

         //
         // Errhandler
         //
         typedef void Errhandler_function(MPI::File &, Int_t *, ...);

         static ROOT::Mpi::TErrhandler Create_errhandler(Errhandler_function* function);

         ROOT::Mpi::TErrhandler Get_errhandler() const;

         void Set_errhandler(const TErrhandler& errhandler) const;

         void Call_errhandler(Int_t errorcode) const;

         ClassDef(TFile, 1)
      };
   }

}

#endif
