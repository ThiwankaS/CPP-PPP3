cmake_minimum_required(VERSION 3.12)

project(nullptr_explore LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(prog main.cpp)

target_compile_options(prog PRIVATE 
    -Wall 
    -Werror 
    -Wextra 
    -Wpedantic 
    -Wshadow 
    -fsanitize=address,undefined
)

target_link_options(prog PRIVATE -fsanitize=address,undefined)
