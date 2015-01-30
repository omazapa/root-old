require(ROOT)
LoadModule('RIO')
LoadModule('Hist')
LoadModule('Gpad')

rfilein <- new(TFile,'rfile.root','read')

gobj <- rfilein$Get('gamma')
print(gobj)
f1 <- new(TF1,gobj)
c1<-new(TCanvas,'c1','gamma')
f1$Draw()
c1$Update()

hobj  <- rfilein$Get('hgaus')
hgaus <- new(TH1F,hobj)
c2<-new(TCanvas,'c2','hgaus')
hgaus$Draw()
c2$Update()

rfilein$Close('')
