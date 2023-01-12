cmake_minimum_required(VERSION 3.16)
project(236360HW5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(236360HW5
        bp.cpp
        bp.hpp
        hw3_output.cpp
        hw3_output.hpp
        ir_translation.cpp
        ir_translation.h
        utilities.cpp
        utilities.hpp)
