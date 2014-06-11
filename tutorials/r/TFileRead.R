require(ROOTR)

gApp<-TRRint('ROOTR')
gApp$ProcessLine('#include<Math/SpecFuncMathMore.h>')#require to load MathMore's Special Function airy_Ai

x<-seq(0,2*pi,by=.1)
rfilein <- TRFile('airy.root','read')
f1 <- rfilein$Get('airy')
plot(x,f1$Eval(x))
rfilein$Close('')
