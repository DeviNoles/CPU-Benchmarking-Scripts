# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(CPU_Benchmarking)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add each benchmark as a separate executable
add_executable(multithreading_test src/multithreading_test.cpp)
add_executable(cache_performance_test src/cache_performance_test.cpp)
add_executable(memory_bandwidth_test src/memory_bandwidth_test.cpp)
add_executable(floating_point_calculation_test src/floating_point_calculation_test.cpp)
add_executable(disk_io_performance_test src/disk_io_performance_test.cpp)
