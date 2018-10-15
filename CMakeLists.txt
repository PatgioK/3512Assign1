cmake_minimum_required(VERSION 3.12)
project(3512Assign1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(3512Assign1 main.cpp matrix.cpp matrix.hpp matrixexceptions.cpp pagerank.cpp pagerank.hpp)