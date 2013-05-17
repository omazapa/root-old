/*************************************************************************
 * Copyright (C) 2012,  Gfif Developers                                  *
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

#ifndef ROOT_Mpi_TGroup
#define ROOT_Mpi_TGroup


#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif
#include<TObject.h>
#ifdef __CINT__
namespace MPI {
   class Group;
}
struct MPI_Group;
#else
#include<mpi.h>
#endif
namespace ROOT {

   namespace Mpi {
      class TWin;
      class TGroup: public TObject {
         friend class TWin;
      protected:
         MPI::Group fGroup;
      public:
         using TObject::Compare;
         // construction
         TGroup(): TObject() {}
         TGroup(const TObject &obj): TObject(obj) {}
         TGroup(const MPI_Group &group) {
            fGroup = group;
         }
         TGroup(const MPI::Group& group) {
            fGroup = group;
         }
         TGroup(const TGroup& group): TObject(group) {
            fGroup = group.fGroup;
         }

         inline virtual ~TGroup() {}

         inline TGroup& operator=(const TGroup& group) {
            fGroup = group.fGroup;
            return *this;
         }

         inline Bool_t operator== (const TGroup &group) {
            return (Bool_t)(fGroup == group.fGroup);
         }
         inline Bool_t operator!= (const TGroup &group) {
            return (Bool_t)!(fGroup == group.fGroup);
         }

         inline TGroup& operator= (const MPI_Group &group) {
            fGroup = group;
            return *this;
         }
         inline operator MPI_Group() const {
	   return (const MPI_Group)fGroup;
         }


         //
         // Groups, Contexts, and Communicators
         //

         virtual Int_t Get_size() const;

         virtual Int_t Get_rank() const;

         static void Translate_ranks(const TGroup& group1, Int_t n, const Int_t ranks1[],
                                     const TGroup& group2, Int_t ranks2[]);

         static Int_t Compare(const TGroup& group1, const TGroup& group2);

         static TGroup Union(const TGroup &group1, const TGroup &group2);

         static TGroup Intersect(const TGroup &group1, const TGroup &group2);

         static TGroup Difference(const TGroup &group1, const TGroup &group2);

         virtual TGroup Incl(Int_t n, const Int_t ranks[]) const;

         virtual TGroup Excl(Int_t n, const Int_t ranks[]) const;

         virtual TGroup Range_incl(Int_t n, const Int_t ranges[][3]) const;

         virtual TGroup Range_excl(Int_t n, const Int_t ranges[][3]) const;

         virtual void Free();

         ClassDef(TGroup, 1)
      };
   }

}

#endif
