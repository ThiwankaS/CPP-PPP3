cmake_minimum_required(VERSION 3.12)

project(test LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(test test.cpp)

target_compile_options(test PRIVATE 
    -Wall 
    -Wextra 
    -Werror 
    -Wpedantic 
    -Wshadow
)

