cmake_minimum_required(VERSION 3.12)
project(Tensor1D)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(pybind11)
add_library(Tensor1D MODULE python_export.cpp Tensor1D.tpp)
set_target_properties(Tensor1D PROPERTIES PREFIX "") # remove prefix from shared object name
target_link_libraries(Tensor1D PRIVATE pybind11::module)

