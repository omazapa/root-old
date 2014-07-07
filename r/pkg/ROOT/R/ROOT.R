#/*************************************************************************
# * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
# * All rights reserved.                                                  *
# *                                                                       *
# * For the licensing terms see $ROOTSYS/LICENSE.                         *
# * For the list of contributors see $ROOTSYS/README/CREDITS.             *
# *************************************************************************/
require( Rcpp )
.onLoad <- function(libname, pkgname)
{
require("methods") 
loadRcppModules()

LoadModule <- function(name){
  ROOTPKGPATH=paste(libname,pkgname,sep='/')
  ROOTLIBPATH=paste(ROOTPKGPATH,'lib',sep='/')
  if(name=="Hist")
  {
      LIB=paste('Hist',.Platform$dynlib.ext,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRHISTLIB          <- dyn.load(LIBPATH) 
      #calling classes from library
      ROOTR_TRF1        <- Module("ROOTR_TRF1", PACKAGE=ROOTRHISTLIB,mustStart=TRUE)
      ROOTR_TRGraph     <- Module("ROOTR_TRGraph", PACKAGE=ROOTRHISTLIB,mustStart=TRUE)
      TF1      <- function(name,formula,xmin = 0,xmax = 1){ new(ROOTR_TRF1$TRF1, name, formula,xmin,xmax) }
      TGraph   <- function(n,x,y){ new(ROOTR_TRGraph$TRGraph, n,x,y) }
      assign("TF1", TF1, envir = .GlobalEnv)
      assign("TGraph", TGraph, envir = .GlobalEnv)
  }
  if(name=="Core")
  {
      LIB=paste('Core',.Platform$dynlib.ext,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRCORELIB      <- dyn.load(LIBPATH) 
      ROOTR_TRSystem    <- Module("ROOTR_TRSystem", PACKAGE=ROOTRCORELIB,mustStart=TRUE)
      TSystem  <- function(){new(ROOTR_TRSystem$TRSystem)}
      assign("TSystem", TSystem, envir = .GlobalEnv)
  }
  if(name=="Rint")
  {
      LIB=paste('Rint',.Platform$dynlib.ext,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRRINTLIB      <- dyn.load(LIBPATH) 
      ROOTR_TRRint      <- Module("ROOTR_TRRint", PACKAGE=ROOTRRINTLIB,mustStart=TRUE)
      TRint    <- function(name){ new(ROOTR_TRRint$TRRint, name) }
      assign("TRint", TRint, envir = .GlobalEnv)
  }

}

assign("LoadModule", LoadModule, envir = .GlobalEnv)

#loading default modules
LoadModule("Rint")
LoadModule("Core")

#creating global variables
gApplication <- TRint('ROOTR')
assign("gApplication", gApplication, envir = .GlobalEnv)

gSystem      <- TSystem()
assign("gSystem", gSystem, envir = .GlobalEnv)

#starting Gui eventloop
gSystem$ProcessEventsLoop()
}


