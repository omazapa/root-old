require(ROOT)
gSystem$Load("libMathMore")#require to load MathMore's Special Function airy_Ai
rfile <- TFile('airy.root','recreate')
airy  <- TF1('airy','ROOT::Math::airy_Ai(x)',0,2*pi)
airy$Write('airy')
rfile$Flush()
rfile$Close()

