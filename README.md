# WikiPath - Wikipedia Article Path Finder

## Team Members
- Khushi Chitalia
- Ananya Mundrathi
- Kovidh Gandreti

## Project Overview
WikiPath is a full-stack application that finds and compares efficient navigation paths between Wikipedia articles using different pathfinding algorithms (BFS and DFS). The project analyzes algorithm performance on a large dataset of Wikipedia articles and their connections.

## Getting Started

### Prerequisites
- **Node.js** (version 16 or higher)
- **C++ compiler** with C++11 support
- **CMake** (version 3.10 or higher)
- **Git**

### Running WikiPath

1. **Clone the repository:**
    ```bash
    git clone https://github.com/kgand/WikiPathOptimizer---COP3530-P3.git
    ```

#### Frontend Setup
1. Open a terminal
2. Navigate to the frontend directory:
   ```bash
   cd wikipath-front-end
   ```
3. Install dependencies:
   ```bash
   npm install
   ```
4. Start the frontend:
   ```bash
   npm start
   ```

#### Backend Setup
1. Install the Restbed API using VCPKG:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat   # For Windows
   ./bootstrap-vcpkg.sh    # For Linux/MAC OS
   .\vcpkg integrate install   # Windows only
   .\vcpkg install restbed
   ```
   > **Note:** After installation, ensure the Restbed header file in vcpkg/installed/x64-windows/include is named `restbed.h`

2. Open x64 Native Tools Command Prompt for VS 2022

3. Navigate to the backend directory:
   ```bash
   cd wikipath-back-end
   ```

4. Compile the backend (adjust paths accordingly):
   ```bash
   cl /std:c++17 /EHsc /I C:<path-to-vcpkg-installed-include> /I include test.cpp src/Graph.cpp src/BFS.cpp src/DFS.cpp /link /LIBPATH:C:<path-to-vcpkg-installed-lib> restbed-shared.lib /out:test.exe /MACHINE:X64
   ```

5. Run the backend:
   ```bash
   test.exe
   ```

6. Test the API:
   Open a browser and navigate to:
   ```
   http://localhost:8070/bfs?source=Dog&target=Shang%20Dynasty
   ```

## Features
- **Find shortest paths** between any two Wikipedia articles
- **Compare BFS and DFS algorithm performance**
- **Performance metrics tracking:**
  - Path length
  - Number of nodes visited
  - Execution time
  - Success rate
- **Modern web interface**
- **Article name mapping and validation**
- **Support for large datasets**

## Technical Architecture

### Backend (wikipath-back-end)
- **C++ Core Engine**
  - Graph processing
  - Pathfinding algorithms
  - Performance metrics collection
- **REST API Server**
  - Express.js wrapper for C++ core
  - RESTful endpoints for path finding
  - Performance data endpoints

### Frontend (wikipath-front-end)
- **React Application**
  - Modern UI/UX design
  - Real-time path visualization
  - Interactive article selection
  - Performance metrics display
- **TypeScript Implementation**
  - Type-safe development
  - Component-based architecture
  - State management

### Core Components
1. **Graph Implementation**
   - Custom Graph class for Wikipedia article network
   - Efficient article name to ID mapping
   - Adjacency list representation for connections

2. **Search Algorithms**
   - Breadth-First Search (BFS)
   - Depth-First Search (DFS)
   - Performance metrics tracking

3. **API Layer**
   - RESTful endpoints
   - JSON response formatting
   - Error handling middleware

4. **Frontend Components**
   - Article search interface
   - Path visualization
   - Performance comparison charts
   - Error handling and validation

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
1. Fork the respective repository (frontend or backend)
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request following our code review guidelines

## Acknowledgments
- **Wikispeedia Dataset Providers:** For supplying the navigation paths data
- **Open Source Community:** For the various libraries and tools used in this project
