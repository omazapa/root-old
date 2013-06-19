#include<TRInterface.h>
//Tests for Functions
//passing function from C++ to R enviroment
//NOTE: the functions support some TObjects Arguments tha was enable in RExport.h

double funv(TVectorD v)
{
   return v[0] * v[1];
}

void funm(TMatrixD m)
{
   m.Print();
}

void funs(TString s)
{
   std::cout << "hello " << s.Data() << std::endl;
}

Double_t fun3(TVectorD x, TVectorD par)
{
   return x[0] * par[0];
}

int main()
{
   gR->SetVerbose(kFALSE);
   gR->assign(Rcpp::InternalFunction(&funv), "funv");
   gR->assign(Rcpp::InternalFunction(&funm), "funm");
   gR->assign(Rcpp::InternalFunction(&funs), "funs");
   gR->assign(Rcpp::InternalFunction(&fun3), "f3");

   gR->parse("cat(funv(c(2,3)))");
   gR->parse("cat(funm(matrix(c(1,2,3,4),2,2)))");
   gR->parse("cat(funs('ROOTR'))");
   gR->parse("cat(f3(c(1),c(2)))");
}