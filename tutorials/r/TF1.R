require(ROOT)
ROOT::LoadModule('Hist')
gApplication$ProcessLine('#include<Math/SpecFuncMathMore.h>')#loading MathMore to use Special Functions in TF1 (required for lgamma)

dilog<- TF1('dilog','TMath::DiLog(x)')
dilog$SetRange(0,2*pi)
dilog$Draw('') #plotting with ROOT's graphics system

x<-seq(0,2*pi,by=.1)
lgamma<- TF1('lgamma','ROOT::Math::lgamma(x)')
plot(x,lgamma$Eval(x)) #plotting with R's graphics system
