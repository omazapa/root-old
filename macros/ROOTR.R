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

# ROOTLIBSTATUS     <- FALSE
# ROOTRLIBPATH      <- paste(ROOTSYS,paste('lib/libRInterface',.Platform$dynlib.ext,sep=''),sep='/')
# if(file.exists(ROOTRLIBPATH)) { 
#   ROOTRLIB          <- dyn.load(ROOTRLIBPATH) 
#   ROOTLIBSTATUS     <- TRUE
# }
# 
# if(!ROOTLIBSTATUS)
# {
#   ROOTRLIBPATH      <- paste(ROOTSYS,paste('lib/root/libRInterface',.Platform$dynlib.ext,sep=''),sep='/')
#   if(file.exists(ROOTRLIBPATH)){
#       ROOTRLIB          <- dyn.load(ROOTRLIBPATH) 
#       ROOTLIBSTATUS     <- TRUE      
#     }else{
#       stop(paste('Can not find libRInterface',.Platform$dynlib.ext,sep=''))
#     }
# }
# 
# #calling classes from library
# ROOTR_TRF1        <- Module("ROOTR_TRF1", PACKAGE=ROOTRLIB,mustStart=TRUE)
# ROOTR_TRGraph     <- Module("ROOTR_TRGraph", PACKAGE=ROOTRLIB,mustStart=TRUE)
# ROOTR_TRCanvas    <- Module("ROOTR_TRCanvas", PACKAGE=ROOTRLIB,mustStart=TRUE)
# ROOTR_TRRint      <- Module("ROOTR_TRRint", PACKAGE=ROOTRLIB,mustStart=TRUE)
# ROOTR_TRFile      <- Module("ROOTR_TRFile", PACKAGE=ROOTRLIB,mustStart=TRUE)
# ROOTR_TRSystem    <- Module("ROOTR_TRSystem", PACKAGE=ROOTRLIB,mustStart=TRUE)
# 
# #creating a ROOTR module calling every submodule into a R's class
# TF1      <- function(name,formula,xmin = 0,xmax = 1){ new(ROOTR_TRF1$TRF1, name, formula,xmin,xmax) }
# TGraph   <- function(n,x,y){ new(ROOTR_TRGraph$TRGraph, n,x,y) }
# TCanvas  <- function(name,tittle='',form=1){ new(ROOTR_TRCanvas$TRCanvas, name,tittle,form) }
# TRint    <- function(name){ new(ROOTR_TRRint$TRRint, name) }
# TFile    <- function(fname,option='',ftitle='',compress=1){ new(ROOTR_TRFile$TRFile,fname,option,ftitle,compress) }
# TSystem  <- function(){new(ROOTR_TRSystem$TRSystem)}
# 
# #creating global bariables
# gApplication <- TRint('ROOTR')
# gSystem      <- TSystem()
# 
# #starting Gui eventloop
# gSystem$ProcessEventsLoop()

#creating  registers to clean memory when R ends the session 
# reg.finalizer(.GlobalEnv, function(e){gApplication$Terminate(0)},TRUE) 

