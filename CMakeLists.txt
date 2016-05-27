cmake_minimum_required(VERSION 3.5)
project(ArrayList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp utils utils/ArrayList.hpp)
add_executable(ArrayList ${SOURCE_FILES})