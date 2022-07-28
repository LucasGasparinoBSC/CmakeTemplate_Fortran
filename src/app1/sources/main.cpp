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

    // Test wheter GEMPA can indeed be used
    msg = "Using library function GEMPA...";
    printMsg(msg);
    gempa::Partitioner P1;

    // See if the object can be modified
    msg = "Modifying the object...";
    printMsg(msg);
    P1.sdim = 2;
    std::cout << "P1.sdim: " << P1.sdim << std::endl;

    // Finalize MPI environment
    #ifndef NO_MPI
    mpiEnd();
    #endif // !NO_MPI

    // End program
    return 0;
}
