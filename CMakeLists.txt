cmake_minimum_required(VERSION 3.10)
project(BFS-toposort)

# Set C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(${PROJECT_SOURCE_DIR}/includes)

# Add source files
add_executable(out
    src/main.cpp
)
