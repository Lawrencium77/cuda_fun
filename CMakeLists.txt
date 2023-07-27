cmake_minimum_required(VERSION 3.12)
project(Tensor)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(pybind11)
add_library(Tensor MODULE csrc/python_export.cpp csrc/Tensor.tpp)
set_target_properties(Tensor PROPERTIES PREFIX "") # remove prefix from shared object name
target_link_libraries(Tensor PRIVATE pybind11::module)
