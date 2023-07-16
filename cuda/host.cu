#include <stdio.h>
#include <pybind11/pybind11.h>
#include "add.h"

float add_wrapper(int N)
{
  float *x, *y, *out, *d_x, *d_y, *d_out;
  x = (float *)malloc(N * sizeof(float));
  y = (float *)malloc(N * sizeof(float));
  out = (float *)malloc(N * sizeof(float));

  cudaMalloc(&d_x, N * sizeof(float));
  cudaMalloc(&d_y, N * sizeof(float));
  cudaMalloc(&d_out, N * sizeof(float));

  for (int i = 0; i < N; i++)
  {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  cudaMemcpy(d_x, x, N * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_y, y, N * sizeof(float), cudaMemcpyHostToDevice);

  // Execute the kernel
  add<<<1, 1>>>(N, d_x, d_y, d_out);

  cudaMemcpy(out, d_out, N * sizeof(float), cudaMemcpyDeviceToHost);

  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = max(maxError, fabs(out[i] - 3.0));

  cudaFree(d_x);
  cudaFree(d_y);
  cudaFree(d_out);
  free(x);
  free(y);
  free(out);

  return maxError;
}

PYBIND11_MODULE(example, m)
{
  m.def("add_static_arrays", &add_wrapper, "A function which adds two arrays");
}