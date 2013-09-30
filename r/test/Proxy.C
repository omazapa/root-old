#include<TRInterface.h>
#include<vector>
//script to test RExport a TRobjectProxy
void Proxy()
{
//   gR->SetVerbose(kTRUE);
   //////////////////////////
   //Getting values from R //
   //////////////////////////
   std::cout << "======Getting values from R ======\n";
   TString  s = gR->ParseEval("'ROOTR'").ToString();
#if defined(__ACLIC__)
   TVectorD v = gR->ParseEval("c(1,2,3,4)").ToVector<Double_t>();
   std::vector<Double_t> sv=gR->ParseEval("c(1.01,2,3,4)").ToStdVector<Double_t>();
   TMatrixD m = gR->ParseEval("matrix(c(1,2,3,4),2,2)").ToMatrix<Double_t>();
#else   
   TVectorD v = gR->ParseEval("c(1,2,3,4)").ToVector();
   std::vector<Double_t> sv=gR->ParseEval("c(1.01,2,3,4)").ToStdVector();
   TMatrixD m = gR->ParseEval("matrix(c(1,2,3,4),2,2)").ToMatrix();
#endif   
   std::cout<<"-----------------------------------"<<endl;
   std::cout << s << std::endl;
   std::cout<<"-----------------------------------"<<endl;
   v.Print();
   std::cout<<"-----------------------------------"<<endl;
   for(int i=0;i<sv.size();i++) std::cout<<sv[i]<<" "<<std::endl;
   std::cout<<"-----------------------------------"<<endl;
   m.Print();

#if defined(__ACLIC__)
   Double_t d = gR->ParseEval("1.1").ToScalar<Double_t>();
   Float_t  f = gR->ParseEval("0.1").ToScalar<Float_t>();
   Int_t    i = gR->ParseEval("1").ToScalar<Int_t>();
#else
   Double_t d = gR->ParseEval("1.1").ToScalar();
   Float_t  f = gR->ParseEval("0.1").ToScalar();
   Int_t    i = gR->ParseEval("1").ToScalar();
#endif   
   
   std::cout << d << " " << f << " " << i << std::endl;

   /////////////////////////
   //Passing values to R  //
   /////////////////////////

   std::cout << "======Passing values to R ======\n";
   gR->Assign(s, "s");
   gR->Parse("print(s)");
   std::cout<<"-----------------------------------"<<endl;
   
   (*gR)["v"]=v;
   gR->Parse("print(v)");
   std::cout<<"-----------------------------------"<<endl;

   gR->Assign(sv, "sv");
   gR->Parse("print(sv)");
   std::cout<<"-----------------------------------"<<endl;

   gR->Assign(m, "m");
   gR->Parse("print(m)");
   std::cout<<"-----------------------------------"<<endl;

   gR->Assign(d, "d");
   gR->Parse("print(d)");
   std::cout<<"-----------------------------------"<<endl;

   gR->Assign(f, "f");
   gR->Parse("print(f)");
   std::cout<<"-----------------------------------"<<endl;

   gR->Assign(i, "i");
   gR->Parse("print(i)");

}
