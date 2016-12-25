cmake_minimum_required(VERSION 3.6)
project(CompilerTask)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp scanner.h scanner.cpp analyse.h analyse.cpp mean.h mean.cpp recursive.h recursive.cpp)
add_executable(CompilerTask ${SOURCE_FILES})