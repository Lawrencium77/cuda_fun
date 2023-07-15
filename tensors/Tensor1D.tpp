template <typename T>
Tensor1D<T>::Tensor1D(int size) : size(size)
{
    data = new T[size];
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
void Tensor1D<T>::delete_data()
{
    delete[] data;
    size = 0;
}