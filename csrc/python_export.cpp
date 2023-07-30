#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Tensor.h"

namespace py = pybind11;

template <typename T>
void declare_class(py::module &m, const std::string &typestr)
{
    using Class = Tensor<T>;
    std::string pyclass_name = "Tensor" + typestr;
    py::class_<Class>(m, pyclass_name.c_str())
        .def(py::init<const std::vector<int> &>())
        .def_readwrite("data", &Class::data)
        .def_readwrite("shape", &Class::shape)
        .def_readwrite("strides", &Class::strides)
        .def_readwrite("size", &Class::size)
        .def_readwrite("ndim", &Class::ndim);
}

PYBIND11_MODULE(Tensor, m)
{
    m.doc() = "Tensor class";
    declare_class<int>(m, "Int");
    declare_class<float>(m, "Float");
    declare_class<double>(m, "Double");
}
