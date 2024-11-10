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
- g++

### Steps

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/WikiPath.git
   cd WikiPath
   ```

2. **Ensure the data files are in place:**
   - `data/articles.tsv`: Contains article names (one per line).
   - `data/links.tsv`: Contains links in the format `source\target`.

3. **Compile the main program:**
   ```bash
   g++ src/main.cpp src/Graph.cpp src/BFS.cpp src/DFS.cpp src/DataLoader.cpp src/ArticleMapper.cpp src/UI.cpp -Iinclude -o WikiPath
   ```

4. **Run the executable:**
   ```bash
   ./WikiPath
   ```

5. **Compile and run the test cases:**
   ```bash
   g++ tests/test_graph.cpp src/Graph.cpp src/BFS.cpp src/DFS.cpp -Iinclude -o test_graph
   ./test_graph
   ```

## Dataset
Ensure that your `data/articles.tsv` and `data/links.tsv` are properly formatted and placed in the `data` directory as described above.
