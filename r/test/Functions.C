//script to test TRFunction
#include<TRInterface.h>

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

Double_t fun3(Double_t *x, Double_t *par)
{
   return x[0] * par[0];
}

Double_t fun4(Double_t x)
{
   return x * 3;;
}


void Functions()
{
   TF1 f1("f1", "x*x");
   TF1 f2("f2", "TMath::DiLog(x)");
   TF1 f3("f3", fun3, 0, 5, 1);
   TF1 f4("f4", "fun4(x)");


   gR->SetVerbose(kFALSE);

   gR->assign(ROOT::R::TRFunction(f1), "f1");
   gR->parseEval("f1(2)");

   gR->assign(f2);
   gR->parse("print(f2(2))");

   gR->assign(f3, "f3");
   gR->parse("print(f3(c(1),c(2)))");

   gR->assign(f4, "f4");
   gR->parse("print(f4(2))");

   gR->assign(ROOT::R::TRFunction(&funv), "funv");
   gR->parse("print(funv(c(2,3)))");

   ;
   gR->assign(ROOT::R::TRFunction(&funm), "funm");
   gR->parse("cat(funm(matrix(c(1,2,3,4),2,2)))");

   gR->assign(ROOT::R::TRFunction(&funs), "funs");
   gR->parse("cat(funs('ROOTR'))");
}
