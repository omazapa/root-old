gApp<-ROOTR$TRRint('ROOTR')
gApp$ProcessLine("#include<TRFile.h>")


x<-seq(0,2*pi,by=.1)
rfilein <- ROOTR$TRFile('airy.root','read')
f1 <- rfilein$Get('airy')
plot(x,f1$Eval(x))
rfilein$Close('')
