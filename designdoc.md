# Design Document for Tensor Processing Library

## Objective

The aim of this project is to develop a tensor processing library in C++, with the intention of replacing NumPy functionalities in a Python-based neural network implementation.

##  System Architecture

The system is composed of two main parts: the core tensor processing library, written in C++, and the Python bindings for this library, created using pybind11. The core library is located in the `csrc/` directory, and the Python bindings are defined in `csrc/python_export.cpp`.

##  Core Library

The core library should be able to handle the following operations:

**Initialization**: Ability to initialize tensors of different dimensions and types. Functions this requires:

* `zeros`: Initialize a tensor of zeros.
* `ones`: Initialize a tensor of ones.
* `randn`: Initialize a tensor of random values.

**Addition/Subtraction**: Implement addition/subtraction of a tensor with a scalar, or two tensors.

**Multiplication/Division**: Implement multiplication/division of a tensor with a scalar, or two tensors.

**Matrix Multiplication**: Implement matrix multiplication of two tensors. Equivalent to `np.dot` in numpy.

**Item Assignment and Access**: Support for setting and getting the value of a tensor at a particular index.

**Slicing**: Support for slicing a tensor. Equivalent to `tensor[start:end]` in numpy.

**Reshaping**: Support for reshaping a tensor. Equivalent to `tensor.reshape` in numpy.

**Reduction**: Support for reducing a tensor along a particular axis. Equivalent to `np.sum`, `np.mean`,`np.max`.

**Transpose**: Equivalent to `tensor.T` in numpy.

##  Code Structure

* `CMakeLists.txt`: CMake file for building the C++ code and creating the Python bindings.
* `csrc/`: Contains the C++ source code for the tensor processing library.
* `csrc/python_export.cpp`: Defines the Python bindings using pybind11.
* `pybind11/`: Contains pybind11 as a git submodule.
* `python_neural_net/`: Contains the neural network Python code, which will eventually make use of the tensor processing library.
