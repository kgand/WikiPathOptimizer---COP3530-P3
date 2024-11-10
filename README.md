# WikiPath - Wikipedia Article Path Finder

## Team Members
- Khushi Chitalia
- Ananya Mundrathi
- Kovidh Gandreti

## Project Overview
WikiPath is a C++ application that finds and compares efficient navigation paths between Wikipedia articles using different pathfinding algorithms (BFS and DFS). The project analyzes algorithm performance on a large dataset of Wikipedia articles and their connections.

## Features
- **Find shortest paths** between any two Wikipedia articles
- **Compare BFS and DFS algorithm performance**
- **Performance metrics tracking:**
  - Path length
  - Number of nodes visited
  - Execution time
  - Success rate
- **User-friendly command-line interface**
- **Article name mapping and validation**
- **Support for large datasets**

## Technical Architecture

### Data Structure
- **Graph representation using adjacency lists**
- **Article mapping system for efficient lookups**
- **Pre-computed shortest path matrix support**

### Core Components
1. **Graph Implementation**
   - Custom Graph class for Wikipedia article network
   - Efficient article name to ID mapping
   - Adjacency list representation for connections

2. **Search Algorithms**
   - Breadth-First Search (BFS)
   - Depth-First Search (DFS)
   - Performance metrics tracking

3. **Data Management**
   - ArticleMapper for efficient article lookup
   - DataLoader for parsing TSV files
   - Support for URL-encoded article names

4. **User Interface**
   - Interactive command-line interface
   - Path visualization
   - Performance metrics display

## Dataset
- **Source:** Wikispeedia Navigation Paths
- **Size:** 
  - 4,604 Wikipedia articles (nodes)
  - 119,882 navigation paths (edges)
- **File Format:** TSV (Tab-Separated Values)
- **Required Files:**
  - `articles.tsv`: List of all articles
  - `links.tsv`: Article connections
  - `shortest-path-distance-matrix.txt`: Pre-computed distances

## Getting Started

### Prerequisites
- **C++ compiler** with C++11 support
- **CMake** (version 3.10 or higher)
- **Make** (Unix) or **PowerShell** (Windows)
- **Git**

### Installation

#### Option 1: Using CMake (Unix/Linux/MacOS)
1. **Clone the repository:**
    ```bash
    git clone https://github.com/kgand/WikiPath.git
    cd WikiPath
    ```
2. **Create and enter build directory:**
    ```bash
    mkdir build && cd build
    ```
3. **Configure and build with CMake:**
    ```bash
    cmake ..
    make
    ```

#### Option 2: Using PowerShell (Windows)
1. **Open PowerShell** in the project directory.
2. **Run the build script:**
    ```powershell
    .\build.ps1
    ```

### Running WikiPath

#### Basic Usage
After building the project, you can run the application as follows:

```bash
./wikipath
```


### Running Tests
After building, run the test suite to verify the implementation:
```bash
./test_graph
```

### Build Scripts

#### CMake
The project uses CMake for building on Unix/Linux/MacOS systems. The `CMakeLists.txt` is configured to include necessary directories and compile the executable targets.

#### PowerShell Script (Windows)
For Windows users, a PowerShell script `build.ps1` is provided to automate the build process.

```powershell
# Create build directory if it doesn't exist
if (!(Test-Path build)) {
    New-Item -ItemType Directory -Path build
}

# Get the current directory (project root)
$projectRoot = Get-Location

# Copy data files to build directory
Copy-Item -Path "$projectRoot\data" -Destination "$projectRoot\build" -Recurse -Force

# Change to build directory
Set-Location "$projectRoot\build"

# Compile main program using absolute paths
g++ "$projectRoot\src\main.cpp" "$projectRoot\src\Graph.cpp" "$projectRoot\src\BFS.cpp" "$projectRoot\src\DFS.cpp" -I"$projectRoot\include" -o wikipath

# Compile test program using absolute paths
g++ "$projectRoot\tests\test_graph.cpp" "$projectRoot\src\Graph.cpp" "$projectRoot\src\BFS.cpp" "$projectRoot\src\DFS.cpp" -I"$projectRoot\include" -o test_graph

# Return to original directory
Set-Location $projectRoot
```

## Implementation Details

### Core Classes

#### Graph Class
- Manages article network structure
- Handles file loading and parsing
- Provides neighbor lookup functionality

#### ArticleMapper Class
- Maps between article names and indices
- Handles URL-encoded article names
- Provides efficient lookup operations

#### Search Algorithm Classes
- BFS and DFS implementations
- Path reconstruction
- Performance metrics collection

#### UI Class
- User input handling
- Result formatting and display
- Error handling and validation

### Testing
- **Graph Operations:** Ensures the graph is constructed correctly from data files
- **Path Validation:** Verifies the integrity of the found paths
- **Performance Benchmarking:** Measures the efficiency of BFS and DFS algorithms
- **Edge Case Handling:** Tests scenarios with no available paths or invalid inputs

### Future Improvements
- **Additional Pathfinding Algorithms:** Implement algorithms like A*, Dijkstra's for enhanced performance
- **Graphical User Interface (GUI):** Develop a GUI for better visualization and user interaction
- **Path Optimization Strategies:** Incorporate techniques to optimize found paths further
- **Real-time Wikipedia API Integration:** Fetch live data directly from Wikipedia for up-to-date information
- **Multi-threading Support:** Enhance performance by parallelizing graph traversal for large datasets

## Contributing
1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request


## Acknowledgments
- **Wikispeedia Dataset Providers:** For supplying the navigation paths data