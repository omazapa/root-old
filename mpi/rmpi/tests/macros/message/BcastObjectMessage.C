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


void BcastObjectMessage(Int_t root=0)
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;
   ROOT::Mpi::TMpiMessage msg;
   ROOT::Mpi::TMpiMessage *msgs=new ROOT::Mpi::TMpiMessage[2];
   if (world.Get_rank() == root) {
      /**********
       * Matrix *
       **********/
      TMatrixD d_mat(2, 2);
      d_mat[0][0] = 0.1;
      d_mat[0][1] = 0.2;
      d_mat[1][0] = 0.3;
      d_mat[1][1] = 0.4;

      msg.WriteObject(&d_mat);
      msgs[0].WriteObject(&d_mat);
      TString str="RMpi";
      msgs[1].WriteObjectAny(&str,str.Class());
      
   }
   world.BcastObject(msg,root);

   world.BcastObject(msgs,2,root);
   
   TMatrixD *rd_mat = (TMatrixD *)msg.ReadObject(msg.GetClass());
   rd_mat->Print();     

   rd_mat=(TMatrixD *)msgs[0].ReadObject(msgs[0].GetClass());
   rd_mat->Print();
   TString str=*(TString *)msgs[1].ReadObject(msgs[1].GetClass());
   cout<<str.Data()<<endl;
}