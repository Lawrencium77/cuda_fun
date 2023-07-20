#include <iostream>

template <typename T>
Tensor1D<T>::Tensor1D(int size, bool zeros) : size(size)
{
    data = new T[size];
    if (zeros)
    {
        zero();
    }
}

template <typename T>
void Tensor1D<T>::zero()
{
    for (int i = 0; i < size; i++)
    {
        data[i] = 0;
    }
}

template <typename T>
int Tensor1D<T>::getSize()
{
    return size;
}

template <typename T>
void Tensor1D<T>::set_value(int index, T value)
{
    data[index] = value;
}

template <typename T>
T &Tensor1D<T>::operator[](int index)
{
    if (index + 1 > size)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
Tensor1D<T> &Tensor1D<T>::operator+(int value)
{
    for (int i = 0; i < size; i++)
    {
        data[i] += value;
    }
    return *this;
}

template <typename T>
void Tensor1D<T>::show_data()
{
    std::cout << "Data: [";
    if (size > 0)
    {
        std::copy(data, data + size - 1, std::ostream_iterator<T>(std::cout, ", "));
        std::cout << data[size - 1];
    }
    std::cout << "]\n";
}

template <typename T>
void Tensor1D<T>::clear()
{
    delete[] data;
    size = 0;
}