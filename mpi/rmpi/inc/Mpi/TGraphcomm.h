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

#ifndef ROOT_Mpi_TGraphcomm
#define ROOT_Mpi_TGraphcomm

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#include<TObject.h>
#include"TGroup.h"
#include"TIntracomm.h"
namespace ROOT {

   namespace Mpi {
      class TGraphcomm: public TIntracomm {
      private:
         TGraphcomm(const MPI_Comm& data);
      public:
         using TComm::Clone;
         TGraphcomm();
         TGraphcomm(const TGraphcomm& data);

         TGraphcomm& operator=(const TGraphcomm& data) {
            TComm::fComm = data.fComm;
            return *this;
         }


         //
         // Groups, Contexts, and Communicators
         //

         TGraphcomm Dup() const;

         virtual TGraphcomm& Clone() const;


         //
         //  Process Topologies
         //

         virtual void Get_dims(Int_t nnodes[], Int_t nedges[]) const;

         virtual void Get_topo(Int_t maxindex, Int_t maxedges, Int_t index[], Int_t edges[]) const;

         virtual Int_t Get_neighbors_count(Int_t rank) const;

         virtual void Get_neighbors(Int_t rank, Int_t maxneighbors, Int_t neighbors[]) const;

         virtual Int_t Map(Int_t nnodes, const Int_t index[], const Int_t edges[]) const;

         ClassDef(TGraphcomm, 3) //
      };
   }

}

#endif
