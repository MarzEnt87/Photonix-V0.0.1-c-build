cmake_minimum_required(VERSION 3.20)
project(Photonix VERSION 0.0.1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Qt MOC, RCC, and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Photonix version: ${PROJECT_VERSION}")

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS 
    Core 
    Widgets 
    OpenGL 
    OpenGLWidgets
)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find Python3 (for plugin system - will be added in Milestone 5)
# find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/third_party
)

# Collect source files
file(GLOB_RECURSE CORE_SOURCES "src/core/*.cpp")
file(GLOB_RECURSE UI_SOURCES "src/ui/*.cpp")
file(GLOB_RECURSE RENDER_SOURCES "src/render/*.cpp")
file(GLOB_RECURSE TOOLS_SOURCES "src/tools/*.cpp")
file(GLOB_RECURSE PLUGINS_SOURCES "src/plugins/*.cpp")

# Collect header files
file(GLOB_RECURSE HEADERS "src/*.h")

# Main executable source
set(MAIN_SOURCE src/main.cpp)

# Combine all sources
set(ALL_SOURCES
    ${MAIN_SOURCE}
    ${CORE_SOURCES}
    ${UI_SOURCES}
    ${RENDER_SOURCES}
    ${TOOLS_SOURCES}
    ${PLUGINS_SOURCES}
    ${HEADERS}
)

# Create executable
add_executable(Photonix ${ALL_SOURCES})

# Link libraries
target_link_libraries(Photonix PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    OpenGL::GL
)

# Compiler warnings
if(MSVC)
    target_compile_options(Photonix PRIVATE /W4)
else()
    target_compile_options(Photonix PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Install targets
install(TARGETS Photonix
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

# Install assets
install(DIRECTORY ${CMAKE_SOURCE_DIR}/assets
    DESTINATION share/photonix
)

# Enable testing
enable_testing()

# Add subdirectory for tests (will be populated later)
# add_subdirectory(tests)

# Print configuration summary
message(STATUS "")
message(STATUS "=== Photonix Configuration Summary ===")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Qt6 version: ${Qt6_VERSION}")
message(STATUS "OpenGL found: ${OPENGL_FOUND}")
message(STATUS "======================================")
message(STATUS "")
