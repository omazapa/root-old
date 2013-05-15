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



void ScatterObjectMessage(Int_t root = 1)
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;


   ROOT::Mpi::TMpiMessage *msgs=new ROOT::Mpi::TMpiMessage[world.Get_size()];
   if (world.Get_rank() == root) {
      TMatrixD *d_objects = new TMatrixD[world.Get_size()];   
      for (Int_t i = 0; i < world.Get_size(); i++) {
         d_objects[i].ResizeTo(3, 3);
         for (Int_t n = 0; n < 3; n++) {
            for (Int_t m = 0; m < 3; m++) {
               d_objects[i][n][m] = i;
            }
         }
         msgs[i].WriteObject(&d_objects[i]);
      }
      delete[] d_objects;
   }
   ROOT::Mpi::TMpiMessage rmsg;

   world.ScatterObject(msgs,rmsg,root);

   TMatrixD *d_matrix=(TMatrixD*)rmsg.ReadObject(rmsg.GetClass());
   TMatrixD d_matrix_required(3, 3);
//    for (Int_t n = 0; n < 3; n++) {
//       for (Int_t m = 0; m < 3; m++) {
//          d_matrix_required[n][m] = world.Get_rank();
//       }
//    }
   cout<<"Rank = "<<world.Get_rank()<<endl;
   d_matrix->Print();
}