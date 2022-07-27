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

// List of external libraries
#ifndef NO_METIS
#include "metis.h"
#endif // !NO_METIS

#endif // !LIBLIST_H