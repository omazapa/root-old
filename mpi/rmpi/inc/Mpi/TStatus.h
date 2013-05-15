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
#ifndef ROOT_Mpi_TStatus
#define ROOT_Mpi_TStatus
#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#ifdef __CINT__
namespace MPI {
   class Status;
}
struct MPI_Status;
#else
#include<mpi.h>
#endif
#include<Mpi/TDatatype.h>
namespace ROOT {
   namespace Mpi {
      class TStatus: public MPI::Status {
      public:
         using MPI::Status::Get_count;
         using MPI::Status::Get_elements;
         using MPI::Status::Set_elements;
//    using MPI::Status::
         TStatus();
         TStatus(const TStatus& data);
         TStatus(const MPI_Status &i);

         virtual ~TStatus() {}

         TStatus& operator=(const TStatus& data) {
            mpi_status = data.mpi_status;
            return *this;
         }

         TStatus& operator= (const MPI_Status &i) {
            mpi_status = i;
            return *this;
         }
         operator MPI_Status() const {
            return mpi_status;
         }

         virtual Int_t Get_count(const TDatatype& datatype) const;

         virtual Bool_t Is_cancelled() const;

         virtual Int_t Get_elements(const TDatatype& datatype) const;

         virtual Int_t Get_source() const;

         virtual void Set_source(Int_t source);

         virtual Int_t Get_tag() const;

         virtual void Set_tag(Int_t tag);

         virtual Int_t Get_error() const;

         virtual void Set_error(Int_t error);

         virtual void Set_elements(const TDatatype& datatype, Int_t count);

         virtual void Set_cancelled(Bool_t flag);

         ClassDef(TStatus, 0)
      };
   }
}
#endif
