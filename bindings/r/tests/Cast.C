#include<TRInterface.h>
#ifndef ROOT_TF1
#include<TF1.h>
#endif

#ifndef ROOT_R_RExports
#include<RExports.h>
#endif

//________________________________________________________________________________________________________
/**
   This is TF1's wrapper class for R


   @ingroup R
*/


//namespace ROOT {
//   namespace R {
//      class TRObject: public TObject {
//      public:
//         TRObject():TObject(){};
//         TRObject(const TObject &obj):TObject(obj){};
//         TRObject(const TRObject &obj):TObject(obj){};
//         TString ClassName(){return TObject::ClassName();}
//         TString GetName(){return TObject::GetName();}
//         
//      };
//   }
//}
//ROOTR_EXPOSED_CLASS_INTERNAL(TRObject)

ROOTR_EXPOSED_CLASS(TObject)

ROOTR_MODULE(ROOTR_TRObject)
{
//   ROOT::R::class_<ROOT::R::TRObject>("TRObject", "Mother of all ROOT objects.")
//   .constructor()
//   .method("ClassName",&ROOT::R::TRObject::ClassName)
//   .method("GetName",&ROOT::R::TRObject::GetName);
   
   ROOT::R::class_<TObject>("TObject", "Mother of all ROOT objects.")
   .constructor();
//   .method("ClassName",&ROOT::R::TObject::ClassName)
//   .method("GetName",&ROOT::R::TRObject::GetName);
}

namespace ROOT
{
    namespace R
    {
//          typedef Rcpp::XPtr<TRObject> TRObjectPtr;
          typedef Rcpp::XPtr<TObject> TObjectPtr;
    }
}

namespace ROOT {
   namespace R {
      class TRF1: public TF1 {
      public:
         TRF1():TF1(){}
         TRF1(const TF1 &f1): TF1(f1) {}
         TRF1(TObjectPtr obj): TF1((const TF1 &)*obj) {}
         TRF1(TString name, TString formula, Double_t xmin = 0, Double_t xmax = 1):TF1(name.Data(), formula.Data(), xmin, xmax){}
         std::vector<Double_t> Eval(std::vector<Double_t> x);
         void Draw(){TF1::Draw();}
         void Draw(TString opt){TF1::Draw(opt.Data());}
         inline Int_t Write(const TString name) {
            return TF1::Write(name.Data());
         }
         inline Int_t Write(const TString name, Int_t option,Int_t bufsize) {
            return TF1::Write(name.Data(),option,bufsize);
         }
      };
   }
}

namespace Rcpp {
   template<> SEXP wrap(const TF1 &f)
   {
      return Rcpp::wrap(ROOT::R::TRF1(f));
   }
   template<> TF1 as(SEXP f)
   {
      return Rcpp::as<ROOT::R::TRF1>(f);
   }
}

ROOTR_EXPOSED_CLASS_INTERNAL(TRF1)

//______________________________________________________________________________
std::vector<Double_t> ROOT::R::TRF1::Eval(std::vector<Double_t> x)
{
   std::vector<Double_t> result(x.size());
   for (unsigned int i = 0; i < x.size(); i++) result[i] = TF1::Eval(x[i]);
   return result;
}


ROOTR_MODULE(ROOTR_TRF1)
{

   ROOT::R::class_<ROOT::R::TRF1>("TRF1", "1-Dim ROOT's function class")
   .constructor<TString , TString , Double_t, Double_t>()
   .constructor<ROOT::R::TObjectPtr>()
   .method("Eval", (std::vector<Double_t> (ROOT::R::TRF1::*)(std::vector<Double_t>))&ROOT::R::TRF1::Eval)
   .method("Eval", (Double_t (ROOT::R::TRF1::*)(Double_t))&ROOT::R::TRF1::Eval)
   .method("Draw", (void (ROOT::R::TRF1::*)())(&ROOT::R::TRF1::Draw))
   .method("Draw", (void (ROOT::R::TRF1::*)(TString))(&ROOT::R::TRF1::Draw))
   .method("SetRange", (void (ROOT::R::TRF1::*)(Double_t, Double_t))(&ROOT::R::TRF1::SetRange))
   .method("SetParameter", (void (ROOT::R::TRF1::*)(Int_t, Double_t))(&ROOT::R::TRF1::SetParameter))
   .method("Write", (Int_t(ROOT::R::TRF1::*)(TString, Int_t, Int_t))(&ROOT::R::TRF1::Write))
   .method("Write", (Int_t(ROOT::R::TRF1::*)(TString))(&ROOT::R::TRF1::Write))
   ;
}


void Cast()
{
    ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();
    
    r["ROOTR_TRObject"]<<LOAD_ROOTR_MODULE(ROOTR_TRObject);
    r["ROOTR_TRF1"]<<LOAD_ROOTR_MODULE(ROOTR_TRF1);
    r<<"TRObject <- ROOTR_TRObject$TRObject";
    r<<"TObject <- ROOTR_TRObject$TObject";
    r<<"TRF1 <- ROOTR_TRF1$TRF1";
    
    TF1 *f=new TF1("f","sin(x)");
    r["f"]<<ROOT::R::TObjectPtr(f);
    r<<"print(f)";
    r<<"fun <- new(TRF1,f)";
    r<<"print(fun)";
    r<<"fun$Draw()";
 
}