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

#ifndef ROOT_Mpi_TIntracomm
#define ROOT_Mpi_TIntracomm

#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif

#include<TObject.h>
#include"TComm.h"
#include"TGroup.h"


namespace ROOT {

   namespace Mpi {
      class TIntercomm;
      class TInfo;
      class TWin;
      class TFile;
      class TIntracomm: public TComm {
         friend class TWin;
         friend class TFile;
      public:
         using TComm::Clone;
         TIntracomm(MPI::Intracomm comm = MPI::COMM_WORLD) {
            fComm = comm;
         }
         TIntracomm(const TIntracomm& data);

         // assignment
         TIntracomm& operator=(const TIntracomm& data) {
            TComm::fComm = data.TComm::fComm;
            return *this;
         }

         TIntracomm& operator=(const MPI::Comm& data) {
            TComm::fComm = data;
            return *this;
         }

         TIntracomm Dup() const;
         virtual TIntracomm& Clone() const;

         virtual TIntracomm Create(const TGroup& group) const;

         virtual TIntracomm Split(int color, int key) const;

         virtual TIntercomm Create_intercomm(int local_leader, const TIntracomm& peer_comm, int remote_leader, int tag) const;

         //
         // Process Creation and Management
         //

         virtual TIntercomm Accept(const char* port_name, const TInfo& info, int root)const;

         virtual TIntercomm Connect(const char* port_name, const TInfo& info, int root)const;

         virtual TIntercomm Spawn(const char* command, const char* argv[], int maxprocs, const TInfo& info, int root) const;

         virtual TIntercomm Spawn(const char* command, const char* argv[], int maxprocs, const TInfo& info,
                                  int root, int array_of_errcodes[]) const;

         virtual TIntercomm Spawn_multiple(int count, const char* array_of_commands[], const char** array_of_argv[],
                                           const int array_of_maxprocs[], const TInfo array_of_info[], int root);

         virtual TIntercomm Spawn_multiple(int count, const char* array_of_commands[], const char** array_of_argv[],
                                           const int array_of_maxprocs[], const TInfo array_of_info[], int root,
                                           int array_of_errcodes[]);
         ClassDef(TIntracomm, 1) //
      };
      //Global Comm
      R__EXTERN TIntracomm COMM_WORLD;
   }
}


#endif
