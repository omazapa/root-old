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

#ifndef ROOT_RootMpiUtils
#define ROOT_RootMpiUtils

#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>

#include<TMatrixT.h>
#include<TMatrixD.h>
#include<TMatrixF.h>
#include<TMatrixF.h>
#include<TMatrixDSparse.h>
#include<TMatrixFSym.h>

#ifdef __CINT__
template<class DataType> void PrintTMatrix(DataType matrix);
template<class DataType> void PrintTVector(DataType vector);
template<class DataType> void PrintTArray(DataType array);
template<class DataType> void PrintArray(DataType array, int size);
template<class DataType> Bool_t IqualTArray(DataType array_one, DataType array_two);
template<class DataType> Bool_t IqualArray(DataType array_one, DataType array_two, int size);
#else
template<class DataType> void PrintTMatrix(DataType matrix)
{
   int rows = matrix.GetNrows();
   int cols = matrix.GetNcols();
   std::cout << std::endl;
   std::cout.flush();
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         std::cout << std::setw(10) << matrix[i][j];
         std::cout.flush();
      }
      std::cout << std::endl;
      std::cout.flush();
   }
}

template<class DataType> void PrintTVector(DataType vector)
{
   int rows = vector.GetNrows();
   std::cout << std::endl;
   std::cout.flush();
   for (int i = 0; i < rows; i++) {
      std::cout << std::setw(10) << vector[i];
      std::cout.flush();
   }
   std::cout << std::endl;
   std::cout.flush();
}


template<class DataType> void PrintTArray(DataType array)
{
   int size = array.GetSize();
   for (int i = 0; i < size; i++) {
      std::cout << std::setw(10) << array[i];
      std::cout.flush();
   }
   std::cout << std::endl;
   std::cout.flush();
}

template<class DataType> void PrintArray(DataType array, int size)
{
   for (int i = 0; i < size; i++) {
      std::cout << std::setw(10) << array[i];
      std::cout.flush();
   }
   std::cout << std::endl;
   std::cout.flush();
}


template<class DataType> Bool_t IqualTArray(DataType array_one, DataType array_two)
{
   if (array_one.GetSize() != array_two.GetSize()) {
      return false;
   }
   Int_t size = array_one.GetSize();
   for (Int_t i = 0; i < size; i++) {
      if (array_one[i] != array_two[i]) {
         return false;
      }
   }
   return true;
}

template<class DataType> Bool_t IqualArray(DataType array_one, DataType array_two, int size)
{
   for (Int_t i = 0; i < size; i++) {
      if (array_one[i] != array_two[i]) {
         return false;
      }
   }
   return true;
}

#endif

#endif
