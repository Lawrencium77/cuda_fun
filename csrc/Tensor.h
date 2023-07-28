#ifndef TENSOR_H
#define TENSOR_H

template <typename T>
class Tensor
{
public:
    // Attributes
    std::vector<T> data;
    std::vector<int> shape;
    std::vector<int> strides;
    int size;
    int ndim;

    // Constructor
    Tensor(std::vector<int> shape);
};

#include "Tensor.tpp"
#endif