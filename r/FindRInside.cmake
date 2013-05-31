#Cmake module to find RInisde
# - Try to find Rinside
# Once done, this will define
#
#  RINSIDE_FOUND - system has RINSIDE
#  RINSIDE_INCLUDE_DIRS - the RINSIDE include directories
#  RINSIDE_LIBRARIES - link these to use RINSIDE
#Autor: Omar Andres Zapata Mesa 31/05/2013
include(LibFindMacros)

# Dependencies
libfind_package(RInside Rcpp)


set(RINSIDE_PKGCONF_INCLUDE_DIRS  usr/local/include /usr/include \
        /opt/R/site-library/RInside/include \
        /usr/local/lib/R/site-library/RInside/include \
        /usr/lib/R/site-library/RInside/include)

# Include dir
find_path(RINSIDE_INCLUDE_DIR
  NAMES RInside.h
  PATHS ${RINSIDE_PKGCONF_INCLUDE_DIRS}
)

set(RINSIDE_PKGCONF_LIBRARY_DIRS  /usr/local/lib /usr/lib \
        /opt/R/site-library/RInside/lib  /usr/local/lib/R/site-library/RInside/lib \
        /usr/lib/R/site-library/RInside/lib )

# Finally the library itself
find_library(RINSIDE_LIBRARY
  NAMES RInside
  PATHS ${RINSIDE_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(RINSIDE_PROCESS_INCLUDES RINSIDE_INCLUDE_DIR RCPP_INCLUDE_DIRS)
set(RINSIDE_PROCESS_LIBS RINSIDE_LIBRARY RCPP_LIBRARIES)
libfind_process(RInside)
