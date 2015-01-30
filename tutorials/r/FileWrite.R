require(ROOT)
LoadModule('RIO')
LoadModule('Hist')
LoadModule('Gpad')

rfile <- new(TFile,'rfile.root','recreate')
gamma <- new(TF1,'gamma','TMath::Gamma(x)',0.1,2*pi)
gamma$Write('gamma')

hgaus <- new(TH1F,'hgaus','histo from a gaussian', 100, -3, 3)
hgaus$FillRandom('gaus',10000)
hgaus$Write('hgaus')

rfile$Flush()
rfile$Close()

