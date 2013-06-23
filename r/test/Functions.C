//script to test TRFunction
#include<TRInterface.h>
#include<TMath.h>
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


   gR->SetVerbose(kFALSE);

   gR->assign(ROOT::R::TRFunction(funv), "funv");
   gR->parse("print(funv(c(2,3)))");

   gR->assign(ROOT::R::TRFunction(funm), "funm");
   gR->parse("cat(funm(matrix(c(1,2,3,4),2,2)))");

   gR->assign(ROOT::R::TRFunction(funs), "funs");
   gR->parse("cat(funs('ROOTR'))");

   gR->assign(ROOT::R::TRFunction(TMath::DiLog), "DiLog");
   gR->parse("print(DiLog(2))");

   gR->parse("x <- seq(0,10,0.01)");
   gR->parse("y <- NULL ");
   gR->parse("for(i in seq(along=x)) { \
		y <- c(y,DiLog(i)) \
	     }");
   gR->x11();
   gR->plot("x,y");

}
