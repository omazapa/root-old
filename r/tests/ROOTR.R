require( Rcpp )
ROOTSYS           <- Sys.getenv("ROOTSYS")
ROOTRLIB          <- dyn.load(paste(ROOTSYS,'lib/libRInterface.so',sep='/'))
ROOTR_TRF1        <- Module("ROOTR_TRF1", ROOTRLIB)
ROOTR_TRGraph     <- Module("ROOTR_TRGraph", ROOTRLIB)
ROOTR_TRCanvas    <- Module("ROOTR_TRCanvas", ROOTRLIB)

ROOTR <- c()
ROOTR$TRF1 <- function(name,formula){ new(ROOTR_TRF1$TRF1, name, formula) } 
ROOTR$TRGraph  <- function(n,x,y){ new(ROOTR_TRGraph$TRGraph, n,x,y) } 
ROOTR$TRCanvas  <- function(name,tittle=''){ new(ROOTR_TRCanvas$TRCanvas, name,tittle) }
ROOTR$InitX  <- function(){ ROOTR_InitX$InitX() }

x<-seq(0,2*pi,by=.1)
o<- ROOTR$TRF1('dilog','TMath::DiLog(x)')
plot(x,o$Eval(x))
