// Author: Omar Zapata
#include<TRInterface.h>

Double_t Function(Double_t x)
{
  return x/(x-1);
}

void Binding(){
ROOT::R::TRInterface r=gR->Instance();
r.SetVerbose(kTRUE);
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
r["b"]=123.456;
r["i"]=i;
r["d"]=d;
r["f"]=f;
(*gR)["s"]="ROOT";


//printting results
gR->Parse("print(a)");
std::cout<<"--------------------\n";
gR->Parse("print(v)");
std::cout<<"--------------------\n";
gR->Parse("print(m)");
std::cout<<"--------------------\n";
gR->Parse("print(b)");
std::cout<<"--------------------\n";
gR->Parse("print(i)");
std::cout<<"--------------------\n";
gR->Parse("print(d)");
std::cout<<"--------------------\n";
gR->Parse("print(f)");
std::cout<<"--------------------\n";
gR->Parse("print(s)");
std::cout<<"--------------------\n";

//reassigning the variable s
r["s"]=str;//string with string
gR->Parse("print(s)");

std::cout<<"--------------------\n";
(*gR)["d"]=str;//double with string
gR->Parse("print(d)");

#if defined(__ACLIC__)
(*gR)["Function"]=ROOT::R::TRFunction(Function);
gR->Parse("print(Function(-1))");

gR->Parse("print(Function(1))");//division by zero producess Inf.
#else
#pragma message ( "Require ACLiC compilation to test Functions" )
#endif
}
