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
      Hist        <- Module("Hist", PACKAGE=ROOTRHISTLIB,mustStart=TRUE)
      TH1F     <- Hist$TH1F
      TF1      <- Hist$TF1
      TGraph   <- Hist$TGraph

      assign("TH1F", TH1F, envir = .GlobalEnv)
      assign("TF1", TF1, envir = .GlobalEnv)
      assign("TGraph", TGraph, envir = .GlobalEnv)
  }
  if(name=="Core")
  {
      LIB=paste('Core',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRCORELIB      <- dyn.load(LIBPATH) 
      Core     <- Module("Core", PACKAGE=ROOTRCORELIB,mustStart=TRUE)
      TSystem  <- Core$TSystem
      assign("TSystem", TSystem, envir = .GlobalEnv)
      TObject    <- Core$TObject
      assign("TObject", TObject, envir = .GlobalEnv)

  }
  if(name=="Rint")
  {
      LIB=paste('Rint',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRRINTLIB      <- dyn.load(LIBPATH) 
      Rint      <- Module("Rint", PACKAGE=ROOTRRINTLIB,mustStart=TRUE)
      TRint    <- Rint$TRint
      assign("TRint", TRint, envir = .GlobalEnv)
  }

  if(name=="Gpad")
  {
      LIB=paste('Gpad',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRGRAFLIB      <- dyn.load(LIBPATH) 
      Gpad    <- Module("Gpad", PACKAGE=ROOTRGRAFLIB,mustStart=TRUE)
      TCanvas    <- Gpad$TCanvas
      assign("TCanvas", TCanvas, envir = .GlobalEnv)
  }
  
  if(name=="RIO")
  {
      LIB=paste('RIO',ROOTLIBEXT,sep='')
      LIBPATH=paste(ROOTLIBPATH,LIB,sep='/')
      ROOTRRIOLIB      <- dyn.load(LIBPATH) 
      RIO    <- Module("RIO", PACKAGE=ROOTRRIOLIB,mustStart=TRUE)
      TFile    <- RIO$TFile
      assign("TFile", TFile, envir = .GlobalEnv)
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
CastObject <- function(class,obj)
{
    new(class,obj)
}

assign("CastObject", CastObject, envir = .GlobalEnv)



#starting Gui eventloop
gSystem$ProcessEventsLoop()
#creating  registers to clean memory when R ends the session 
reg.finalizer(.GlobalEnv, function(e){gApplication$Terminate(0)},TRUE) 
}
