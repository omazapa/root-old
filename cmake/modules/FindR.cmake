#Cmake module to find R 
# - Try to find R
# Once done, this will define
#
#  R_FOUND - system has R
#  R_INCLUDE_DIRS - the R include directories
#  R_LIBRARIES - link these to use R
#Autor: Omar Andres Zapata Mesa 31/05/2013

message(STATUS "Looking for R")

set(R_PKGCONF_INCLUDE_DIRS  
      "/usr/local/include" "/usr/include" 
      "/opt/R/include" "/usr/share/R/include"  
      "/usr/local/share/R/include")

# Include dir
find_path(R_INCLUDE_DIR
  NAMES R.h
  PATHS ${R_PKGCONF_INCLUDE_DIRS}
)

set(R_PKGCONF_LIBRARY_DIRS  "/usr/local/lib" "/usr/lib"
    "/opt/R/lib" "/usr/lib/R/lib/" "/usr/lib/R/lib/" )
# Finally the library itself
find_library(R_LIBRARY
  NAMES R
  PATHS ${R_PKGCONF_LIBRARY_DIRS}
)

# Setting up the results 
set(R_INCLUDE_DIRS ${R_INCLUDE_DIR})
set(R_LIBRARIES ${R_LIBRARY})
if (("${R_INCLUDE_DIR}" STREQUAL "") OR ("${R_LIBRARY}" STREQUAL "")) 
  set(R_FOUND FALSE)
  message(STATUS "Looking for R -- not found ")
else()
  set(R_FOUND TRUE)
  message(STATUS "Looking for R -- found")
endif()
