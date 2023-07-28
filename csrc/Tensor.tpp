#include <iostream>

template <typename T>
Tensor<T>::Tensor(std::vector<int> shape_) : shape(std::move(shape_))
{
    // Get size
    size = 1;
    for (int i = 0; i < shape.size(); i++)
    {
        size *= shape[i];
    }

    // Get ndim
    ndim = shape.size();

    // Get strides
    strides = std::vector<int>(shape.size());
    strides[shape.size() - 1] = 1;
    for (int i = shape.size() - 2; i >= 0; i--)
    {
        strides[i] = strides[i + 1] * shape[i + 1];
    }

    // Create storage
    data = std::vector<T>(size);
}