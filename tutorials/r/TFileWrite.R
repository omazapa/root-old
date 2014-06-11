require(ROOTR)
gApp<-TRRint('ROOTR')
gApp$ProcessLine('#include<Math/SpecFuncMathMore.h>')#require to load MathMore's Special Function airy_Ai

rfile <- TRFile('airy.root','create')
airy  <- TRF1('airy','ROOT::Math::airy_Ai(x)')
airy$SetRange(0,2*pi)
airy$Write('airy',0,0)
rfile$Flush()
rfile$Close('')

