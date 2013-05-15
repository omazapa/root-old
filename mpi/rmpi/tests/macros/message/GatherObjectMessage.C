/*************************************************************************
 * Copyright (C) 2012,  Gfif Developers                                   *
 * Grupo de Fenomenologia de Interacciones Fundamentales                  *
 * http://gfif.udea.edu.co                                                *
 * División de ciencias de la computación Gfifdev                         *
 * http://gfifdev.udea.edu.co                                             *
 * Class Created and Maintained By Omar Andres Zapata Mesa                *
 * Team Developers Sigifredo Escobar Gomez,                               *
 * All rights reserved.                                                   *
 *                                                                        *
 *                                                                        *
 * For the list of contributors see $ROOTSYS/README/CREDITS.              *
 *************************************************************************/
#include<RMpi.h>
#include<Mpi/TDebug.h>
#include<iostream>
#include<TArrayD.h>
#include<TMatrixD.h>
#include<TComplex.h>

void GatherObjectMessage()
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;
   ROOT::Mpi::TMpiMessage *msgs = new ROOT::Mpi::TMpiMessage[world.Get_size()];

   Int_t root = 0;
   TString str("*");
   
   str += world.Get_rank();
   ROOT::Mpi::TMpiMessage msg;
   msg.WriteObjectAny(&str,str.Class());
   world.GatherObject(msg,msgs,root);

   if (world.Get_rank() == root) {
      
   
      for (Int_t i = 0; i < world.Get_size(); i++) {
	 msgs[i].SetReadMode();
	 msgs[i].Reset();
         TString *s_str=(TString*)msgs[i].ReadObject(msgs->GetClass());
         std::cout<<s_str->Data();
      }
      std::cout<<"\n";
   }
}