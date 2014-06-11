#/*************************************************************************
# * Copyright (C)  2014, Omar Andres Zapata Mesa                          *
# * All rights reserved.                                                  *
# *                                                                       *
# * For the licensing terms see $ROOTSYS/LICENSE.                         *
# * For the list of contributors see $ROOTSYS/README/CREDITS.             *
# *************************************************************************/
require( Rcpp )
#Loading the ROOTR Library to create a Module
ROOTSYS           <- Sys.getenv("ROOTSYS")
ROOTRLIBPATH      <- paste(ROOTSYS,paste('lib/libRInterface',.Platform$dynlib.ext,sep=''),sep='/')        
ROOTRLIB          <- dyn.load(ROOTRLIBPATH)
#calling classes from library
ROOTR_TRF1        <- Module("ROOTR_TRF1", PACKAGE=ROOTRLIB,mustStart=TRUE)
ROOTR_TRGraph     <- Module("ROOTR_TRGraph", PACKAGE=ROOTRLIB,mustStart=TRUE)
ROOTR_TRCanvas    <- Module("ROOTR_TRCanvas", PACKAGE=ROOTRLIB,mustStart=TRUE)
ROOTR_TRRint      <- Module("ROOTR_TRRint", PACKAGE=ROOTRLIB,mustStart=TRUE)
ROOTR_TRFile      <- Module("ROOTR_TRFile", PACKAGE=ROOTRLIB,mustStart=TRUE)
ROOTR_TRSystem    <- Module("ROOTR_TRSystem", PACKAGE=ROOTRLIB,mustStart=TRUE)

#creating a ROOTR module calling every submodule into a R's class
TF1      <- function(name,formula){ new(ROOTR_TRF1$TRF1, name, formula) } #X11 eventloop not working and Draw dont work
TGraph   <- function(n,x,y){ new(ROOTR_TRGraph$TRGraph, n,x,y) } #X11 eventloop not working and Draw dont work
TCanvas  <- function(name,tittle='',form=1){ new(ROOTR_TRCanvas$TRCanvas, name,tittle,form) } #X11 eventloop not working and Draw dont work
TRint    <- function(name){ new(ROOTR_TRRint$TRRint, name) }
TFile    <- function(fname,option='',ftitle='',compress=1){ new(ROOTR_TRFile$TRFile,fname,option,ftitle,compress) }
TSystem  <- function(){new(ROOTR_TRSystem$TRSystem)}

#creating global bariables
gSystem      <- TSystem()
gApplication <- TRint('ROOTR')
gSystem$ProcessEventsLoop();