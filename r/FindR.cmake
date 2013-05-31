#Cmake module to find R 
# - Try to find R
# Once done, this will define
#
#  R_FOUND - system has R
#  R_INCLUDE_DIRS - the R include directories
#  R_LIBRARIES - link these to use R
#Autor: Omar Andres Zapata Mesa 31/05/2013

include(LibFindMacros)

set(R_PKGCONF_INCLUDE_DIRS  /usr/local/include /usr/include \
        /opt/R/include /usr/share/R/include \
        /usr/local/share/R/include)

# Include dir
find_path(R_INCLUDE_DIR
  NAMES R.h
  PATHS ${R_PKGCONF_INCLUDE_DIRS}
)

set(R_PKGCONF_LIBRARY_DIRS  /usr/local/lib /usr/lib \
        /opt/R/lib /usr/lib/R/lib/ \
        /usr/lib/R/lib/ )
# Finally the library itself
find_library(R_LIBRARY
  NAMES R
  PATHS ${R_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(R_PROCESS_INCLUDES R_INCLUDE_DIR R_INCLUDE_DIRS)
set(R_PROCESS_LIBS R_LIBRARY R_LIBRARIES)
libfind_process(R)