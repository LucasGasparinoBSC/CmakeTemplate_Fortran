#include "mpiEnvSet.h"

#ifndef NO_MPI
void mpiInit(int *numRanks, int *rank)
{
    // Initialize MPI
    MPI_Init(NULL, NULL);
    // Get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, numRanks);
    // Get the rank of the process
    MPI_Comm_rank(MPI_COMM_WORLD, rank);
}

void mpiEnd()
{
    // Finalize MPI
    MPI_Finalize();
}
#endif // !NO_MPI