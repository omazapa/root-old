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


#include<RMpi.h>
#include<iostream>
#include<TArrayD.h>
#include<TMatrixD.h>
#include<TComplex.h>
using namespace ROOT;
void AllGatherObjectMessage()
{
   Mpi::TEnvironment env;
   Int_t size=Mpi::COMM_WORLD.Get_size();

   TString str("*");
   Mpi::TMpiMessage msg;
   msg.WriteObjectAny(&str,str.Class());
   
   Mpi::TMpiMessage *msgs=new Mpi::TMpiMessage[size];
   
   
   
   Mpi::COMM_WORLD.AllGatherObject(msg,msgs);
   
   for(Int_t i=0;i<size;i++){
   TString rstr=*(TString*)msgs[i].ReadObject(msgs[i].Class());
   cout<<rstr.Data();
   }
    cout<<endl;
}