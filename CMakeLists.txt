cmake_minimum_required(VERSION 3.17)
project(2nd_course)

set(CMAKE_CXX_STANDARD 14)

add_executable(2nd_course
               main.cpp
               main_class.cpp
               source/Subvector.cpp
               headers/Subvector.h)
