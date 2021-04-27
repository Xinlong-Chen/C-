cmake_minimum_required(VERSION 3.17)
project(cpp_learn)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_learn main.cpp)
add_executable(ch1-0 src/cpp_base/ch1-cpp_base/00-形参带默认值函数/main.cpp)
add_executable(ch1-1 src/cpp_base/ch1-cpp_base/01-inline内联函数/main.cpp)
add_executable(ch1-2 src/cpp_base/ch1-cpp_base/02-函数重载/main.cpp)
add_executable(ch1-2-extern src/cpp_base/ch1-cpp_base/02-函数重载/extern.cpp src/cpp_base/ch1-cpp_base/02-函数重载/test.c)
add_executable(ch1-3 src/cpp_base/ch1-cpp_base/03-const/main.cpp)
add_executable(ch1-3-1 src/cpp_base/ch1-cpp_base/03-const/test.c)



add_executable(oop-0 src/cpp_oop/classWithoutPointer/test.cpp)
