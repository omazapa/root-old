#include<TRInterface.h>

double funv(TVectorD v)
{
  return v[0]*v[1];
}

void funm(TMatrixD m)
{
  m.Print();
}

void funs(TString s)
{
  std::cout<<"hello "<<s.Data()<<std::endl;
}

int main()
{
  gR->assign(Rcpp::InternalFunction(&funv),"funv");
  gR->assign(Rcpp::InternalFunction(&funm),"funm");
  gR->assign(Rcpp::InternalFunction(&funs),"funs");
  
  gR->parse("cat(funv(c(2,3)))");
  gR->parse("cat(funm(matrix(c(1,2,3,4),2,2)))");
  gR->parse("cat(funs('ROOTR'))");
}