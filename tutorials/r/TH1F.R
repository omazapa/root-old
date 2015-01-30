require(ROOT)
ROOT::LoadModule('Hist')
ROOT::LoadModule('Gpad')

c1    <- new(TCanvas,'c1','hgaus',1)
hgaus <- new(TH1F,'hgaus','histo from a gaussian', 100, -3, 3)
hgaus$FillRandom('gaus',10000)
hgaus$Draw('') #plotting with ROOT's graphics system
c1$Update()
