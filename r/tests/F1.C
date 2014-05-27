//script to test TRFunction
#include<TRInterface.h>
#include<TMath.h>

std::string hello( std::string who, std::string msg){
    std::string result( "hello " ) ;
    result += who ;
    result += msg;
    return result ;
} 

ROOTR_MODULE(rootr){
    ROOT::R::function( "hello", &hello );
}

void F1()
{
   gR->SetVerbose(kFALSE);
   (*gR)["rootr"]=LOAD_ROOTR_MODULE(rootr);
   gR->ParseEval("print(rootr$hello('world ','ROOTR'))") ;
}
