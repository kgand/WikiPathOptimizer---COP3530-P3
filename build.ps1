# Create build directory if it doesn't exist
if (!(Test-Path build)) {
    New-Item -ItemType Directory -Path build
}

# Get the current directory (project root)
$projectRoot = Get-Location

# Copy data files to build directory recursively and force overwriting existing files
Copy-Item -Path "$projectRoot\data" -Destination "$projectRoot\build" -Recurse -Force

# Navigate to the build directory to initiate the build process
Set-Location "$projectRoot\build"

# Compile the main application using absolute paths and include directories
g++ "$projectRoot\src\main.cpp" "$projectRoot\src\Graph.cpp" "$projectRoot\src\BFS.cpp" "$projectRoot\src\DFS.cpp" -I"$projectRoot\include" -o wikipath

# Compile the test program using absolute paths and include directories
g++ "$projectRoot\tests\test_graph.cpp" "$projectRoot\src\Graph.cpp" "$projectRoot\src\BFS.cpp" "$projectRoot\src\DFS.cpp" -I"$projectRoot\include" -o test_graph

# Return to the original project root directory after compilation
Set-Location $projectRoot