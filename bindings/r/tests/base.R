require(ROOT)
ROOT::LoadModule('BASE')
c<-new(TRClass,'TF1',TRUE)
m<-c$GetListOfAllPublicMethods( TRUE)
m$GetSize( )
o22 <- m$At(22)
o22$ClassName( )

