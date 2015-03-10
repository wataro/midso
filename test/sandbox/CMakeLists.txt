cmake_minimum_required(VERSION 2.8)

project(sandbox)
find_package(CUDA REQUIRED)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS -std=c++11)
set(CUDA_NVCC_FLAGS -arch=compute_35;-code=sm_35)
set(CUDA_PROPAGATE_HOST_FLAGS OFF)
include_directories(..)
file(GLOB CUDA_SRC_FILES cuda_allocate.cu)
file(GLOB CXX_SRC_FILES test_cuda_unique_ptr.cpp ../gtest-all.cc ../gtest_main.cc)
cuda_add_executable(${PROJECT_NAME} ${CXX_SRC_FILES} ${CUDA_SRC_FILES})
target_link_libraries(${PROJECT_NAME} pthread)

