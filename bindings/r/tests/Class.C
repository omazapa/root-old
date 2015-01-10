//script to test Modules
#include<TRInterface.h>
#include<TMath.h>
#include<TF1.h>

class TRF1 {
private:  
  TF1 *f;
public:
  TRF1(std::string name,const char *formula){f=new TF1(name.c_str(),formula);}
//  double Eval(double x) {
//    return f->Eval(x);
//  }

  double Eval(double *x) {
    cout<<x[0]<<endl;
    return x[0];
  }

  void Draw(){
    f->Draw();
  }
};

//namespace Rcpp {
////   template<> SEXP wrap(const double *f)
////   {
////      return Rcpp::wrap(XPtr<double>(f));
////   }
//   template<> double* as(SEXP f)
//   {
//      return Rcpp::as<XPtr<double> >(f);
//   }
//   template<> int* as(SEXP f)
//   {
//      return Rcpp::as<XPtr<int> >(f);
//   }
//}

//namespace Rcpp
//{
//   namespace traits {
//      template <class T>
//      class Exporter<const T*> {
//      public:
//         Exporter(SEXP x):t(Rcpp::as<XPtr<const T> >(x)) {
//
//         }
//         const T* get() {
//            return t;
//         }
//      private:
//         XPtr<const T> t;
//      } ;
//   }
//}

ROOTR_MODULE(rootr) {
    ROOT::R::class_<TRF1>( "TRF1" )
    .constructor<std::string,const char*>()
    .method( "Eval", &TRF1::Eval )
    .method( "Draw", &TRF1::Draw )    
    ;
}


void Class()
{
   ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
   r.SetVerbose(true);
   r["rootr"]<<LOAD_ROOTR_MODULE(rootr);
//   double *a=new double[3];
//   double a[1];
   double *a=(double*)malloc(sizeof(double)*2);
   a[0]=9;
   r.AssignPtr(a,"a");
//   r["a"]=a;
   r<<"TRF1 <- rootr$TRF1";
   r<<"u <- new(TRF1,'dilog','TMath::DiLog(x)')";
   r<<"print(u$Eval( a ))";
//   r<<"u$Draw()";
}
