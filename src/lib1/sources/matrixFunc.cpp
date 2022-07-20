double doubleInnerProduct(double *a, double *b, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += a[i * n + j] * b[i * n + j];
        }
    }
    return sum;
}