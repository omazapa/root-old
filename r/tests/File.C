#include<TRInterface.h>

void File()
{
ROOT::R::TRInterface &r=ROOT::R::TRInterface::Instance();

r<<"rfilein <- ROOTR$TRFile('airy.root','read')";
r<<"trf1 <- rfilein$Get('airy')";
r<<"trf1$SetRange(0,2*pi)";
r<<"trf1$Draw()";
r<<"rfilein$Close('')";
}
