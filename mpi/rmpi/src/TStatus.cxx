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

#include<Mpi/TStatus.h>
#include<Mpi/TDatatype.h>

using namespace ROOT::Mpi;

ClassImp(TStatus)
//______________________________________________________________________________
TStatus::TStatus(): Status() {}

//______________________________________________________________________________
TStatus::TStatus(const TStatus& data): Status(data) {}

//______________________________________________________________________________
TStatus::TStatus(const MPI_Status &i): Status(i) {}

//______________________________________________________________________________
Int_t TStatus::Get_count(const TDatatype& datatype) const
{
   return Status::Get_count((MPI_Datatype)datatype);
}

//______________________________________________________________________________
Bool_t TStatus::Is_cancelled() const
{
   return Status::Is_cancelled();
}

//______________________________________________________________________________
Int_t TStatus::Get_elements(const TDatatype& datatype) const
{
   return Status::Get_elements(datatype.fDatatype);
}

//______________________________________________________________________________
Int_t TStatus::Get_source() const
{
   return Status::Get_source();
}

//______________________________________________________________________________
void TStatus::Set_source(Int_t source)
{
   Status::Set_source(source);
}

//______________________________________________________________________________
Int_t TStatus::Get_tag() const
{
   return Status::Get_tag();
}

//______________________________________________________________________________
void TStatus::Set_tag(Int_t tag)
{
   Status::Set_tag(tag);
}

//______________________________________________________________________________
Int_t TStatus::Get_error() const
{
   return Status::Get_error();
}

//______________________________________________________________________________
void TStatus::Set_error(Int_t error)
{
   Status::Set_error(error);
}

//______________________________________________________________________________
void TStatus::Set_elements(const TDatatype& datatype, Int_t count)
{
   Status::Set_elements(datatype.fDatatype, count);
}

//______________________________________________________________________________
void TStatus::Set_cancelled(Bool_t flag)
{
   Status::Set_cancelled(flag);
}
