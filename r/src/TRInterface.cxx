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
#include<TRInterface.h>
#include<vector>

using namespace ROOT::R;
ClassImp(TRInterface)

//______________________________________________________________________________
TRInterface::TRInterface(const int argc, const char *const argv[], const bool loadRcpp, const bool verbose, const bool interactive): RInside(argc, argv, loadRcpp, verbose, interactive)
{
}

//______________________________________________________________________________
Int_t  TRInterface::parseEval(const TString &code, TRObjectProxy  &ans)
{
   SEXP fans;
   Int_t fResult = RInside::parseEval(code.Data(), fans);
   ans = fans;
   return fResult;
}

//______________________________________________________________________________
void TRInterface::parse(const TString &code, Bool_t exception)
{
   if (exception) RInside::parseEvalQ((std::string)code);
   else RInside::parseEvalQNT(code.Data());
}

//______________________________________________________________________________
TRObjectProxy TRInterface::parseEval(const TString &code, Bool_t exception)
{
   if (exception) return TRObjectProxy((SEXP)RInside::parseEval(code.Data()));
   else return TRObjectProxy((SEXP)RInside::parseEvalNT(code.Data()));
}

//______________________________________________________________________________
template<> void TRInterface::assign<TArrayD>(const TArrayD &obj, const TString & name)
{
   std::vector<double> vec(obj.GetArray(), obj.GetArray() + obj.GetSize());
   RInside::assign(vec, name.Data());
}

//______________________________________________________________________________
template<> void TRInterface::assign<TVectorD>(const TVectorD &obj, const TString & name)
{
   std::vector<double> vec(obj.GetMatrixArray(), obj.GetMatrixArray() + obj.GetNoElements());
   RInside::assign(vec, name.Data());
}

//______________________________________________________________________________
template<> void TRInterface::assign<TString>(const TString &obj, const TString & name)
{

   RInside::assign(obj.Data(), name.Data());
}

//______________________________________________________________________________
template<> void TRInterface::assign<TMatrixD>(const TMatrixD &obj, const TString & name)
{
   Int_t rows = obj.GetNrows();
   Int_t cols = obj.GetNcols();
   Double_t *data = new Double_t[rows * cols];
   obj.GetMatrix2Array(data, "F"); //ROOT have a bug here(Fixed)
   TMatrixD m(obj.GetNrows(), obj.GetNcols(), data, "F");
   Rcpp::NumericMatrix mat(obj.GetNrows(), obj.GetNcols(), data);
   RInside::assign(mat, name.Data());
}

//______________________________________________________________________________
template<> void TRInterface::assign<Double_t>(const Double_t &value, const TString & name)
{
   RInside::assign(value, name.Data());
}

//______________________________________________________________________________
template<> void TRInterface::assign<Int_t>(const Int_t &value, const TString & name)
{
   RInside::assign(value, name.Data());
}

//______________________________________________________________________________
Rcpp::Environment::Binding TRInterface::operator[](const TString& name)
{
   return RInside::operator[](name.Data());
}

void TRInterface::x11(TString opt)
{
   parseEvalQ((std::string)TString("x11(" + opt + ")"));
}
