# 1. Setup and Project Name
cmake_minimum_required(VERSION 3.15)
project(SchrodingerSolver LANGUAGES CXX)

# 2. Require Modern C++ (C++20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Find our Python bridge
# This asks CMake to look inside your 'uv' environment for pybind11
find_package(pybind11 REQUIRED)

# 4. Create the output library
# This tells CMake: "Bake a Python module named 'schrodinger_cpp' 
# using these two C++ source files."
pybind11_add_module(schrodinger_cpp
    src/solver.cpp
    src/bindings.cpp
)

# 5. Connect the Headers
# This tells the compiler where to look when you write 
# #include "solver.hpp" or #include <Eigen/Dense>
target_include_directories(schrodinger_cpp PRIVATE 
    include
    extern/eigen
)