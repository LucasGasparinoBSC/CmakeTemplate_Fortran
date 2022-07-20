#include "liblist.h"

int main()
{
    const int n=2;
    double *a = new double[n];
    double *b = new double[n];
    double *c = new double[n];
    double *d = new double[n*n];
    double *res_v = new double[n];
    double *res_t = new double[n*n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 1.0;
        b[i] = 2.0;
        res_v[i] = 3.0;
        for (int j = 0; j < n; j++)
        {
            res_t[i*n+j] = 3.0;
        }
    }
    vecAdd(a, b, c, n);
    for (int i = 0; i < n; i++)
    {
        if (c[i] != res_v[i])
        {
            std::cerr << "Error in vecAdd" << std::endl;
            return 1;
        }
    }
    tensorProductLinearized(a, c, d, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n; i++)
        {
            if (d[i * n + j] != res_t[i * n + j])
            {
                std::cerr << "Error in tensorProductLinearized" << std::endl;
                return 1;
            }
        }
    }

    delete a;
    delete b;
    delete c;
    delete d;
    delete res_v;
    delete res_t;

    return 0;
}
