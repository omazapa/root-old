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
    .method( "Eval", &TRF1::Eval )
    .method( "Draw", &TRF1::Draw )    
    ;
}


void Class()
{
   ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
   r["rootr"]=LOAD_ROOTR_MODULE(rootr);
   
   r.Parse("TRF1 <- rootr$TRF1") ;
   r.Parse("u <- new(TRF1,'dilog','TMath::DiLog(x)')") ;
   r.Parse("print(u$Eval( 0.0 ))");
   r.Parse("u$Draw()");
}
