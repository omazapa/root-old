/*************************************************************************
* Copyright (C) 2012,  Gfif Developers                              *
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


#include<TArrayC.h>
#include<TArrayD.h>
#include<TArrayF.h>
#include<TArrayI.h>
#include<TArrayL.h>
#include<TArrayL64.h>
#include<TArrayS.h>
#include<TF2.h>
#include<TApplication.h>
// using namespace ROOT::Mpi; 
void SendRecvObjectExtreme()
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;

   if (world.Get_rank() == 0) {
      /**********
       * Matrix *
       **********/
      TMatrixD d_mat(9000000,2);
      d_mat[0][0] = 0.1;
      d_mat[0][1] = 0.2;
      d_mat[1][0] = 0.3;
      d_mat[1][1] = 0.4;


      world.SendObject(d_mat,1, 0);
   } else if (world.Get_rank() == 1) {

      /**********
       * Matrix *
       **********/
      TMatrixD d_mat;
      TMatrixD d_matrequired(9000000,2);
      d_matrequired[0][0] = 0.1;
      d_matrequired[0][1] = 0.2;
      d_matrequired[1][0] = 0.3;
      d_matrequired[1][1] = 0.4;

      world.RecvObject(d_mat,0, 0);
     if(d_mat==d_matrequired) cout<<"PASSED"<<endl;

   }
}
