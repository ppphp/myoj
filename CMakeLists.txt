
cmake_minimum_required(VERSION 3.3)
project(myoj)

set(num p1007)

add_executable(myoj poj//${num}//${num}.cpp)
add_compile_options(-std=c++11)