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
ROOTSYS           <- Sys.getenv("ROOTSYS")
ROOTRMODPATH      <- paste(ROOTSYS,'r/mod/scripts/ROOTRCORE.R',sep='/')
source(ROOTRMODPATH)
}
