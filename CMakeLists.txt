cmake_minimum_required(VERSION 3.6)
project(CompilerTask)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp scanner.h scanner.cpp)
add_executable(CompilerTask ${SOURCE_FILES})