# Photonix

**Professional-grade open-source photo editing suite**

Version: 0.0.1 (Development)  
License: GPL v3

---

## Overview

Photonix is a lightweight, modern, and extensible photo editor designed to be:
- **Portable**: Download, extract, and run without complex installation
- **Professional**: Powerful editing tools for photographers and digital artists
- **Extensible**: Python plugin system for custom tools and AI integration
- **Cross-platform**: Windows, Linux, and macOS support

## Features (v0.0.1 - In Development)

### Current Status (Milestone 1: Complete ✓)
- [x] Project structure and build system
- [x] Main window with menu bar
- [x] Toolbar with quick actions
- [x] Dock panels (Tools, Layers, Properties) - placeholders
- [x] Status bar
- [x] Settings persistence

### Upcoming (Milestones 2-6)
- [ ] OpenGL-accelerated canvas (Milestone 2)
- [ ] Image I/O (PNG, JPEG, TIFF) (Milestone 3)
- [ ] Layer system (Milestone 3)
- [ ] Basic tools: Brush, Crop, Color Picker (Milestone 4)
- [ ] Undo/Redo system (Milestone 4)
- [ ] Python plugin system (Milestone 5)
- [ ] Installers and portable builds (Milestone 6)

## Technology Stack

- **UI Framework**: Qt6
- **Rendering**: OpenGL 3.3+
- **Programming Language**: C++17
- **Scripting**: Python 3.9+ (for plugins)
- **Build System**: CMake 3.20+

## Building from Source

### Prerequisites

#### All Platforms
- CMake 3.20 or later
- Qt6 (6.5 or later)
- C++17 compatible compiler
- Git

#### Windows
- Visual Studio 2019/2022 or MinGW-w64
- Qt6 for MSVC or MinGW

#### Linux (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install build-essential cmake git
sudo apt install qt6-base-dev qt6-opengl-dev libgl1-mesa-dev
```

#### Linux (Fedora)
```bash
sudo dnf install cmake gcc-c++ git
sudo dnf install qt6-qtbase-devel qt6-qtopengl-devel mesa-libGL-devel
```

#### macOS
```bash
xcode-select --install
brew install qt@6 cmake
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
cmake -DCMAKE_BUILD_TYPE=Release ..
```

4. **Build**
```bash
cmake --build . --config Release
```

5. **Run**
- **Windows**: `bin\Photonix.exe`
- **Linux**: `bin/Photonix`
- **macOS**: `open bin/Photonix.app`

## Project Structure

```
Photonix/
├── src/                    # Source code
│   ├── core/              # Core image processing
│   ├── ui/                # Qt6 user interface
│   ├── render/            # OpenGL rendering
│   ├── tools/             # Editing tools
│   ├── plugins/           # Plugin system
│   └── main.cpp           # Entry point
├── assets/                # Icons, themes, cursors
├── docs/                  # Documentation
├── tests/                 # Unit tests
├── third_party/           # External dependencies
└── CMakeLists.txt         # Build configuration
```

## Development Roadmap

### v0.0.1 (Current - Weeks 1-14)
- [x] **Milestone 1**: Project skeleton ✓
- [ ] **Milestone 2**: OpenGL canvas and rendering
- [ ] **Milestone 3**: Image I/O and layers
- [ ] **Milestone 4**: Basic tools and UI
- [ ] **Milestone 5**: Plugin system
- [ ] **Milestone 6**: Packaging and distribution

### v0.1.0 (Future)
- Advanced tools (selection, transform, filters)
- Layer blend modes
- Plugin marketplace
- Performance optimizations

### v0.2.0 (Future)
- Text tool
- Vector shapes
- Adjustment layers
- Color management

### v1.0.0 (Future)
- Complete feature set
- Stable plugin API
- Comprehensive documentation
- AI tool integration

## Contributing

We welcome contributions! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

### Development Resources
- [Architecture Documentation](docs/architecture.md)
- [Build Guide](docs/build_guide.md)
- [Plugin Development Guide](docs/plugin_guide.md)

## Documentation

- **User Manual**: [docs/user_manual.md](docs/user_manual.md)
- **API Reference**: [docs/api_reference.md](docs/api_reference.md)
- **Development Plan**: See project wiki

## License

Photonix is licensed under the GNU General Public License v3.0.  
See [LICENSE](LICENSE) for details.

## Inspiration

- **UI Design**: Inspired by Pixlr's clean, modern interface
- **Architecture**: Inspired by Krita's extensible design
- **Goal**: Create a lightweight alternative with professional features

## Contact & Community

- **Issues**: Report bugs on [GitHub Issues](https://github.com/yourusername/photonix/issues)
- **Discussions**: Join us on [GitHub Discussions](https://github.com/yourusername/photonix/discussions)

---

**Status**: Active Development  
**Current Milestone**: M1 - Project Skeleton ✓  
**Next Milestone**: M2 - OpenGL Canvas

Built with ❤️ by the Photonix community
"# Photonix-V0.0.1-c-build" 
