cmake_minimum_required(VERSION 2.8)
project(midso CXX)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS -std=c++11)
include_directories(../include)
file(GLOB MIDSO_SRC_FILES ../src/midso/*/*.cpp ../src/midso/*/*/*.cpp)
add_library(${PROJECT_NAME} SHARED ${MIDSO_SRC_FILES})

