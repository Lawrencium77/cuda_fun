#include <iostream>

template <typename T>
class Tensor1D
{
private:
    T *data;
    int size;

public:
    Tensor1D(int size) : size(size)
    {
        data = new T[size];
    }

    int getSize()
    {
        return size;
    }

    void set_value(int index, T value)
    {
        data[index] = value;
    }

    // Overload the [] operator
    T &operator[](int index)
    {
        return data[index];
    }

    // Overload the + operator
    Tensor1D<T> &operator+(int value)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] += value;
        }
        return *this;
    }

    void delete_data()
    {
        delete[] data;
        size = 0;
    }
};

template <typename T>
void test(Tensor1D<T> tensor)
{
    // get size of tensor
    std::cout << "Size of tensor: " << tensor.getSize() << std::endl;

    // set index 2 of tensor to 10
    tensor.set_value(2, 5);
    std::cout << "Index number 2: " << tensor[2] << std::endl;

    // add 5 to all elements of tensor
    tensor + 5;
    std::cout << "Index number 2: " << tensor[2] << std::endl;

    // delete data in t
    tensor.delete_data();

    // check if data is deleted
    std::cout << "Size of tensor: " << tensor.getSize() << std::endl;
}

int main()
{
    Tensor1D<int> tensor(10);
    test(tensor);
    return 0;
}