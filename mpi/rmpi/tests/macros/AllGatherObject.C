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
void AllGatherObject()
{
   Mpi::TEnvironment env;
   Int_t size=Mpi::COMM_WORLD.Get_size();

   TString str;
   str+=Mpi::COMM_WORLD.Get_rank();
   TString *strs=new TString[size];
    
   Mpi::COMM_WORLD.AllGatherObject(str,strs);
   
  for(Int_t i=0;i<size;i++){
   cout<<strs[i].Data();
   }
    cout<<endl;
}