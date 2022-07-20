# cmake_template

## Definition

Small template for C/C++ and Fortran projects using CMake. Capable of building an app and associated libraries.

## Required

- CMake version 3.15 or higher;
- C and C++ compilers;
- OpenMPI version 1.10 or higher;

## Usage

The root CMakeLists.txt file looks for source code inside the "src" directory. Inside, another CMakeLists.txt indicates which folders contain projects, wheter it's an app or a library.
New apps and libraries must be added to the search list as well.

Apps and libraries are divided into "sources" and "headers" folders. The CMakeLists.txt associated will handle file location for *.c/*.cpp and *.h files.

If using VSCode, the easiest way is to set the MPI compiler set as a toolkit. Can be compiled without MPI by passing -USE_MPI=OFF to the CMake command.
