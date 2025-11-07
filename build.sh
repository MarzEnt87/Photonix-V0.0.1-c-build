#!/bin/bash
# Photonix Build Script
# This script simplifies the build process

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}    Photonix Build Script v0.0.1${NC}"
echo -e "${GREEN}========================================${NC}"
echo ""

# Check for CMake
if ! command -v cmake &> /dev/null; then
    echo -e "${RED}Error: CMake not found!${NC}"
    echo "Please install CMake 3.20 or later"
    exit 1
fi

echo -e "${GREEN}✓ CMake found:${NC} $(cmake --version | head -n1)"

# Default build type
BUILD_TYPE=${1:-Release}

echo -e "${YELLOW}Build type:${NC} $BUILD_TYPE"
echo ""

# Create build directory
if [ -d "build" ]; then
    echo -e "${YELLOW}Build directory exists. Cleaning...${NC}"
    rm -rf build
fi

mkdir build
cd build

# Configure
echo -e "${GREEN}Configuring project...${NC}"
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE .. || {
    echo -e "${RED}Configuration failed!${NC}"
    exit 1
}

# Build
echo ""
echo -e "${GREEN}Building Photonix...${NC}"
cmake --build . --config $BUILD_TYPE || {
    echo -e "${RED}Build failed!${NC}"
    exit 1
}

# Success
echo ""
echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}  Build completed successfully! 🎉${NC}"
echo -e "${GREEN}========================================${NC}"
echo ""
echo -e "Executable: ${GREEN}build/bin/Photonix${NC}"
echo ""
echo "To run: ./build/bin/Photonix"
echo ""
