# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)
add_compile_options(-Wall -Wextra -Werror)

# Name of the project
project(Vector)
include_directories(include)

# Add libraries
add_library(vector "src/vector.cpp")
add_executable(exec src/main.cpp)

target_link_libraries(exec vector)
