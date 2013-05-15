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


void BcastObject(Int_t root = 0)
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;
   TMatrixD d_mat;
   TMatrixF f_mat;
   TMatrixDSparse sd_mat;
   TString t_str;
   TStringLong tl_str;
   TArrayC c_arr;
   TArrayD d_arr;
   
   TString *strs=new TString[2];
   
   if (world.Get_rank() == root) {
      /**********
       * Matrix *
       **********/
      d_mat.ResizeTo(2,2);
      d_mat[0][0] = 0.1;
      d_mat[0][1] = 0.2;
      d_mat[1][0] = 0.3;
      d_mat[1][1] = 0.4;

      f_mat.ResizeTo(2,2);
      f_mat[0][0] = 0.01;
      f_mat[0][1] = 0.02;
      f_mat[1][0] = 0.03;
      f_mat[1][1] = 0.04;

      sd_mat.ResizeTo(2,2);
      sd_mat[0][0] = 1.00001;

      /**********
       * TSring *
       **********/
      t_str = "hola";
      tl_str = "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
      tl_str += "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
      tl_str += "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
      /**********
       * TArray *
       **********/
      c_arr.Set(4);
      c_arr[0] = 'R';
      c_arr[1] = 'O';
      c_arr[2] = 'O';
      c_arr[3] = 'T';

      d_arr.Set(3);
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
      
      strs[0]="ROOT";
      strs[1]="Mpi";

   }

   world.BcastObject(d_mat, root);
   d_mat.Print();
   world.BcastObject(f_mat, root);
   f_mat.Print();   
   world.BcastObject(sd_mat, root);
   sd_mat.Print();
   
   world.BcastObject(strs,2, root);
    cout<<strs[0].Data()<<endl;
    cout<<strs[1].Data()<<endl;
   
   /**********
    * Matrix *
    **********/
   TMatrixD d_mat(2, 2);
   TMatrixF f_mat(2, 2);
   TMatrixDSparse sd_mat(2, 2);

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
   TArrayC c_arr(4);
   TArrayD d_arr(3);
   TArrayF f_arr(3);
   TArrayI i_arr(3);

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
}