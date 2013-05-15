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

#include<TGroup.h>


using namespace ROOT::Mpi;

ClassImp(TGroup)


//______________________________________________________________________________
Int_t TGroup::Get_size() const
{
   return fGroup.Get_size();
}

//______________________________________________________________________________
Int_t TGroup::Get_rank() const
{
   return fGroup.Get_rank();
}

//______________________________________________________________________________
void TGroup::Translate_ranks(const TGroup& group1, Int_t n, const Int_t ranks1[], const TGroup& group2, Int_t ranks2[])
{
   MPI::Group::Translate_ranks(group1.fGroup, n, ranks1, group2.fGroup, ranks2);
}

//______________________________________________________________________________
Int_t TGroup::Compare(const TGroup& group1, const TGroup& group2)
{
   return MPI::Group::Compare(group1.fGroup, group2.fGroup);
}

//______________________________________________________________________________
TGroup TGroup::Union(const TGroup &group1, const TGroup &group2)
{
   return MPI::Group::Union(group1.fGroup, group2.fGroup);
}

//______________________________________________________________________________
TGroup TGroup::Intersect(const TGroup &group1, const TGroup &group2)
{
   return MPI::Group::Intersect(group1.fGroup, group2.fGroup);
}

//______________________________________________________________________________
TGroup TGroup::Difference(const TGroup &group1, const TGroup &group2)
{
   return MPI::Group::Difference(group1.fGroup, group2.fGroup);
}

//______________________________________________________________________________
TGroup TGroup::Include(Int_t n, const Int_t ranks[]) const
{
   return fGroup.Incl(n, ranks);
}

//______________________________________________________________________________
TGroup TGroup::Exclude(Int_t n, const Int_t ranks[]) const
{
   return fGroup.Excl(n, ranks);
}

//______________________________________________________________________________
TGroup TGroup::Range_include(Int_t n, const Int_t ranges[][3]) const
{
   return fGroup.Range_incl(n, ranges);
}

//______________________________________________________________________________
TGroup TGroup::Range_exclude(Int_t n, const Int_t ranges[][3]) const
{
   return fGroup.Range_excl(n, ranges);
}

//______________________________________________________________________________
void TGroup::Free()
{
   fGroup.Free();
}