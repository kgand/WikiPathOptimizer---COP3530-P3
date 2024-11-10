cmake_minimum_required(VERSION 3.10)
project(WikiPath)

# set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include directories
include_directories(include)

# add executable
add_executable(WikiPath 
    src/main.cpp 
    src/Graph.cpp 
    src/BFS.cpp 
    src/DFS.cpp 
    src/DataLoader.cpp 
    src/ArticleMapper.cpp 
    src/UI.cpp
)