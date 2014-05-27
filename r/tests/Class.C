//script to test Modules
#include<TRInterface.h>
#include<TMath.h>
#include<TF1.h>

class TRF1 {
private:  
  TF1 *f;
public:
  TRF1(std::string name,std::string formula){f=new TF1(name.c_str(),formula.c_str());}
  double Eval(double x) {
    return f->Eval(x);
  }
  void Draw(){
    f->Draw();
  }
};


ROOTR_MODULE(rootr) {
    Rcpp::class_<TRF1>( "TRF1" )
    .constructor<std::string,std::string>()
//     .field( "min", &Uniform::min )
//     .field( "max", &Uniform::max )
    .method( "Eval", &TRF1::Eval )
    .method( "Draw", &TRF1::Draw )    
//     .method( "range", &uniformRange )
    ;
}


void Class()
{
//    gR->SetVerbose(kFALSE);
   (*gR)["rootr"]=LOAD_ROOTR_MODULE(rootr);
   
   gR->Parse("TRF1 <- rootr$TRF1") ;
   gR->Parse("u <- new(TRF1,'dilog','TMath::DiLog(x)')") ;
   gR->Parse("print(u$Eval( 0.0 ))");
   gR->Parse("u$Draw()");
}
