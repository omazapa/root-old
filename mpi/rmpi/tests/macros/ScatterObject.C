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



void ScatterObject(Int_t root = 1)
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;

   TMatrixD *d_objects = new TMatrixD[world.Get_size()];
   TString *s_objects = new TString[world.Get_size()];


   if (world.Get_rank() == root) {
      for (Int_t i = 0; i < world.Get_size(); i++) {
	 Int_t rows=3,cols=3;
         d_objects[i].ResizeTo(rows, cols);
         for (Int_t n = 0; n < 3; n++) {
            for (Int_t m = 0; m < 3; m++) {
               d_objects[i][n][m] = i;
            }
         }
         TString str = "|";
         str += i;
         s_objects[i] = str;
      }
   }
  TMatrixD mat; 
  TString str;
  
  world.ScatterObject(d_objects,mat,root);
  mat.Print();
  world.ScatterObject(s_objects,str,root);
  cout<<str<<endl;
}