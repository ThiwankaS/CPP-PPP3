cmake_minimum_required(VERSION 3.12)

project(points_in_2D LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(point main.cpp Point2D.cpp Line2D.cpp)

target_compile_options(point PRIVATE
    -Wall
    -Wextra
    -Wall
    -Wpedantic
    -Wshadow
)
