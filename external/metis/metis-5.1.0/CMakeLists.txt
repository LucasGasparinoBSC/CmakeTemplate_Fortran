cmake_minimum_required(VERSION 3.15)
project(METIS)

set(GKLIB_PATH "${CMAKE_SOURCE_DIR}/GKlib" CACHE PATH "path to GKlib")
set(SHARED TRUE CACHE BOOL "build a shared library")
set(METIS_INTEGER "32" CACHE STRING "Compiling with integers 32/64 bits")
set_property(CACHE METIS_INTEGER PROPERTY STRINGS 32 64)
set(METIS_REAL "64" CACHE STRING "Compiling with reals 32/64 bits")
set_property(CACHE METIS_REAL PROPERTY STRINGS 32 64)

if(MSVC)
  set(METIS_INSTALL FALSE)
else()
  set(METIS_INSTALL TRUE)
endif()

# Configure libmetis library.
if(SHARED)
  message("Building METIS shared library")
  set(METIS_LIBRARY_TYPE SHARED)
else()
  set(METIS_LIBRARY_TYPE STATIC)
endif(SHARED)

include(${GKLIB_PATH}/GKlibSystem.cmake)
# Add include directories.
include_directories(${GKLIB_PATH})
include_directories(include)
# Recursively look for CMakeLists.txt in subdirs.
add_subdirectory("include")
add_subdirectory("libmetis")
#add_subdirectory("programs")
