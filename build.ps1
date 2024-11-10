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