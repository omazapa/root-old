require(ROOTR)
gApp<-TRint('ROOTR')
gApp$ProcessLine('#include<Math/SpecFuncMathMore.h>')#loading MathMore to use Special Functions in TRF1 (required for airy)

x<-seq(0,2*pi,by=.1)
dilog<- TF1('dilog','TMath::DiLog(x)')
plot(x,dilog$Eval(x))
x11()

lgamma<- TF1('lgamma','ROOT::Math::lgamma(x)')
plot(x,lgamma$Eval(x))
x11()

airy<- TF1('airy','ROOT::Math::airy_Ai(x)')
plot(x,airy$Eval(x))

