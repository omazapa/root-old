#Cmake module to find Rcpp
# - Try to find Rcpp
# Once done, this will define
#
#  RCPP_FOUND - system has RCPP
#  RCPP_INCLUDE_DIRS - the RCPP include directories
#  RCPP_LIBRARIES - link these to use RCPP
#Autor: Omar Andres Zapata Mesa 31/05/2013
include(LibFindMacros)

# Dependencies
libfind_package(Rcpp R)


set(RCPP_PKGCONF_INCLUDE_DIRS  usr/local/include /usr/include \
        /opt/R/site-library/Rcpp/include \
        /usr/local/lib/R/site-library/Rcpp/include \
        /usr/lib/R/site-library/Rcpp/include)

# Include dir
find_path(RCPP_INCLUDE_DIR
  NAMES Rcpp.h
  PATHS ${RCPP_PKGCONF_INCLUDE_DIRS}
)

set(RCPP_PKGCONF_LIBRARY_DIRS  /usr/local/lib /usr/lib \
        /opt/R/site-library/Rcpp/lib  /usr/local/lib/R/site-library/Rcpp/lib \
        /usr/lib/R/site-library/Rcpp/lib )

# Finally the library itself
find_library(RCPP_LIBRARY
  NAMES Rcpp
  PATHS ${RCPP_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(RCPP_PROCESS_INCLUDES RCPP_INCLUDE_DIR R_INCLUDE_DIRS)
set(RCPP_PROCESS_LIBS RCPP_LIBRARY R_LIBRARIES)
libfind_process(Rcpp)
