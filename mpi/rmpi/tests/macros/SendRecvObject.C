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
void SendRecvObject()
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;
//    MpiInitTest(world, 2, ROOT::Mpi::Iqual);

   if (world.Get_rank() == 0) {
      /**********
       * Matrix *
       **********/
      TMatrixD d_mat(2, 2);
      d_mat[0][0] = 0.1;
      d_mat[0][1] = 0.2;
      d_mat[1][0] = 0.3;
      d_mat[1][1] = 0.4;

      TMatrixF f_mat(2, 2);
      f_mat[0][0] = 0.01;
      f_mat[0][1] = 0.02;
      f_mat[1][0] = 0.03;
      f_mat[1][1] = 0.04;

      TMatrixDSparse sd_mat(2, 2);
      sd_mat[0][0] = 1.00001;

      /**********
       * TSring *
       **********/
      TString t_str = "hola";
      TStringLong tl_str = "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
      tl_str += "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
      tl_str += "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
      /**********
       * TArray *
       **********/
      TArrayC c_arr(4);
      c_arr[0] = 'R';
      c_arr[1] = 'O';
      c_arr[2] = 'O';
      c_arr[3] = 'T';

      TArrayD d_arr(3);
      d_arr[0] = 1.1;
      d_arr[1] = 2.2;
      d_arr[2] = 3.3;

      TArrayF f_arr(3);
      f_arr[0] = 0.1;
      f_arr[1] = 0.2;
      f_arr[2] = 0.3;

      TArrayI i_arr(3);
      i_arr[0] = 1;
      i_arr[1] = 2;
      i_arr[2] = 3;

      world.SendObject(d_mat,1, 0);
      world.SendObject(f_mat,1, 0);
      world.SendObject(sd_mat,1, 0);
      world.SendObject(t_str,1, 0);
      world.SendObject(tl_str,1, 0);
      world.SendObject(c_arr,1, 0);
      world.SendObject(d_arr,1, 0);
      world.SendObject(f_arr,1, 0);
      world.SendObject(i_arr,1, 0);

   } else if (world.Get_rank() == 1) {

      /**********
       * Matrix *
       **********/
      TMatrixD d_mat;
      TMatrixF f_mat;
      TMatrixDSparse sd_mat;

      TMatrixD d_mat_required(2, 2);
      d_mat_required[0][0] = 0.1;
      d_mat_required[0][1] = 0.2;
      d_mat_required[1][0] = 0.3;
      d_mat_required[1][1] = 0.4;

      TMatrixF f_mat_required(2, 2);
      f_mat_required[0][0] = 0.01;
      f_mat_required[0][1] = 0.02;
      f_mat_required[1][0] = 0.03;
      f_mat_required[1][1] = 0.04;

      TMatrixDSparse sd_mat_required(2, 2);
      sd_mat_required[0][0] = 1.00001;

      /**********
      * TSring *
      **********/
      TString t_str;
      TStringLong tl_str;
      TStringLong tl_str_required = "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
      tl_str_required += "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
      tl_str_required += "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";

      /**********
       * TArray *
       **********/
      TArrayC c_arr;
      TArrayD d_arr;
      TArrayF f_arr;
      TArrayI i_arr;

      TArrayC c_arr_required(4);
      c_arr_required[0] = 'R';
      c_arr_required[1] = 'O';
      c_arr_required[2] = 'O';
      c_arr_required[3] = 'T';

      TArrayD d_arr_required(3);
      d_arr_required[0] = 1.1;
      d_arr_required[1] = 2.2;
      d_arr_required[2] = 3.3;

      TArrayF f_arr_required(3);
      f_arr_required[0] = 0.1;
      f_arr_required[1] = 0.2;
      f_arr_required[2] = 0.3;

      TArrayI i_arr_required(3);
      i_arr_required[0] = 1;
      i_arr_required[1] = 2;
      i_arr_required[2] = 3;

      world.RecvObject(d_mat,0, 0);
      d_mat.Print();
      
      
      world.RecvObject(f_mat,0, 0);
      f_mat.Print();

      world.RecvObject(sd_mat,0, 0);
      sd_mat.Print();


      world.RecvObject(t_str,0, 0);
      cout<<t_str.Data()<<endl;

      world.RecvObject(tl_str,0, 0);
      cout<<tl_str.Data()<<endl;

      world.RecvObject(c_arr,0, 0);

      world.RecvObject(d_arr,0, 0);

      world.RecvObject(f_arr,0, 0);

      world.RecvObject(i_arr,0, 0);
   }
}
