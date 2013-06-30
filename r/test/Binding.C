// Author: Omar Zapata
#include<TRInterface.h>
void Binding(){
ROOT::R::TRInterface r=gR->Instance();
r.SetVerbose(kFALSE);

//creating variables
TVectorD v(3);
TString str("ROOTR");
TMatrixD m(2,2);
Int_t i=9;
Double_t d=2.013;
Float_t f=0.013;

//assinging values
v[0]=0.01;
v[1]=1.01;
v[2]=2.01;

m[0][0]=0.01;
m[0][1]=1.01;
m[1][0]=2.01;
m[1][1]=3.01;

//testing operators binding
r["a"]=1;
r["v"]=v;
r["m"]=m;
(*gR)["b"]=123.456;
r["i"]=i;
r["d"]=d;
r["f"]=f;
r["s"]="ROOT";


//printting results
r.parse("print(a)");
cout<<"--------------------\n";
r.parse("print(v)");
cout<<"--------------------\n";
r.parse("print(m)");
cout<<"--------------------\n";
r.parse("print(b)");
cout<<"--------------------\n";
r.parse("print(i)");
cout<<"--------------------\n";
r.parse("print(d)");
cout<<"--------------------\n";
r.parse("print(f)");
cout<<"--------------------\n";
r.parse("print(s)");
cout<<"--------------------\n";

//reassigning the variable s
r["s"]=str;//string with string
r.parse("print(s)");

cout<<"--------------------\n";
r["d"]=str;//double with string
r.parse("print(d)");
}
