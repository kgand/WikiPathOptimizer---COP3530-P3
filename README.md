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
- Compare algorithm performance based on various metrics.

## Distribution of Responsibility
- **Data Analysis:** Kovidh Gandreti
- **Algorithm Implementation:** Khushi Chitalia
- **Data Visualization:** Ananya Mundrathi
- **Performance Benchmarking:** Kovidh Gandreti
- **User Interface Design:** Ananya Mundrathi
- **Integration Testing:** Kovidh Gandreti
- **Backend System Architecture:** Kovidh Gandreti
- **Code Review Management:** Khushi Chitalia
- **Graph Structure Implementation:** Ananya Mundrathi
- **Reporting (Video/Documentation):** Khushi Chitalia

## Build and Run Instructions

### Prerequisites
- C++ compiler (supporting C++11)
- CMake

### Steps

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/WikiPath.git
   cd WikiPath
   ```

2. **Create a build directory:**
   ```bash
   mkdir build
   cd build
   ```

3. **Run CMake to configure the project:**
   ```bash
   cmake ..
   ```

4. **Build the project:**
   ```bash
   make
   ```

5. **Run the executable:**
   ```bash
   ./WikiPath
   ```

## Dataset
- Place the `wikispeedia-data.txt` file in the `data/` directory.

## Testing

### Running Test Cases

1. **Navigate to the build directory:**
   ```bash
   cd build
   ```

2. **Build the test executable:**
   ```bash
   g++ ../tests/test_graph.cpp -I../include -o test_graph
   ```

3. **Run the test:**
   ```bash
   ./test_graph
   ```

### Expected Output

Article 0: 1 -> NULL

Article 1: 0 -> 2 -> NULL

Article 2: 1 -> NULL
