require( Rcpp )
.onLoad <- function(libname, pkgname){
   require("methods") 
   loadRcppModules()
}
#Loading the ROOTR Library to create a Module
ROOTSYS           <- Sys.getenv("ROOTSYS")
ROOTRLIBPATH      <- paste(ROOTSYS,paste('lib/libRInterface',.Platform$dynlib.ext,sep=''),sep='/')        
ROOTRLIB          <- dyn.load(ROOTRLIBPATH)
#calling classes from library
ROOTR_TRF1        <- Module("ROOTR_TRF1", ROOTRLIB)
ROOTR_TRGraph     <- Module("ROOTR_TRGraph", ROOTRLIB)
ROOTR_TRCanvas    <- Module("ROOTR_TRCanvas", ROOTRLIB)
ROOTR_TRRint      <- Module("ROOTR_TRRint", ROOTRLIB)
ROOTR_TRFile      <- Module("ROOTR_TRFile", ROOTRLIB)

#creating a ROOTR module calling every submodule into a R's class
ROOTR <- c()
ROOTR$TRF1      <- function(name,formula){ new(ROOTR_TRF1$TRF1, name, formula) } #X11 eventloop not working and Draw dont work
ROOTR$TRGraph   <- function(n,x,y){ new(ROOTR_TRGraph$TRGraph, n,x,y) } #X11 eventloop not working and Draw dont work
ROOTR$TRCanvas  <- function(name,tittle='',form=1){ new(ROOTR_TRCanvas$TRCanvas, name,tittle,form) } #X11 eventloop not working and Draw dont work
ROOTR$TRRint    <- function(name,args=c('')){ new(ROOTR_TRRint$TRRint, name,args) }
ROOTR$TRFile    <- function(fname,option='',ftitle='',compress=1){ new(ROOTR_TRFile$TRFile,fname,option,ftitle,compress) }
