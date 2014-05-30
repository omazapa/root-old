
gApp<-ROOTR$TRRint('ROOTR')
gApp$ProcessLine('#include<Math/SpecFuncMathMore.h>',1)#loading MathMore to use Special Functions in TRF1


x<-seq(0,2*pi,by=.1)
dilog<- ROOTR$TRF1('dilog','TMath::DiLog(x)')
plot(x,dilog$Eval(x))
x11()

lgamma<- ROOTR$TRF1('lgamma','ROOT::Math::lgamma(x)')
plot(x,lgamma$Eval(x))
x11()

airy<- ROOTR$TRF1('airy','ROOT::Math::airy_Ai(x)')
plot(x,airy$Eval(x))
