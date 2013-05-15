# Build ${libname}
# Define all header and source files which are needed
# to build the RMpi library

FIND_PACKAGE(MPI REQUIRED)

ROOT_USE_PACKAGE(core/rint)
ROOT_USE_PACKAGE(net/net)
ROOT_USE_PACKAGE(io/io)
ROOT_USE_PACKAGE(misc/table)
ROOT_USE_PACKAGE(math/mathcore)
ROOT_USE_PACKAGE(math/mathmore)
ROOT_USE_PACKAGE(math/matrix)
ROOT_USE_PACKAGE(math/smatrix)
ROOT_USE_PACKAGE(math/physics)
ROOT_USE_PACKAGE(math/genvector)
ROOT_USE_PACKAGE(math/minuit)
ROOT_USE_PACKAGE(tree/tree)
ROOT_USE_PACKAGE(tree/treeplayer)
ROOT_USE_PACKAGE(graf3d/gl)

include_directories(${CMAKE_SOURCE_DIR}/mpi/rmpi/inc/Mpi ${CMAKE_SOURCE_DIR}/include)
add_definitions(-w)
set(libname RMpi)

##################
#ROOT ENVIRONMENT#
##################
IF(${CMAKE_HOST_SYSTEM} MATCHES "Linux")
INCLUDE(CMakeForceCompiler)
CMAKE_FORCE_CXX_COMPILER(mpic++ "MPI C++ Compiler")
ENDIF()

SET(RMPI_HEADERS RMpi.h
                 Mpi/TIntercomm.h
                 Mpi/TCommCintSendRecv.h
                 Mpi/TCommCintScatter.h
                 Mpi/TComm.h
                 Mpi/TUtils.h
                 Mpi/TInfo.h
                 Mpi/TFile.h
                 Mpi/TGroup.h
                 Mpi/TWin.h
                 Mpi/TFunctions.h
                 Mpi/TIntracomm.h
                 Mpi/TCommCintBcast.h
                 Mpi/TDatatype.h
                 Mpi/LinkDef_Functions.h
                 Mpi/TOp.h
                 Mpi/TMpiException.h
                 Mpi/TErrhandler.h
                 Mpi/TGraphcomm.h
                 Mpi/TStatus.h
                 Mpi/TEnvironment.h
                 Mpi/TMpiMessage.h
                 Mpi/TRequest.h
                 Mpi/TCommCintGather.h
                 Mpi/LinkDef_Globals.h
                 Mpi/TCartcomm.h
                 Mpi/LinkDef.h
                 Mpi/MTypes.h
)

SET(RMPI_SOURCES src/TOp.cxx
                 src/TEnvironment.cxx
                 src/TException.cxx
                 src/TMpiMessage.cxx
                 src/MTypes.cxx
                 src/TInfo.cxx
                 src/TDatatype.cxx
                 src/TComm.cxx
                 src/TCommObject.cxx
                 src/TGraphcomm.cxx
                 src/TCartcomm.cxx
                 src/TWin.cxx
                 src/TStatus.cxx
                 src/OpenMpiWinSupport.cxx
                 src/TFile.cxx
                 src/TIntracomm.cxx
                 src/TGroup.cxx
                 src/TRequest.cxx
                 src/TFunctions.cxx
                 src/TErrhandler.cxx
                 src/TComm.cxx
                 src/TIntercomm.cxx
)


ROOT_GENERATE_DICTIONARY(G__RMpi ${RMPI_HEADERS} LINKDEF inc/Mpi/LinkDef.h)
ROOT_GENERATE_DICTIONARY(G__RMpiGlobals ${RMPI_HEADERS} LINKDEF inc/Mpi/LinkDef_Globals.h)
ROOT_GENERATE_DICTIONARY(G__RMpiFunctions ${RMPI_HEADERS} LINKDEF inc/Mpi/LinkDef_Functions.h)

ROOT_GENERATE_ROOTMAP(${libname} LINKDEF Mpi/LinkDef.h  Mpi/LinkDef_Globals.h Mpi/LinkDef_Functions.h DEPENDENCIES Core Matrix MathCore Cint Rint Net RIO Hist MathMore GenVector Physics Graf3d RGL Table Tree TreePlayer Minuit)
ROOT_LINKER_LIBRARY(${libname} G__RMpi.cxx G__RMpiGlobals.cxx G__RMpiFunctions.cxx ${RMPI_SOURCES} LIBRARIES Core Matrix MathCore Cint Rint Net RIO Hist MathMore GenVector Physics Graf3d RGL Table Tree TreePlayer Minuit DEPENDENCIES Core Matrix MathCore Cint Rint Net RIO Hist MathMore GenVector Physics Graf3d RGL Table Tree TreePlayer Minuit)
ROOT_INSTALL_HEADERS()
