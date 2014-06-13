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
ROOTMACROSTATUS   <- FALSE
ROOTSYSSTATUS     <- FALSE


ROOTSYS           <- Sys.getenv("ROOTSYS")

if(ROOTSYS=="") { warning("Environment's variable ROOTSYS is not set.") }

ROOTMACRO         <- paste(ROOTSYS,'macros/ROOTR.R',sep='/')
if(file.exists(ROOTMACRO))  
{
  source(ROOTMACRO)
  ROOTMACROSTATUS <- TRUE
}

if(!ROOTMACROSTATUS)
{
  ROOTMACRO       <- paste(ROOTSYS,'share/root/macros/ROOTR.R',sep='/')
  if(file.exists(ROOTMACRO))
  {
    source(ROOTMACRO)
    ROOTMACROSTATUS <- TRUE
  }
}

if(!ROOTMACROSTATUS) stop("The macro ROOTR.R can not be found.")
}

