cmake_minimum_required(VERSION 3.5)
project(deadline24)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES main.cpp)

# Uncomment to enable DEBUG_LOGS
add_definitions(-DDEBUG_LOGS)

set(CMAKE_CXX_FLAGS "-std=c++14")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(template template.cpp)

add_executable(A A.cpp)
add_executable(B B.cpp)
add_executable(C C.cpp)
add_executable(D D.cpp)
add_executable(E E.cpp)

add_executable(tmp tmp.cpp)