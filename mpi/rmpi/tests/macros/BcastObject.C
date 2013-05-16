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
   TStringLong tl_str;
   TArrayC c_arr;
   
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
      
      strs[0]="ROOT";
      strs[1]="Mpi";

   }

   world.BcastObject(d_mat, root);
   world.BcastObject(f_mat, root);
   world.BcastObject(sd_mat, root);
   world.BcastObject(tl_str, root);
   world.BcastObject(c_arr, root);
   world.BcastObject(strs,2, root);
   
   /**********
    * Matrix *
    **********/
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
   TStringLong tl_str_required = "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
   tl_str_required += "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";
   tl_str_required += "123456789012345678901234567890123456789012345678901234567890234567890123456789012345678901234567890\n";

   if((d_mat==d_mat_required)&&(f_mat==f_mat_required)&&(sd_mat==sd_mat_required)&&(tl_str==tl_str_required)&&(strs[0]=="ROOT")&&(strs[1]=="Mpi"))
   {
      cout<<"PASSED"<<endl;
   }
   
}