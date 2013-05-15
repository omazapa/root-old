# Build ${libname}
# Define all header and source files which are needed
# to build the rootmpi command

ROOT_USE_PACKAGE(mpi/rmpi)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include_directories(${CMAKE_SOURCE_DIR}/mpi/rootmpi/inc/)
add_definitions(-w)

##################
#ROOT ENVIRONMENT#
##################
IF(${CMAKE_HOST_SYSTEM} MATCHES "Linux")
INCLUDE(CMakeForceCompiler)
CMAKE_FORCE_CXX_COMPILER(mpic++ "MPI C++ Compiler")
ENDIF()


SET(ROOTMPI_SOURCES src/rootmpi.cpp src/TRun.cpp)
add_executable(rootmpi ${ROOTMPI_SOURCES})
target_link_libraries(rootmpi Core Rint Cint)
install(TARGETS rootmpi DESTINATION bin)