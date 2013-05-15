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

#include<TInfo.h>


using namespace ROOT::Mpi;

ClassImp(TInfo)

//______________________________________________________________________________
TInfo TInfo::Create()
{
   return MPI::Info::Create();
}

//______________________________________________________________________________
TInfo  TInfo::Dup() const
{
   return fInfo.Dup();
}

//______________________________________________________________________________
void TInfo::Delete(const Char_t* key)
{
   fInfo.Delete(key);
}


//______________________________________________________________________________
void TInfo::Free()
{
   fInfo.Free();
}

//______________________________________________________________________________
Bool_t TInfo::Get(const Char_t* key, Int_t valuelen, Char_t* value) const
{
   return fInfo.Get(key, valuelen, value);
}

//______________________________________________________________________________
Int_t TInfo::Get_nkeys() const
{
   return fInfo.Get_nkeys();
}

//______________________________________________________________________________
void TInfo::Get_nthkey(Int_t n, Char_t* key) const
{
   fInfo.Get_nthkey(n, key);
}

//______________________________________________________________________________
Bool_t TInfo::Get_valuelen(const Char_t* key, Int_t& valuelen) const
{
   return fInfo.Get_valuelen(key, valuelen);
}

//______________________________________________________________________________
void TInfo::Set(const Char_t* key, const Char_t* value)
{
   fInfo.Set(key, value);
}
