cmake_minimum_required(VERSION 3.23)
project(system_programming_EX_5_A)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(sources)

add_executable(system_programming_EX_5_A
        sources/MagicalContainer.hpp
        Test.cpp)
