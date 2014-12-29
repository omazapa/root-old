/*************************************************************************
 * Copyright (C)      2014, Omar Andres Zapata Mesa                      *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/
#include<TRObject.h>
#include<TRInterface.h>
#include<vector>
//______________________________________________________________________________
/* Begin_Html
*/

using namespace ROOT::R;
ClassImp(TRObject)

ROOTR_MODULE(ROOTR_TRObject)
{

   ROOT::R::class_<ROOT::R::TRObject>("ROOT::R::TRObject", "Mother of all ROOT objects.")
   .constructor()
   .method("ClassName",&ROOT::R::TRObject::ClassName);
}

namespace Rcpp {
   template<> SEXP wrap(const TObject &obj)
   {
      return Rcpp::wrap(ROOT::R::TRObject(obj));
   }
   template<> TObject as(SEXP obj)
   {
      return Rcpp::as<ROOT::R::TRObject>(obj);
   }
}

RCPP_MODULE(ROOTR_TObject)
{

   Rcpp::class_<TObject>("TObject", "Mother of all ROOT objects.")
   .constructor()
   .method("ClassName",&TObject::ClassName);
}

RCPP_MODULE(ROOTR_TRRef)
{

   Rcpp::class_<TRRef>("TRef", "Persistent Reference link to a TObject")
   .constructor<TObject &>()
   .method("GetObject",&TRRef::GetObject);
}


//______________________________________________________________________________
void ROOT::R::TRObject::Load()
{
ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
r["ROOTR_TRObject"]<<LOAD_ROOTR_MODULE(ROOTR_TRObject);
r["ROOTR_TObject"]<<LOAD_ROOTR_MODULE(ROOTR_TObject);
r["ROOTR_TRRef"]<<LOAD_ROOTR_MODULE(ROOTR_TRRef);
}
