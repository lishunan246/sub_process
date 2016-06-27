cmake_minimum_required(VERSION 3.5)
project(sub_process)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(sub_process ${SOURCE_FILES})