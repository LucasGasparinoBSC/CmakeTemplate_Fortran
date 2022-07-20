#ifndef LIBLIST_H
#define LIBLIST_H

// C/C++ standard libraries required
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#ifndef NO_MPI
#include <mpiEnvSet.h>
#endif // !NO_MPI

// List of app functions, routines and classes
#include "outputfunc.h"

// List of shared libraries
#include "vecFunc.h"
#include "matrixFunc.h"

#endif // !LIBLIST_H