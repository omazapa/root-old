#include<TRInterface.h>
#include<vector>
#include<TArrayD.h>
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
   TArrayD arr= gR->ParseEval("c(0.0,0.1,0.2)").ToArray<TArrayD,Double_t>();
#else   
   TVectorD v = gR->ParseEval("c(1,2,3,4)").ToVector();
   std::vector<Double_t> sv=gR->ParseEval("c(1.01,2,3,4)").ToStdVector();
   TMatrixD m = gR->ParseEval("matrix(c(1,2,3,4),2,2)").ToMatrix();
   TArrayD arr=gR->ParseEval("c(0.0,0.1,0.2)").ToArray();
#endif   
   std::cout<<"-----------------------------------"<<std::endl;
   std::cout << s << std::endl;
   std::cout<<"-----------------------------------"<<std::endl;
   v.Print();
   std::cout<<"-----------------------------------"<<std::endl;
   for(int i=0;i<sv.size();i++) std::cout<<sv[i]<<" "<<std::endl;
   std::cout<<"-----------------------------------"<<std::endl;
   m.Print();
   std::cout<<"-----------------------------------"<<std::endl;
   std::cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<std::endl; 

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
   
   //////////////////
   //Handling Error//
   //////////////////
#if !defined(__ACLIC__)
   TString something=gR->ParseEval("qwerty").ToString();
//    int scalar=gR->ParseEval("qwerty").ToScalar();
//    std::vector<double> vec=gR->ParseEval("qwerty").ToStdVector();
//    TVectorD  tvec=gR->ParseEval("qwerty").ToVector();
//    TMatrixD mat=gR->ParseEval("qwerty").ToMatrix();
//    mat.Print();
#endif

}
