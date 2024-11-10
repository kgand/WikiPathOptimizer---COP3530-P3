# WikiPath

## Team Name
KAK

## Team Members
- Khushi Chitalia
- Ananya Mundrathi
- Kovidh Gandreti

## Problem Statement
Our project addresses and aims to optimize the seemingly endless navigation paths through Wikipedia articles by searching for the most efficient pathway by comparing pathfinding algorithms.

## Motivation
We seek to determine whether BFS or DFS has a better performance when using a data structure with a large dataset. This will help optimize search algorithms for graph traversal in various applications.

## Features
- Find the most efficient pathway from one Wikipedia article to another.
- Compare efficiency of human paths with algorithmically found paths.
- Metrics: Time complexity, space usage, path length, success rate, system response time, accuracy, memory optimization.

## Data
- **Dataset:** Wikispeedia Data
- **Nodes:** 4,604 Wikipedia articles
- **Edges:** 119,882 navigation paths

## Tools
- **Programming Language:** C++
- **Libraries:** STL, Boost Graph Library (BGL), LEMON, Gnuplot, Matplot++

## Strategy
- Represent data using a graph.
- Implement BFS and DFS algorithms for pathfinding.

## Setup
1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/WikiPath.git
   cd WikiPath
   ```

2. **Ensure data files are in the `data` directory:**
   - `articles.tsv`
   - `links.tsv`
   - `paths_finished.tsv`
   - `paths_unfinished.tsv`
   - `shortest-path-distance-matrix.txt`

## Build Instructions
1. **Compile the project:**
   ```bash
   g++ src/main.cpp src/Graph.cpp src/BFS.cpp src/DFS.cpp -Iinclude -o wikipath -lboost_graph
   ```

2. **Run the application:**
   ```bash
   ./wikipath
   ```

## Testing
1. **Compile and run the test cases:**
   ```bash
   g++ tests/test_graph.cpp src/Graph.cpp src/BFS.cpp src/DFS.cpp -Iinclude -o test_graph -lboost_graph
   ./test_graph
   ```

## Usage Example
Enter source article name: Algorithm

Enter target article name: Computer_science

BFS Results:

Path: Algorithm -> Computer_science

Path length: 2

Nodes visited: 15

Execution time: 23.0 microseconds

DFS Results:

Path: Algorithm -> Programming_language -> Computer_science

Path length: 3

Nodes visited: 25

Execution time: 31.0 microseconds
