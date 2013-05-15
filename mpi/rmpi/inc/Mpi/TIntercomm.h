/*************************************************************************
 * Copyright (C) 2012,  Gfif Developers                              *
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

#ifndef ROOT_Mpi_TIntercomm
#define ROOT_Mpi_TIntercomm

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif

#include<TObject.h>
#include"TComm.h"
#include"TGroup.h"

namespace ROOT {

   namespace Mpi {
      class TIntracomm;
      class TIntercomm: public TComm {
      public:
         using TComm::Clone;
         TIntercomm(MPI::Intercomm comm);

         TIntercomm(const TIntercomm& data);

         // assignment
         TIntercomm& operator=(const TIntercomm& data) {
            TComm::fComm = data.TComm::fComm;
            return *this;
         }

         TIntercomm& operator=(const MPI::Comm& data) {
            TComm::fComm = data;
            return *this;
         }

         virtual int Get_remote_size() const;
         virtual TGroup Get_remote_group() const;

         TIntercomm Dup() const;
         virtual TIntercomm& Clone() const;

         virtual TIntracomm Merge(bool high);

         virtual TIntercomm Create(const TGroup& group) const;

         virtual TIntercomm Split(int color, int key) const;

         ClassDef(TIntercomm, 1) //
      };
   }

}

#endif
