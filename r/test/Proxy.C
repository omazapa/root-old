#include<TRInterface.h>
//script to test RExport a TRobjectProxy
void Proxy()
{
   gR->SetVerbose(kFALSE);
   //////////////////////////
   //Getting values from R //
   //////////////////////////
   std::cout << "======Getting values from R ======\n";
   TString  s = gR->parseEval("'ROOTR'").toString();
   TVectorD v = gR->parseEval("c(1,2,3,4)").toVector();
   TMatrixD m = gR->parseEval("matrix(c(1,2,3,4),2,2)").toMatrix();
   std::cout << s << std::endl;
   v.Print();
   m.Print();


   Double_t d = gR->parseEval("1.1").toScalar();
   Float_t  f = gR->parseEval("0.1").toScalar();
   Int_t    i = gR->parseEval("1").toScalar();
   std::cout << d << " " << f << " " << i << end::endl;

   /////////////////////////
   //Passing values to R  //
   /////////////////////////

   std::cout << "======Passing values to R ======\n";
   gR->assign(s, "s");
   gR->parse("print(s)");

   gR->assign(v, "v");
   gR->parse("print(v)");

   gR->assign(m, "m");
   gR->parse("print(m)");

   gR->assign(d, "d");
   gR->parse("print(d)");

   gR->assign(f, "f");
   gR->parse("print(f)");

   gR->assign(i, "i");
   gR->parse("print(i)");

}