require(ROOT)
gSystem$Load("libMathMore")#require to load MathMore's Special Function airy_Ai
rfilein <- TFile('airy.root','read')
f1 <- rfilein$Get('airy')
f1$Draw()
rfilein$Close('')
