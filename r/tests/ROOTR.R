require( Rcpp )
ROOTSYS           <- Sys.getenv("ROOTSYS")
ROOTRLIB          <- dyn.load(paste(ROOTSYS,'lib/libRInterface.so',sep='/'))
ROOTR_TRF1        <- Module("ROOTR_TRF1", ROOTRLIB)
ROOTR_TRGraph     <- Module("ROOTR_TRGraph", ROOTRLIB)
ROOTR_TRCanvas    <- Module("ROOTR_TRCanvas", ROOTRLIB)

ROOTR <- c()
ROOTR$TRF1 <- function(name,formula){ new(ROOTR_TRF1$TRF1, name, formula) } #X11 eventloop not working and Draw dont work
ROOTR$TRGraph  <- function(n,x,y){ new(ROOTR_TRGraph$TRGraph, n,x,y) } #X11 eventloop not working and Draw dont work
ROOTR$TRCanvas  <- function(name,tittle=''){ new(ROOTR_TRCanvas$TRCanvas, name,tittle) } #X11 eventloop not working and Draw dont work
