ROOT_USE_PACKAGE(mpi/rmpi)

SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
#################
#MPI ENVIRONMENT#
#################
FIND_PACKAGE(MPI REQUIRED)

##################
#ROOT ENVIRONMENT#
##################
IF(${CMAKE_HOST_SYSTEM} MATCHES "Linux")
     INCLUDE(CMakeForceCompiler)
     CMAKE_FORCE_CXX_COMPILER(mpic++ "MPI C++ Compiler")
ENDIF()

add_subdirectory(rmpi)
# add_subdirectory(rmpimath)
add_subdirectory(rootmpi)
