#include <stdio.h>

__global__
void add(int n, float *x, float *y, float *out)
{
  for (int i = 0; i < n; i++) {
    out[i] = x[i] + y[i];
  }
}