# Set minimum CMake version
cmake_minimum_required(VERSION 3.15)

# Set project name, version and languages
project(test LANGUAGES C CXX Fortran)

# Include external projects
include(ExternalProject)

# Set project versions: major, minor and patch
set(TEST_VERSION_MAJOR "0")
set(TEST_VERSION_MINOR "1")
set(TEST_VERSION_PATCH "0")
set(TEST_VERSION "${TEST_VERSION_MAJOR}.${TEST_VERSION_MINOR}.${TEST_VERSION_PATCH}")

# Options
option(UNIT_TESTING "Enable unit tests" ON)
option(USE_MPI "Compile using MPI" ON)
option(USE_METIS "Compile using Metis" ON)
option(USE_SFC "Compile using GEMPA" ON)

# Folder with files configuring extra CMake options
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Configure MPI module
include(mpi)

# Set library types to be shared
set(LIBRARY_TYPE SHARED)

# Set a default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set compilation config for certain compilers
message(STATUS "CXX compiler: ${CMAKE_CXX_COMPILER_ID}")
## GNU compilers
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(CMAKE_C_FLAGS "-cpp")
	set(CMAKE_C_FLAGS_DEBUG "-g -Wall -Wextra -Wsign-conversion -Wold-style-cast")
	set(CMAKE_C_FLAGS_RELEASE "-O3 -march=native")
    set(CMAKE_CXX_FLAGS "-cpp")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wsign-conversion -Wold-style-cast")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native")
	set(CMAKE_Fortran_FLAGS "-cpp")
	set(CMAKE_Fortran_FLAGS_DEBUG "-g -Wall -Wextra -Wpedantic -fbacktrace -Wconversion-extra -ftrapv -fcheck=all")
	set(CMAKE_Fortran_FLAGS_RELEASE "-O3 -march=native")
## NVHPC compilers
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "NVHPC" OR CMAKE_CXX_COMPILER_ID STREQUAL "PGI")
	set(CMAKE_C_FLAGS "-cpp -DUSE_ACC -lstdc++ -lmpi_cxx -gpu=cc61,managed,lineinfo -acc -cuda -Minfo=all")
	set(CMAKE_C_FLAGS_DEBUG "-g -Minform=inform -C -Mbounds -Mchkstk -traceback -Ktrap=fp,unf")
	set(CMAKE_C_FLAGS_RELEASE "-fast")
    set(CMAKE_CXX_FLAGS "-cpp -DUSE_ACC -lstdc++ -lmpi_cxx -gpu=cc61,managed,lineinfo -acc -cuda -Minfo=all")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -Minform=inform -C -Mbounds -Mchkstk -traceback -Ktrap=fp,unf")
    set(CMAKE_CXX_FLAGS_RELEASE "-fast")
	set(CMAKE_Fortran_FLAGS "-cpp -DUSE_ACC -lstdc++ -lmpi_cxx -gpu=cc61,managed,lineinfo -acc -cuda -Minfo=all")
    set(CMAKE_Fortran_FLAGS_DEBUG "-g -Minform=inform -C -Mbounds -Mchkstk -traceback -Ktrap=fp,unf")
    set(CMAKE_Fortran_FLAGS_RELEASE "-fast")
endif()

# Set C/C++ standard
set(CMAKE_CXX_STANDARD 17)

# use, i.e. don't skip the full RPATH for the build tree
set(CMAKE_SKIP_BUILD_RPATH FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# the RPATH to be used when installing, but only if it's not a system directory
list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
if("${isSystemDir}" STREQUAL "-1")
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
endif("${isSystemDir}" STREQUAL "-1")

# Enable METIS if requested
include(metis)
if (USE_METIS)
  init_metis()
endif()

# Enable SFC if requested
include(gempa)
if (USE_SFC)
  init_gempa()
endif()

add_subdirectory(external)
add_subdirectory(src)

# Enable testing
if(UNIT_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
