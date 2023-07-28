#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Tensor.h"

namespace py = pybind11;

PYBIND11_MODULE(Tensor, m)
{
     py::class_<Tensor<int>>(m, "TensorInt")
         .def(py::init<const std::vector<int> &>())
         .def_readwrite("data", &Tensor<int>::data)
         .def_readwrite("shape", &Tensor<int>::shape)
         .def_readwrite("strides", &Tensor<int>::strides)
         .def_readwrite("size", &Tensor<int>::size)
         .def_readwrite("ndim", &Tensor<int>::ndim);

     py::class_<Tensor<half>>(m, "TensorHalf")
         .def(py::init<const std::vector<int> &>())
         .def_readwrite("data", &Tensor<half>::data)
         .def_readwrite("shape", &Tensor<half>::shape)
         .def_readwrite("strides", &Tensor<half>::strides)
         .def_readwrite("size", &Tensor<half>::size)
         .def_readwrite("ndim", &Tensor<half>::ndim);

     py::class_<Tensor<float>>(m, "TensorFloat")
         .def(py::init<const std::vector<int> &>())
         .def_readwrite("data", &Tensor<float>::data)
         .def_readwrite("shape", &Tensor<float>::shape)
         .def_readwrite("strides", &Tensor<float>::strides)
         .def_readwrite("size", &Tensor<float>::size)
         .def_readwrite("ndim", &Tensor<float>::ndim);

     py::class_<Tensor<double>>(m, "TensorDouble")
         .def(py::init<const std::vector<int> &>())
         .def_readwrite("data", &Tensor<double>::data)
         .def_readwrite("shape", &Tensor<double>::shape)
         .def_readwrite("strides", &Tensor<double>::strides)
         .def_readwrite("size", &Tensor<double>::size)
         .def_readwrite("ndim", &Tensor<double>::ndim);
}
