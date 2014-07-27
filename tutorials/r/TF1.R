require(ROOT)
ROOT::LoadModule('Hist')
ROOT::LoadModule('Graf')
# gApplication$ProcessLine('#include<Math/SpecFuncMathMore.h>')#loading MathMore to use Special Functions in TF1 (required for lgamma)

c1    <- new(TCanvas,'c1','dilog',1)
dilog <- new(TF1,'dilog','TMath::DiLog(x)',0,0)
dilog$SetRange(0,2*pi)
dilog$Draw('') #plotting with ROOT's graphics system
c1$Update()
# x<-seq(0,2*pi,by=.1)
# lgamma<- new(TF1,'lgamma','ROOT::Math::lgamma(x)',0,2*pi)
# plot(x,lgamma$Eval(x)) #plotting with R's graphics system
