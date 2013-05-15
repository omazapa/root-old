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
#include <TArrayI.h>
// using namespace ROOT::Mpi; 
void ISendRecvObjectMessage()
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;

   if (world.Get_rank() == 0) {
      /**********
       * Matrix *
       **********/
      TMatrixD d_mat(2, 2);
      d_mat[0][0] = 0.1;
      d_mat[0][1] = 0.2;
      d_mat[1][0] = 0.3;
      d_mat[1][1] = 0.4;
      
      ROOT::Mpi::TMpiMessage msg;
      msg.WriteObjectAny(&d_mat,d_mat.Class());
      ROOT::Mpi::TRequest req=world.ISendObject(msg,1,0);
      
      ROOT::Mpi::TMpiMessage rmsg;
      TString obj("ROOT");
      rmsg.WriteObjectAny(&obj,obj.Class());
      
      req=world.IRsendObject(rmsg,1,1);
 
      ROOT::Mpi::TMpiMessage smsg;
      TArrayI vec(3);
      vec[0]=1;
      vec[1]=2;
      vec[2]=3;
      smsg.WriteObjectAny(&vec,vec.Class());
      
      req=world.ISsendObject(smsg,1,2);
      
  } else if (world.Get_rank() == 1) {


      TMatrixD d_mat_required(2, 2);
      d_mat_required[0][0] = 0.1;
      d_mat_required[0][1] = 0.2;
      d_mat_required[1][0] = 0.3;
      d_mat_required[1][1] = 0.4;
      ROOT::Mpi::TRequest req;
      ROOT::Mpi::TMpiMessage msg;
      ROOT::Mpi::TMpiMessage rmsg;
      ROOT::Mpi::TMpiMessage smsg;
      req=world.IRecvObject(rmsg,0,1);
      req=world.IRecvObject(smsg,0,2);
      req=world.IRecvObject(msg,0,0);
      TMatrixD *d_mat = (TMatrixD *)msg.ReadObject(msg.GetClass());
      d_mat->Print();
      
      TString  *str=(TString*)rmsg.ReadObject(rmsg.GetClass());
      cout<<str->Data()<<endl;
      TArrayI vec=*(TArrayI*)smsg.ReadObject(smsg.GetClass());
      for(Int_t i=0;i<vec.GetSize();i++) cout<<vec[i]<<endl;
   }
}
