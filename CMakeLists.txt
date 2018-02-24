cmake_minimum_required(VERSION 3.5)
project(deadline24)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES main.cpp)
add_executable(deadline24_template template.cpp)

add_executable(taskA A.cpp)
add_executable(taskB B.cpp)
add_executable(taskC C.cpp)
add_executable(taskD D.cpp)
add_executable(taskE E.cpp)