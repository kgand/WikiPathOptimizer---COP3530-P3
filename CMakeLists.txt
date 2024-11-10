cmake_minimum_required(VERSION 3.10)
project(WikiPath)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add executable targets
add_executable(wikipath 
    src/main.cpp
    src/Graph.cpp
    src/BFS.cpp
    src/DFS.cpp
)

add_executable(test_graph
    tests/test_graph.cpp
    src/Graph.cpp
    src/BFS.cpp
    src/DFS.cpp
)

# Copy data files to build directory
file(COPY ${PROJECT_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})