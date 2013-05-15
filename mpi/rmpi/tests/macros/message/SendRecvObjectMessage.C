/*************************************************************************
* Copyright (C) 2013,  Gfif Developers                              *
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
#include<TString.h>
#include<TStringLong.h>

#include<TMatrixD.h>
#include<TMatrixF.h>
#include<TMatrixDSparse.h>

// using namespace ROOT::Mpi; 
void SendRecvObjectMessage()
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;

   if (world.Get_rank() == 0) {
      /**********
       * Matrix *
       **********/
      TMatrixD d_mat1(2, 2);
      d_mat1[0][0] = 0.1;
      d_mat1[0][1] = 0.2;
      d_mat1[1][0] = 0.3;
      d_mat1[1][1] = 0.4;

     TMatrixD d_mat2(2, 2);
      d_mat2[0][0] = 0.9;
      d_mat2[0][1] = 0.9;
      d_mat2[1][0] = 0.9;
      d_mat2[1][1] = 0.9;

      
      ROOT::Mpi::TMpiMessage *msg=new ROOT::Mpi::TMpiMessage[2];
      msg[0].WriteObjectAny(&d_mat2,d_mat2.Class());

      msg[1].WriteObjectAny(&d_mat1,d_mat1.Class());
      world.SendObject(msg,2,1,0);
   } else if (world.Get_rank() == 1) {

      ROOT::Mpi::TMpiMessage *msg=new ROOT::Mpi::TMpiMessage[2];
      world.RecvObject(msg,2,0,0);
      TMatrixD *d_mat1 = (TMatrixD *)msg[0].ReadObject(msg[0].GetClass());
      d_mat1.Print();
      TMatrixD *d_mat2 = (TMatrixD *)msg[1].ReadObject(msg[1].GetClass());
      d_mat2.Print();
      
   }
}
