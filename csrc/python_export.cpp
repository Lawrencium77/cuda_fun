#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Tensor.h"

namespace py = pybind11;

PYBIND11_MODULE(Tensor, m)
{
     py::class_<Tensor<int>>(m, "Tensor")
         .def(py::init<const std::vector<int> &>())
         .def_readwrite("data", &Tensor<int>::data)
         .def_readwrite("shape", &Tensor<int>::shape)
         .def_readwrite("strides", &Tensor<int>::strides)
         .def_readwrite("size", &Tensor<int>::size)
         .def_readwrite("ndim", &Tensor<int>::ndim);
}
