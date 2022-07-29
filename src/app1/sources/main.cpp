#include "liblist.h"

//int main(int argc, char const *argv[])
int main()
{
    // Initialize MPI environment
    #ifndef NO_MPI
    int *numRank = new int;
    int *rank = new int;
    mpiInit(numRank, rank);
    printf("numRank: %d, rank: %d\n", *numRank, *rank);
    #endif // !NO_MPI

    // Define a string and test wheter the app1 mmessaging function works
    std::string msg = "Hello, World!";
    printMsg(msg);

    // Allocate and initialize arrays for testing the library lib1
    msg = "Messaging from output function...";
    printMsg(msg);
    const int n = 10;

    double *a = new double[n];
    double *b = new double[n];
    double *c = new double[n];
    double *d = new double[n*n];

    for (int i = 0; i < n; i++)
    {
        a[i] = 1.0;
        b[i] = 1.0;
    }

    // Test vecAdd function
    msg = "Using library function vecAdd...";
    printMsg(msg);
    vecAdd(a, b, c, n);
    msg = "a + b = :";
    printMsg(msg);
    printf("%lf\n", c[0]);

    // Test dotProduct function
    msg = "Using library function dotProduct...";
    printMsg(msg);
    double cdotc = dotProduct(c, c, n);
    msg = "c dot c = :";
    printMsg(msg);
    printf("%lf\n", cdotc);

    // Test tensorProductLinearized function
    msg = "Using library function tensorProductLinearized...";
    printMsg(msg);
    tensorProductLinearized(a, c, d, n);
    msg = "a otimes c = :";
    printMsg(msg);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            {
                printf("%lf ", d[i * n + j]);
            }
        printf("\n");
    }

    // Test doubleInnerProduct function
    msg = "Using library function doubleInnerProduct...";
    printMsg(msg);
    double DinnerD = doubleInnerProduct(d,d,n);
    msg = "D : D = :";
    printMsg(msg);
    printf("%lf\n", DinnerD);

    #ifndef NO_SFC
    // Test wheter GEMPA can indeed be used
    msg = "Using library function GEMPA...";
    printMsg(msg);
    gempa::Partitioner P1;

    // See if the object can be modified
    msg = "Modifying the object...";
    printMsg(msg);
    P1.sdim = 2;
    std::cout << "P1.sdim: " << P1.sdim << std::endl;
    #endif // !NO_SFC

    #ifndef NO_METIS
    // Testing wheter metis can be called
    msg = "Using library function METIS...";
    printMsg(msg);

    // Define a mesh to be partitioned
    idx_t nVertices = 6;
    idx_t nEdges = 7;
    idx_t nWeights = 1;
    idx_t nParts = 2;
    idx_t objval;
    idx_t part[nVertices];

    // Indexes of starting points in adjacent array
    idx_t xadj[nVertices+1] = {0,2,5,7,9,12,14};

    // Adjecent vertices inn consecutive index order
    idx_t adjncy[2*nEdges] = {1,3,0,4,2,1,5,0,4,3,1,5,4,2};

    // Weights of vertices
    // If all weights are equal they can be set to null
    idx_t vwgt[nVertices * nWeights];

    int ret = METIS_PartGraphKway(&nVertices,& nWeights, xadj, adjncy,
                                    NULL, NULL, NULL, &nParts, NULL,
                                    NULL, NULL, &objval, part);

    std::cout << ret << std::endl;

    for(unsigned part_i = 0; part_i < nVertices; part_i++){
	std::cout << part_i << " " << part[part_i] << std::endl;
    }

    #endif // !NO_METIS

    // Finalize MPI environment
    #ifndef NO_MPI
    mpiEnd();
    #endif // !NO_MPI

    // End program
    return 0;
}
