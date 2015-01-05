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

ROOTPKGPATH=paste(libname,pkgname,sep='/')
ROOTLIBPATH=paste(ROOTPKGPATH,'lib',sep='/')
ROOTLIBEXT = .Platform$dynlib.ext
if(Sys.info()['sysname'] == "Darwin"){ROOTLIBEXT=".dylib"}

assign("ROOTPKGPATH", ROOTPKGPATH, envir = .GlobalEnv,inherits = TRUE)
assign("ROOTLIBPATH", ROOTLIBPATH, envir = .GlobalEnv,inherits = TRUE)
assign("ROOTLIBEXT" , ROOTLIBEXT , envir = .GlobalEnv,inherits = TRUE)

LoadModule <- function(name){
  
  if(name=="Hist")
  {
      LIB=paste('Hist',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRHISTLIB          <- dyn.load(LIBPATH) 
      #calling classes from library
      ROOTR_TF1        <- Module("ROOTR_TRF1", PACKAGE=ROOTRHISTLIB,mustStart=TRUE)
      ROOTR_TGraph     <- Module("ROOTR_TRGraph", PACKAGE=ROOTRHISTLIB,mustStart=TRUE)
      TF1      <- ROOTR_TF1$TRF1
      TGraph   <- ROOTR_TGraph$TRGraph

      assign("TF1", TF1, envir = .GlobalEnv)
      assign("TGraph", TGraph, envir = .GlobalEnv)
  }
  if(name=="Core")
  {
      LIB=paste('Core',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRCORELIB      <- dyn.load(LIBPATH) 
      ROOTR_TRSystem    <- Module("ROOTR_TRSystem", PACKAGE=ROOTRCORELIB,mustStart=TRUE)
      TSystem  <- ROOTR_TRSystem$TRSystem
      assign("TSystem", TSystem, envir = .GlobalEnv)
  }
  if(name=="Rint")
  {
      LIB=paste('Rint',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRRINTLIB      <- dyn.load(LIBPATH) 
      ROOTR_TRRint      <- Module("ROOTR_TRRint", PACKAGE=ROOTRRINTLIB,mustStart=TRUE)
      TRint    <- ROOTR_TRRint$TRRint
      assign("TRint", TRint, envir = .GlobalEnv)
  }

  if(name=="Graf")
  {
      LIB=paste('Graf',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRGRAFLIB      <- dyn.load(LIBPATH) 
      ROOTR_TRCanvas    <- Module("ROOTR_TRCanvas", PACKAGE=ROOTRGRAFLIB,mustStart=TRUE)
      TCanvas    <- ROOTR_TRCanvas$TRCanvas
      assign("TCanvas", TCanvas, envir = .GlobalEnv)
  }
  
  if(name=="RIO")
  {
      LIB=paste('RIO',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRRIOLIB      <- dyn.load(LIBPATH) 
      ROOTR_TRFile    <- Module("ROOTR_TRFile", PACKAGE=ROOTRRIOLIB,mustStart=TRUE)
      TFile    <- ROOTR_TRFile$TRFile
      assign("TFile", TFile, envir = .GlobalEnv)
  }
  
  if(name=="BASE")
  {
      LIB=paste('BASE',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRBASELIB      <- dyn.load(LIBPATH) 
      ROOTR_TRObject    <- Module("ROOTR_TRObject", PACKAGE=ROOTRBASELIB,mustStart=TRUE)
      TRObject    <- ROOTR_TRObject$TRObject
      assign("TRObject", TRObject, envir = .GlobalEnv)

      ROOTR_TRMethod    <- Module("ROOTR_TRMethod", PACKAGE=ROOTRBASELIB,mustStart=TRUE)
      TRMethod    <- ROOTR_TRObject$TRMethod
      assign("TRMethod", TRMethod, envir = .GlobalEnv)
      
      ROOTR_TRList    <- Module("ROOTR_TRList", PACKAGE=ROOTRBASELIB,mustStart=TRUE)
      TRList    <- ROOTR_TRList$TRList
      assign("TRList", TRList, envir = .GlobalEnv)

      ROOTR_TRClass    <- Module("ROOTR_TRClass", PACKAGE=ROOTRBASELIB,mustStart=TRUE)
      TRClass    <- ROOTR_TRClass$TRClass
      assign("TRClass", TRClass, envir = .GlobalEnv)
  }
  
 }
assign("LoadModule", LoadModule, envir = .GlobalEnv)





#loading default modules
LoadModule("Rint")
LoadModule("Core")

#creating global variables
gApplication <- new(TRint,'ROOTR')
assign("gApplication", gApplication, envir = .GlobalEnv)

gSystem      <- new(TSystem)
assign("gSystem", gSystem, envir = .GlobalEnv)

#system to cast TObject into other ROOT classes
Cast <- function(class,obj)
{
  as(obj,class)
}

assign("Cast", Cast, envir = .GlobalEnv)



#starting Gui eventloop
gSystem$ProcessEventsLoop()
#creating  registers to clean memory when R ends the session 
reg.finalizer(.GlobalEnv, function(e){gApplication$Terminate(0)},TRUE) 
}
