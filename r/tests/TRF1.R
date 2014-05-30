
x<-seq(0,2*pi,by=.001)
o<- ROOTR$TRF1('dilog','TMath::DiLog(x)')
plot(x,o$Eval(x))
x11()

o<- ROOTR$TRF1('lgamma','ROOT::Math::lgamma(x)')
plot(x,o$Eval(x))
