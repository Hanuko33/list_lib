cmake_minimum_required(VERSION 3.10)
project(list_lib)
set(CMAKE_BUILD_TYPE DEBUG)
add_executable(list_test list.c test.c)
add_library(list SHARED list.c)

