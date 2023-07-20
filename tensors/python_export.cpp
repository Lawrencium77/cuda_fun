#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Tensor1D.h"

namespace py = pybind11;

PYBIND11_MODULE(Tensor1D, m)
{
     py::class_<Tensor1D<int>>(m, "Tensor1D")
         .def(py::init<int>())
         .def(py::init<int, bool>())
         .def("zero", &Tensor1D<int>::zero)
         .def("getSize", &Tensor1D<int>::getSize)
         .def("set_value", &Tensor1D<int>::set_value)
         .def("__getitem__", [](Tensor1D<int> &t, int index)
              { return t[index]; })
         .def("__setitem__", [](Tensor1D<int> &t, int index, int value)
              { t.set_value(index, value); })
         .def("__add__", [](Tensor1D<int> &t, int value)
              { return t + value; })
         .def("delete_data", &Tensor1D<int>::delete_data);
}
