#ifndef TENSOR_H
#define TENSOR_H

template <typename T>
class Tensor
{
private:
    T *data;
    int size;

public:
    // Constructor
    Tensor(int size = 0, bool zeros = true);

    // Set data to zeros
    void zero();

    // Get size
    int getSize();

    // Set value
    void set_value(int index, T value);

    // Overload the [] operator
    T &operator[](int index);

    // Overload the + operator
    Tensor<T> &operator+(int value);

    // Show data
    void show_data();

    // Delete data
    void clear();
};

#include "Tensor.tpp"
#endif