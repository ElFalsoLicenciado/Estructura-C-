cmake_minimum_required(VERSION 3.30)
project(Proyecto_U3)

set(CMAKE_CXX_STANDARD 20)

set(CPPLibs_INCLUDE_DIR C:/Users/User/Documents/CppLibs)

include_directories(${CPPLibs_INCLUDE_DIR})

add_executable(Proyecto_U3 main.cpp)
