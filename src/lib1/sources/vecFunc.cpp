#include "vecFunc.h"

void vecAdd(double *a, double *b, double *c, int n)
{
    for (int i = 0; i < n; i++)
        c[i] = a[i] + b[i];
}

double dotProduct(double *a, double *b, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    return sum;
}

void tensorProductLinearized(double *a, double *b, double *c, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i * n + j] = a[i] * b[j];
}