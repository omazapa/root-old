//Example to create class Functor
//Author: Omar Zapata
#include<TRInterface.h>
#include<TMath.h>
 
typedef Double_t (*Function)(Double_t);
 
//Functor class with the function inside
class MyFunctor{
public:
  MyFunctor(){
    //here is the function that I want.
    f=TMath::BesselY1;
  }
  Double_t doEval(Double_t x) {
    return f(x);
  }
private:
   Function f;
};

//Macro to create a module
ROOTR_MODULE(MyFunctorModule) {
    ROOT::R::class_<MyFunctor>( "MyFunctor" )
    //creating a default constructor
    .constructor()
    //adding the method doEval to eval the internal function
    .method( "doEval", &MyFunctor::doEval )
    ;
}
 
void Functor()
{
   ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
   
   //Loading module into R's enviornment
   r["MyFunctorModule"]<<LOAD_ROOTR_MODULE(MyFunctorModule);
   
   //creating a class variable from module
   r<<"MyFunctor <- MyFunctorModule$MyFunctor";
   //creating a MyFunctor's object
   r<<"u <- new(MyFunctor)";
   
   //printing values from Functor and Function
   r<<"print(sprintf('value in R = %f',u$doEval( 1 )))";
   std::cout<<"value in ROOT = "<<TMath::BesselY1(1)<<std::endl;
}