# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Compile options
add_compile_options(-Wall -Wextra -Werror)

# Name of the project
project(QuantumWire)

# Include dir with .h files
include_directories(include)

# Add libraries
add_library(wire "src/wire.cpp")

# Add all the source files needed to build the executable
add_executable(exec src/main.cpp)

# Link targets and  executables
target_link_libraries(exec wire)
