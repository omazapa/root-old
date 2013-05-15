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
#include<iostream>
#include<TArrayD.h>
#include<TMatrixD.h>
#include<TComplex.h>

void GatherObject()
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;
   TString *strs = new TString[world.Get_size()];
   TMatrixD *mats = new TMatrixD[world.Get_size()];

   Int_t root = 0;
   TString str("*");
   TMatrixD mat(2,2);
   mat[0][0] = world.Get_rank();
   mat[0][1] = world.Get_rank();
   mat[1][0] = world.Get_rank();
   mat[1][1] = world.Get_rank();
   
   str += world.Get_rank();
   world.GatherObject(str,strs,root);
   world.GatherObject(mat,mats,root);
   if (world.Get_rank() == root) {   
      TString s_str;
      TMatrixD s_mat(2,2);
      for (Int_t i = 0; i < world.Get_size(); i++) {
	 s_str+=strs[i];
	 s_mat+=mats[i];
      }
      std::cout<<s_str.Data()<<"\n";
      s_mat.Print();
   }
}