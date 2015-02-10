cmake_minimum_required(VERSION 2.8)
project(test_midso)
add_executable(test_midso gtest_main.cc gtest-all.cc)
target_link_libraries(test_midso pthread)

