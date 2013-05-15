#include<TMpiException.h>
#include<iostream>
using namespace ROOT::Mpi;
#include<MTypes.h>

ClassImp(TMpiException)
//______________________________________________________________________________
TMpiException::TMpiException(Int_t err_code, Int_t _rank, const Char_t *err_method, const Char_t *err_msg, Int_t _root, Bool_t _show, Int_t err_class)
{
   try {
      throw MPI::Exception(err_code);
   } catch (MPI::Exception e) {
      if (e.Get_error_code() != MPI_SUCCESS) error_string = e.Get_error_string();
   }
   rank = _rank;
   root = _root;
   show = _show;
   error_method = err_method;
   msg = MSG_RED("------------------TMpiException launched------------------\n");
   msg += MSG_RED("Method: ");
   msg += TString("in method ") + err_method;
   msg += MSG_RED("\nError Code: ");
   msg += err_code;
   msg += MSG_BLUE("\nRank: ");
   msg += rank;
   if (root != -1) {
      msg += MSG_BLUE(" \nRoot: ");
      msg += root;
   }
   msg += MSG_GREEN(" \nMessage:");
   msg += err_msg;
   msg += error_string;
   msg += MSG_RED("\n-----------------------------------------------------------\n");
   error_string = (Char_t *)msg.Data();
   if (show) std::cerr << error_string;
}

//______________________________________________________________________________
TMpiException::TMpiException(const TMpiException& a): TObject(a)
{
   rank = a.rank;
   root = a.root;
   show = a.show;
   error_method = a.error_method;
   error_string = a.error_string;
   if (show) std::cerr << error_string;
}
