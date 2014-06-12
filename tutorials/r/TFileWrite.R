require(ROOTR)
gApplication$ProcessLine('#include<Math/SpecFuncMathMore.h>')#require to load MathMore's Special Function airy_Ai

rfile <- TFile('airy.root','create')
airy  <- TF1('airy','ROOT::Math::airy_Ai(x)')
airy$SetRange(0,2*pi)
airy$Write('airy',0,0)
rfile$Close('')

