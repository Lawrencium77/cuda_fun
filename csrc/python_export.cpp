#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Tensor.h"

namespace py = pybind11;

PYBIND11_MODULE(Tensor, m)
{
     py::class_<Tensor<int>>(m, "Tensor")
         .def(py::init<>())
         .def(py::init<int>())
         .def(py::init<int, bool>())
         .def("zero", &Tensor<int>::zero)
         .def("getSize", &Tensor<int>::getSize)
         .def("set_value", &Tensor<int>::set_value)
         .def("__getitem__", [](Tensor<int> &t, int index)
              { return t[index]; })
         .def("__setitem__", [](Tensor<int> &t, int index, int value)
              { t.set_value(index, value); })
         .def("__add__", [](Tensor<int> &t, int value)
              { return t + value; })
         .def("show_data", &Tensor<int>::show_data)
         .def("clear", &Tensor<int>::clear);
}
