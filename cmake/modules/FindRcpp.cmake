#Cmake module to find Rcpp
# - Try to find Rcpp
# Once done, this will define
#
#  RCPP_FOUND - system has RCPP
#  RCPP_INCLUDE_DIRS - the RCPP include directories
#  RCPP_LIBRARIES - link these to use RCPP
#Autor: Omar Andres Zapata Mesa 31/05/2013

message(STATUS "Looking for Rcpp")

set(RCPP_PKGCONF_INCLUDE_DIRS  
	"/usr/local/include" "/usr/include"
	"/opt/R/site-library/Rcpp/include" 
        "/usr/local/lib/R/site-library/Rcpp/include" 
        "/usr/lib/R/site-library/Rcpp/include")

# Include dir
find_path(RCPP_INCLUDE_DIR
  NAMES Rcpp.h
  PATHS ${RCPP_PKGCONF_INCLUDE_DIRS}
)

set(RCPP_PKGCONF_LIBRARY_DIRS  
	"/usr/local/lib" "/usr/lib"
        "/opt/R/site-library/Rcpp/lib" 
        "/usr/local/lib/R/site-library/Rcpp/lib"
        "/usr/lib/R/site-library/Rcpp/lib" )

# Finally the library itself
find_library(RCPP_LIBRARY
  NAMES Rcpp
  PATHS ${RCPP_PKGCONF_LIBRARY_DIRS}
)


# Setting up the results 
set(RCPP_INCLUDE_DIRS ${RCPP_INCLUDE_DIR})
set(RCPP_LIBRARIES ${RCPP_LIBRARY})
if (("${RCPP_INCLUDE_DIR}" STREQUAL "") OR ("${RCPP_LIBRARY}" STREQUAL "")) 
  set(R_FOUND FALSE)
  message(STATUS "Looking for Rcpp -- not found ")
else()
  set(R_FOUND TRUE)
  message(STATUS "Looking for Rcpp -- found")
endif()
