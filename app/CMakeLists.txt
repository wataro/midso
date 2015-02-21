cmake_minimum_required(VERSION 2.8)
project(midso)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS -std=c++11)
include_directories(../include)
add_executable(${PROJECT_NAME} midso_main.cpp)

