# Photonix Build Guide

This guide provides detailed instructions for building Photonix from source on all supported platforms.

## Table of Contents
- [System Requirements](#system-requirements)
- [Installing Prerequisites](#installing-prerequisites)
- [Building on Windows](#building-on-windows)
- [Building on Linux](#building-on-linux)
- [Building on macOS](#building-on-macos)
- [Troubleshooting](#troubleshooting)

---

## System Requirements

### Minimum Requirements
- **CPU**: Dual-core processor (2 GHz+)
- **RAM**: 4 GB
- **GPU**: OpenGL 3.3+ compatible graphics card
- **Disk Space**: 500 MB for build tools, 100 MB for Photonix

### Recommended Requirements
- **CPU**: Quad-core processor (3 GHz+)
- **RAM**: 8 GB or more
- **GPU**: Dedicated graphics card with OpenGL 4.0+
- **Disk Space**: 2 GB for development environment

---

## Installing Prerequisites

### Common Prerequisites (All Platforms)

#### CMake
**Version Required**: 3.20 or later

- **Windows**: Download from https://cmake.org/download/
- **Linux**: `sudo apt install cmake` (Ubuntu/Debian) or `sudo dnf install cmake` (Fedora)
- **macOS**: `brew install cmake`

Verify installation:
```bash
cmake --version
```

#### Git
- **Windows**: Download from https://git-scm.com/
- **Linux**: `sudo apt install git` or `sudo dnf install git`
- **macOS**: Included with Xcode Command Line Tools

Verify installation:
```bash
git --version
```

---

## Building on Windows

### Option 1: Visual Studio (Recommended)

#### Prerequisites
1. **Visual Studio 2019 or 2022** (Community Edition is free)
   - Download from: https://visualstudio.microsoft.com/
   - During installation, select "Desktop development with C++"

2. **Qt6 for MSVC**
   - Download Qt Online Installer: https://www.qt.io/download-open-source
   - Install Qt 6.5+ for MSVC 2019 64-bit
   - Note the installation path (e.g., `C:\Qt\6.5.3\msvc2019_64`)

3. **CMake** (see above)

#### Build Steps

1. **Clone the repository**
```cmd
git clone https://github.com/yourusername/photonix.git
cd photonix
```

2. **Set Qt path** (if not in PATH)
```cmd
set Qt6_DIR=C:\Qt\6.5.3\msvc2019_64
set PATH=%Qt6_DIR%\bin;%PATH%
```

3. **Create build directory**
```cmd
mkdir build
cd build
```

4. **Configure with CMake**
```cmd
cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_PREFIX_PATH=%Qt6_DIR% ..
```

5. **Build**
```cmd
cmake --build . --config Release
```

6. **Run**
```cmd
bin\Release\Photonix.exe
```

### Option 2: MinGW

#### Prerequisites
1. **MinGW-w64** (GCC for Windows)
   - Download from: https://www.mingw-w64.org/
   - Or use MSYS2: https://www.msys2.org/

2. **Qt6 for MinGW**
   - Install Qt 6.5+ for MinGW 64-bit

#### Build Steps
Same as Visual Studio, but use:
```cmd
cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH=C:\Qt\6.5.3\mingw_64 ..
cmake --build . --config Release
```

---

## Building on Linux

### Ubuntu / Debian

#### Prerequisites
```bash
# Update package list
sudo apt update

# Install build tools
sudo apt install build-essential cmake git

# Install Qt6 development packages
sudo apt install qt6-base-dev qt6-opengl-dev libgl1-mesa-dev

# Optional: Qt6 OpenGL Widgets (if not included)
sudo apt install libqt6openglwidgets6
```

#### Build Steps

1. **Clone the repository**
```bash
git clone https://github.com/yourusername/photonix.git
cd photonix
```

2. **Create build directory**
```bash
mkdir build
cd build
```

3. **Configure with CMake**
```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
```

4. **Build** (use all CPU cores)
```bash
make -j$(nproc)
```

5. **Run**
```bash
./bin/Photonix
```

### Fedora / Red Hat / CentOS

#### Prerequisites
```bash
# Install build tools
sudo dnf install cmake gcc-c++ git

# Install Qt6 development packages
sudo dnf install qt6-qtbase-devel qt6-qtopengl-devel mesa-libGL-devel
```

Build steps are the same as Ubuntu.

### Arch Linux

#### Prerequisites
```bash
# Install build tools and Qt6
sudo pacman -S base-devel cmake git qt6-base qt6-opengl
```

Build steps are the same as Ubuntu.

---

## Building on macOS

### Prerequisites

1. **Xcode Command Line Tools**
```bash
xcode-select --install
```

2. **Homebrew** (package manager)
   - Install from: https://brew.sh/

3. **Qt6 and CMake**
```bash
brew install qt@6 cmake
```

4. **Set Qt path**
```bash
export Qt6_DIR=$(brew --prefix qt@6)
export PATH=$Qt6_DIR/bin:$PATH
```

Add to `~/.zshrc` or `~/.bash_profile` for persistence:
```bash
echo 'export Qt6_DIR=$(brew --prefix qt@6)' >> ~/.zshrc
echo 'export PATH=$Qt6_DIR/bin:$PATH' >> ~/.zshrc
source ~/.zshrc
```

### Build Steps

1. **Clone the repository**
```bash
git clone https://github.com/yourusername/photonix.git
cd photonix
```

2. **Create build directory**
```bash
mkdir build
cd build
```

3. **Configure with CMake**
```bash
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=$Qt6_DIR ..
```

4. **Build**
```bash
make -j$(sysctl -n hw.ncpu)
```

5. **Run**
```bash
open ./bin/Photonix.app
```

Or from command line:
```bash
./bin/Photonix.app/Contents/MacOS/Photonix
```

---

## Troubleshooting

### Qt6 Not Found

**Error**: `CMake Error: Could not find a package configuration file provided by "Qt6"`

**Solution**:
- Ensure Qt6 is installed
- Set `CMAKE_PREFIX_PATH` to Qt installation directory
- Example (Linux): `cmake -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake/Qt6 ..`
- Example (Windows): `cmake -DCMAKE_PREFIX_PATH=C:\Qt\6.5.3\msvc2019_64 ..`

### OpenGL Not Found

**Error**: `Could not find OpenGL`

**Solution**:
- **Windows**: Install GPU drivers
- **Linux**: Install mesa-libGL-dev or equivalent
- **macOS**: OpenGL should be included with Xcode

### Qt OpenGLWidgets Not Found

**Error**: `Could not find Qt6OpenGLWidgets`

**Solution**:
- Ensure Qt6 OpenGL Widgets module is installed
- **Linux**: `sudo apt install libqt6openglwidgets6`
- **macOS**: Should be included with Qt6
- **Windows**: Reinstall Qt with OpenGL Widgets component

### Build Fails with "undefined reference"

**Solution**:
- Clean build directory: `rm -rf build/*`
- Reconfigure and rebuild
- Check that all Qt modules are installed

### Application Crashes on Startup

**Solution**:
- Check Qt DLLs are in PATH (Windows)
- Run with debug output: `./Photonix --verbose`
- Check GPU drivers are up to date
- Verify OpenGL version: `glxinfo | grep "OpenGL version"` (Linux)

### High DPI / Scaling Issues

**Solution**:
- Qt6 handles high DPI automatically
- If issues persist, set environment variable:
  ```bash
  export QT_AUTO_SCREEN_SCALE_FACTOR=1
  ```

---

## Advanced Build Options

### Debug Build
```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

### Custom Install Prefix
```bash
cmake -DCMAKE_INSTALL_PREFIX=/custom/path ..
cmake --build .
cmake --install .
```

### Enable Verbose Output
```bash
cmake --build . --verbose
```

### Parallel Build (specify jobs)
```bash
# Linux/macOS
make -j4

# Windows (Visual Studio)
cmake --build . --config Release -- /maxcpucount:4
```

---

## Verifying Build

After successful build, verify:

1. **Executable exists**
   - Windows: `build\bin\Release\Photonix.exe`
   - Linux/macOS: `build/bin/Photonix`

2. **Run application**
   - Main window should open
   - Menu bar should be functional
   - No crashes or errors

3. **Check version**
   - Help → About Photonix
   - Should show version 0.0.1

---

## Next Steps

- Read the [User Manual](user_manual.md)
- Explore the [Architecture Documentation](architecture.md)
- Start developing plugins: [Plugin Guide](plugin_guide.md)
- Contribute: [CONTRIBUTING.md](../CONTRIBUTING.md)

---

**Need Help?**
- GitHub Issues: https://github.com/yourusername/photonix/issues
- Discussions: https://github.com/yourusername/photonix/discussions
