#include<TRInterface.h>

//script to test TRFunction
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

void Functions()
{
   TF1 f1("f1","x*x");
   TF1 f2("f1","TMath::DiLog(x)");
   gR->SetVerbose(kFALSE);
   
   gR->assign(ROOT::R::TRFunction(&funv), "funv");
   gR->parse("print(funv(c(2,3)))");

   gR->assign(ROOT::R::TRFunction(f1), "f1");
   gR->parse("print(f1(2))");
   
   gR->assign(ROOT::R::TRFunction(f2), "f2");
   gR->parse("print(f2(2))")
   ;
   gR->assign(ROOT::R::TRFunction(&funm), "funm");
   gR->parse("cat(funm(matrix(c(1,2,3,4),2,2)))");

   gR->assign(ROOT::R::TRFunction(&funs), "funs");
   gR->parse("cat(funs('ROOTR'))");
}
