#ifndef TENSOR1D_H
#define TENSOR1D_H

template <typename T>
class Tensor1D
{
private:
    T *data;
    int size;

public:
    // Constructor
    Tensor1D(int size, bool zeros = true);

    // Set data to zeros
    void zero();

    // Get size
    int getSize();

    // Set value
    void set_value(int index, T value);

    // Overload the [] operator
    T &operator[](int index);

    // Overload the + operator
    Tensor1D<T> &operator+(int value);

    // Delete data
    void delete_data();
};

#include "Tensor1D.tpp"
#endif