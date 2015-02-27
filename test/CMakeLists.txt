cmake_minimum_required(VERSION 2.8)
project(test_midso)
include_directories(../include ../src)
file(GLOB SRC_FILES ../src/midso/*.cpp *.cc midso/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} pthread)

