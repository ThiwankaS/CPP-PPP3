CMAKE_MINIMUM_REQUIRED(VERSION 3.12)

project(modern_cpp LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# Automatically find all source files in the src directory
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Create the executable using main.cpp and the found source files
add_executable(prog 
    main.cpp 
    ${SRC_FILES}
)

target_include_directories(prog PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(prog PRIVATE 
    -Wall
    -Werror
    -Wextra
    -Wpedantic
    -Wshadow
    -fsanitize=address,undefined
)

target_link_options(prog PRIVATE -fsanitize=address,undefined)
