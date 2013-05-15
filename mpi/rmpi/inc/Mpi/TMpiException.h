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

#ifndef ROOT_Mpi_TException
#define ROOT_Mpi_TException
#include<TObject.h>
#include<TString.h>
#include<Rtypes.h>
#include<exception>

#ifdef __CINT__
namespace MPI {
   class Exception;
}
#else
#include<mpi.h>
#endif

namespace ROOT {
   namespace Mpi {
      class TMpiException: public TObject {
      protected:
         Int_t error_code;
         Int_t error_class;
         TString error_string;
         TString msg;
         Int_t rank;
         Int_t root;
         Bool_t show;
         TString error_method;
      public:
         TMpiException(Int_t err_code, Int_t rank, const Char_t *err_method = NULL, const Char_t *err_msg = NULL, Int_t root = -1, Bool_t show = true, Int_t err_class = -1);
         TMpiException(const TMpiException& a);
         virtual ~TMpiException() throw() {};
         inline Int_t Get_error_code() const {
            return error_code;
         }
         inline Int_t Get_error_class() const {
            return error_class;
         }
         inline TString Get_error_string() const {
            return error_string;
         }
         ClassDef(TMpiException, 1)
      };
   }
}


#endif
