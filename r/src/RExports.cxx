/*************************************************************************
* Copyright (C) 2013,  Gfif Developers                                   *
* Grupo de Fenomenologia de Interacciones Fundamentales                  *
* http://gfif.udea.edu.co                                                *
* División de ciencias de la computación Gfifdev                         *
* Class Created and Maintained By Omar Andres Zapata Mesa                *
* All rights reserved.                                                   *
*                                                                        *
*                                                                        *
* For the list of contributors see $ROOTSYS/README/CREDITS.              *
*************************************************************************/
#include<RExports.h>
#include<Rcpp/Vector.h>

namespace Rcpp{
  
  template<> SEXP wrap( const TString &s)
  {
    return wrap(s.Data());
  }
  template<> TString as( SEXP s) 
  {
    return TString(::Rcpp::as<const char*>(s));
  }

  template<> SEXP wrap( const TVectorD &v)
  {
    Int_t size=v.GetNoElements();
    const Double_t *data=v.GetMatrixArray();
    std::vector<Double_t> vec(data, data + sizeof(Double_t)*size );
    return wrap(vec);
  }
  
  template<> TVectorD as( SEXP v)
  {
     std::vector<Double_t> vec =::Rcpp::as<std::vector<Double_t> >(v);
     return TVectorT<Double_t>(vec.size(), vec.data());    
  }

  template<> SEXP wrap( const TMatrixD &m)
  {
     Int_t rows = m.GetNrows();
     Int_t cols = m.GetNcols();
     Double_t *data = new Double_t[rows * cols];
     m.GetMatrix2Array(data, "F"); //ROOT have a bug here(Fixed)
     NumericMatrix mat(rows,cols,data);
     return wrap(mat);
  }
  
  template<> TMatrixD as( SEXP m)
  {
    NumericMatrix mat=::Rcpp::as<NumericMatrix>(m);
    return TMatrixD(mat.rows(),mat.cols(),mat.begin(),"F");
  }
}
