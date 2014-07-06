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



}

LoadModule <- function(name){
  if(name=="Hist")
  {
      LIBHISTPATH=paste('../lib/Hist',.Platform$dynlib.ext,sep='')
      ROOTRHISTLIB          <- dyn.load(LIBHISTPATH) 
      #calling classes from library
      ROOTR_TRF1        <- Module("ROOTR_TRF1", PACKAGE=ROOTRHISTLIB,mustStart=TRUE)
      ROOTR_TRGraph     <- Module("ROOTR_TRGraph", PACKAGE=ROOTRHISTLIB,mustStart=TRUE)
      TF1      <- function(name,formula,xmin = 0,xmax = 1){ new(ROOTR_TRF1$TRF1, name, formula,xmin,xmax) }
      TGraph   <- function(n,x,y){ new(ROOTR_TRGraph$TRGraph, n,x,y) }
      assign("TF1", TF1, envir = .GlobalEnv)
      assign("TGraph", TGraph, envir = .GlobalEnv)
  }
}