gApp<-ROOTR$TRRint('ROOTR')
gApp$ProcessLine('#include<TRFile.h>')

rfile <- ROOTR$TRFile('airy.root','create')
airy  <- ROOTR$TRF1('airy','ROOT::Math::airy_Ai(x)')
airy$SetRange(0,2*pi)
airy$Write('airy',0,0)
rfile$Flush()
rfile$Close('')

