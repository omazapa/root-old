require(ROOT)
ROOT::LoadModule('Hist')
ROOT::LoadModule('Gpad')

c1    <- new(TCanvas,'c1','dilog',1)
dilog <- new(TF1,'dilog','TMath::DiLog(x)',0,2*pi)
dilog$SetRange(0,2*pi)
dilog$Draw('') #plotting with ROOT's graphics system
c1$Update()
