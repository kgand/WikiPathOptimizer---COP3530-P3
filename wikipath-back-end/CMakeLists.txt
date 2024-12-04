cmake_minimum_required(VERSION 3.10)
project(WikiPathBackend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the executable
add_executable(WikiPathBackend ${SOURCES})

# Include directories for dependencies
include_directories(C:/Users/kjchi/vcpkg/installed/x64-windows/include)

# Link dependencies manually
target_link_libraries(WikiPathBackend PRIVATE 
    C:/Users/kjchi/vcpkg/installed/x64-windows/lib/restbed.lib
    C:/Users/kjchi/vcpkg/installed/x64-windows/lib/libssl.lib
    C:/Users/kjchi/vcpkg/installed/x64-windows/lib/libcrypto.lib
    fmt::fmt
    nlohmann_json::nlohmann_json
)

# Copy data directory to the build folder
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
