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

#ifndef ROOT_Mpi_TInfo
#define ROOT_Mpi_TInfo

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#include<TObject.h>
#ifdef __CINT__
namespace MPI {
   class Info;
   class Request;
}
struct MPI_Info;
#else
#include<mpi.h>
#endif
namespace ROOT {

   namespace Mpi {
      class TComm;
      class TIntracomm;
      class TIntercomm;
      class TWin;
      class TFile;
      class TInfo : public TObject {
         friend class TComm;
         friend class TIntracomm;
         friend class TIntercomm;
         friend class TWin;
         friend class TFile;
      protected:
         MPI::Info fInfo;
      public:
         TInfo() {};
         TInfo(const TInfo& info): TObject(info) {
            fInfo = info.fInfo;
         }
         TInfo(const MPI::Info& info) {
            fInfo = info;
         }
         TInfo(const MPI_Info& info) {
            fInfo = info;
         }

         virtual ~TInfo() {}

         TInfo& operator=(const TInfo& data) {
            fInfo = data.fInfo;
            return *this;
         }



         static TInfo Create();

         virtual void Delete(const Char_t* key);

         TInfo Dup() const;

         virtual void Free();

         virtual bool Get(const Char_t* key, Int_t valuelen, Char_t* value) const;

         virtual Int_t Get_nkeys() const;

         virtual void Get_nthkey(Int_t n, Char_t* key) const;

         virtual bool Get_valuelen(const Char_t* key, Int_t& valuelen) const;

         virtual void Set(const Char_t* key, const Char_t* value);
         operator MPI_Info() {
            return (MPI_Info)fInfo;
         }
         ClassDef(TInfo, 1)

      };
   }
}
#endif
