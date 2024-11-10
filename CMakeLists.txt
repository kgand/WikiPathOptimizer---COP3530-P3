cmake_minimum_required(VERSION 3.10)
project(Wikipath)

# set the c++ standard to c++11 and enforce its usage
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# add executable target for the main application
add_executable(wikipath 
    src/main.cpp
    src/Graph.cpp
    src/BFS.cpp
    src/DFS.cpp
)

# add executable target for the graph testing program
add_executable(test_graph
    tests/test_graph.cpp
    src/Graph.cpp
    src/BFS.cpp
    src/DFS.cpp
)

# copy data files to the build directory to ensure they're available during execution
file(COPY ${PROJECT_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})