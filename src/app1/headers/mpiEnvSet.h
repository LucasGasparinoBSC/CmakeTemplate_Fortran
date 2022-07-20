#ifndef MPIENVSET_H
#define MPIENVSET_H

#ifndef NO_MPI

#include <mpi.h>

void mpiInit(int *numRanks, int *rank);
void mpiEnd();

#endif // !NO_MPI

#endif // !MPIENVSET_H