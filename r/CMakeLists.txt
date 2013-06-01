############################################################################
# CMakeLists.txt file for building ROOT R package
############################################################################
#Autor: Omar Andres Zapata Mesa 31/05/2013

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/r")

FIND_PACKAGE(R REQUIRED)
FIND_PACKAGE(Rcpp REQUIRED)
FIND_PACKAGE(RInside REQUIRED)

ROOT_USE_PACKAGE(core)
ROOT_USE_PACKAGE(cint)
ROOT_USE_PACKAGE(math/matrix)

message(STATUS  "${RCPP_LIBRARIES}" )
include_directories(${CMAKE_SOURCE_DIR}/r/inc ${R_INCLUDE_DIR} ${RCPP_INCLUDE_DIR} ${RINSIDE_INCLUDE_DIR})

set(R_HEADERS TRinterface.h TRObjectProxy.h)




ROOT_GENERATE_DICTIONARY(G__RInterface ${R_HEADERS} LINKDEF LinkDef.h)

ROOT_GENERATE_ROOTMAP(RInterface LINKDEF LinkDef.h)

add_definitions(-DUSE_ROOT_ERROR )

ROOT_LINKER_LIBRARY(RInterface *.cxx G__RInterface.cxx LIBRARIES ${R_LIBRARIES} ${RCPP_LIBRARIES} ${RINSIDE_LIBRARIES} DEPENDENCIES Core Cint Matrix)

ROOT_INSTALL_HEADERS()






