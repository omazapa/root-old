############################################################################
# CMakeLists.txt file for building ROOT R package
############################################################################
#Autor: Omar Andres Zapata Mesa 31/05/2013

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/r")

FIND_PACKAGE(R REQUIRED)
FIND_PACKAGE(Rcpp REQUIRED)
FIND_PACKAGE(RInside REQUIRED)

ROOT_USE_PACKAGE(core)
ROOT_USE_PACKAGE(core/thread)
ROOT_USE_PACKAGE(cint)
ROOT_USE_PACKAGE(math/matrix)

if(${R_FOUND} AND ${RCPP_FOUND} AND ${RINSIDE_FOUND})

FILE(WRITE ${CMAKE_SOURCE_DIR}/r/inc/compilerdata.h
     "#define RINCLUDEPATH \" ${R_INCLUDE_DIRS} ${RCPP_INCLUDE_DIRS} ${RINSIDE_INCLUDE_DIRS} \"\n"
     "#define RLINKEDLIBS  \" ${R_LIBRARIES} ${RCPP_LIBRARIES} ${RINSIDE_LIBRARIES} \"\n")

include_directories(${CMAKE_SOURCE_DIR}/r/inc )
set(CMAKE_CXX_FLAGS "${CMAKE_CXXS_FLAGS} ${RCPP_INCLUDE_DIR} ${RINSIDE_INCLUDE_DIR} ${R_INCLUDE_DIR}")


set(R_HEADERS ${CMAKE_SOURCE_DIR}/r/inc/TRInterface.h 
              ${CMAKE_SOURCE_DIR}/r/inc/TRObjectProxy.h 
              ${CMAKE_SOURCE_DIR}/r/inc/TRFunction.h
              ${CMAKE_SOURCE_DIR}/r/inc/RExports.h
              ${CMAKE_SOURCE_DIR}/r/inc/compilerdata.h
              )
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
ROOT_GENERATE_DICTIONARY(G__RInterface ${R_HEADERS} LINKDEF LinkDef.h)

ROOT_GENERATE_ROOTMAP(RInterface LINKDEF LinkDef.h)

add_definitions(-DUSE_ROOT_ERROR )

ROOT_LINKER_LIBRARY(RInterface *.cxx G__RInterface.cxx LIBRARIES ${R_LIBRARIES} ${RINSIDE_LIBRARIES} DEPENDENCIES Core Cint Matrix Thread readline)
set_target_properties(RInterface PROPERTIES LINK_FLAGS ${RCPP_LIBRARIES})
ROOT_INSTALL_HEADERS()
endif()





