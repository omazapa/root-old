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

void ISendRecvObject()
{
   ROOT::Mpi::TEnvironment env(gApplication->Argc(), gApplication->Argv());
   ROOT::Mpi::TIntracomm world;
   ROOT::Mpi::TRequest request;


   if (world.Get_rank() == 0) {
      TArrayD darr(2);
      darr[0] = 0.01;
      darr[1] = 0.02;
      TString str = "RMpi";
      request = world.ISendObject(darr,1, 0); //call non-blocking and before sync methods

      Double_t d = 1.1;

      world.Send(&d,1,ROOT::Mpi::DOUBLE,1, 2);
      request = world.ISsendObject(str,1, 1); //call non-blocking and after sync methods

      TMatrixD dmat(2, 2);
      dmat[0][0] = 0.001;
      dmat[0][1] = 0.001001;
      dmat[1][0] = 0.002002;
      dmat[1][1] = 0.003003;

      request = world.IRsendObject(dmat,1, 2); //call non-blocking aready mode
   } else if (world.Get_rank() == 1) {
      Double_t d;
      TString str;
      request = world.IRecvObject(str,0, 1);
      cout<<str.Data()<<endl;
      world.Recv(&d,1,ROOT::Mpi::DOUBLE,0, 2);//I can recv firts Sync Method beacuse the integer is passed in non-blocking method

      cout<<d<<endl;
      
      TMatrixD dmat(2, 2);
      TMatrixD dmat_required(2, 2);
      dmat_required[0][0] = 0.001;
      dmat_required[0][1] = 0.001001;
      dmat_required[1][0] = 0.002002;
      dmat_required[1][1] = 0.003003;

      request = world.IRecvObject(dmat,0, 2);
      dmat.Print();

      TArrayD darr(2);
      TArrayD darr_required(2);
      darr_required[0] = 0.01;
      darr_required[1] = 0.02;

      request = world.IRecvObject(darr,0, 0);
      for(Int_t i=0;i<darr.GetSize();i++) cout<<darr[i]<<endl;
   }
}