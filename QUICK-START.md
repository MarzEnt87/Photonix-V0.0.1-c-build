# 🚀 Photonix Quick Start Guide

Welcome to **Photonix v0.0.1** - Your journey into open-source photo editing begins here!

---

## 📦 What You Have

You now have a complete **Milestone 1** implementation of Photonix, including:

✅ Full application structure  
✅ Qt6-based UI framework  
✅ Build system (CMake)  
✅ Complete documentation  
✅ Ready for development  

---

## 🎯 Project Overview

**Photonix** is a lightweight, professional-grade, open-source photo editor designed to be:
- **Portable**: Extract and run, minimal installation
- **Extensible**: Python plugins for custom tools and AI
- **Professional**: Powerful editing capabilities
- **Cross-platform**: Windows, Linux, macOS

---

## 📂 What's Inside

```
Photonix/
├── 📄 README.md                    # Project overview
├── 📄 MILESTONE-1-COMPLETE.md      # This milestone summary
├── 📄 CMakeLists.txt               # Build configuration
├── 📄 LICENSE                      # GPL v3 license
├── 📄 CONTRIBUTING.md              # How to contribute
├── 🔧 build.sh                     # Quick build script
│
├── 📁 src/                         # Source code
│   ├── main.cpp                    # Entry point
│   └── ui/
│       ├── MainWindow.h            # Main window header
│       └── MainWindow.cpp          # Main window implementation
│
├── 📁 docs/                        # Documentation
│   ├── build_guide.md              # Build instructions
│   └── STATUS.md                   # Development status
│
├── 📁 assets/                      # Icons, themes (ready for M2+)
├── 📁 tests/                       # Unit tests (for future)
└── 📁 builds/                      # Output directory
```

---

## 🛠️ Prerequisites

Before building, you need:

### All Platforms
- **CMake** 3.20 or later
- **Qt6** 6.5 or later  
- **C++17** compatible compiler

### Linux (Ubuntu/Debian)
```bash
sudo apt install build-essential cmake git
sudo apt install qt6-base-dev qt6-opengl-dev libgl1-mesa-dev
```

### Windows
- Visual Studio 2019/2022 OR MinGW-w64
- Qt6 for MSVC or MinGW
- CMake

### macOS
```bash
xcode-select --install
brew install qt@6 cmake
```

---

## 🏗️ Building Photonix

### Quick Build (Linux/macOS)
```bash
cd Photonix
./build.sh
```

### Manual Build (All Platforms)

1. **Create build directory**:
```bash
mkdir build
cd build
```

2. **Configure**:
```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
```

3. **Build**:
```bash
cmake --build . --config Release
```

4. **Run**:
```bash
# Linux/macOS
./bin/Photonix

# Windows
bin\Release\Photonix.exe
```

---

## 🎮 Using Photonix (Current State)

### What Works Now ✅

When you run Photonix, you can:

1. **Explore the Interface**
   - Menu bar with all planned menus
   - Toolbar with action buttons
   - Resizable dock panels
   - Professional layout

2. **Test Menus**
   - File → Open (shows file dialog)
   - File → Save As (shows save dialog)
   - View → Zoom controls (prepared for M2)
   - Help → About (shows info)

3. **Use Keyboard Shortcuts**
   - `Ctrl+N` - New (placeholder)
   - `Ctrl+O` - Open file dialog
   - `Ctrl+S` - Save (placeholder)
   - `Ctrl+Z` - Undo (coming in M4)
   - `F11` - Toggle fullscreen
   - `Ctrl+Q` - Exit

4. **Customize Layout**
   - Drag dock panels to reposition
   - Close/open panels from View menu
   - Resize panels

### What's Coming Next 🔜

**Milestone 2** (Weeks 3-4): OpenGL Canvas
- Display images
- Zoom and pan
- Hardware acceleration

**Milestone 3** (Weeks 5-6): Image I/O
- Load PNG, JPEG, TIFF
- Save images
- Layer system

**Milestone 4** (Weeks 7-9): Editing Tools
- Brush tool
- Crop tool
- Color picker
- Undo/Redo

**Milestone 5** (Weeks 10-12): Plugins
- Python plugin system
- AI integration support
- Custom tools

**Milestone 6** (Weeks 13-14): Distribution
- Installers
- Portable builds
- Full documentation

---

## 📚 Documentation

Explore these guides:

1. **[README.md](README.md)**  
   Project overview, features, quick start

2. **[docs/build_guide.md](docs/build_guide.md)**  
   Detailed build instructions for all platforms

3. **[CONTRIBUTING.md](CONTRIBUTING.md)**  
   Contribution guidelines, code standards

4. **[docs/STATUS.md](docs/STATUS.md)**  
   Current development status, milestones

5. **[MILESTONE-1-COMPLETE.md](MILESTONE-1-COMPLETE.md)**  
   Milestone 1 achievements and next steps

---

## 🐛 Troubleshooting

### Qt6 Not Found
```bash
# Set Qt path
export CMAKE_PREFIX_PATH=/path/to/qt6
# Or on Windows:
set CMAKE_PREFIX_PATH=C:\Qt\6.5.3\msvc2019_64
```

### Build Errors
```bash
# Clean build
rm -rf build
mkdir build
cd build
cmake ..
```

### Can't Run Executable
```bash
# Linux: Check permissions
chmod +x build/bin/Photonix

# Windows: Check if Qt DLLs are in PATH
# Or copy Qt DLLs to bin/ directory
```

See **[docs/build_guide.md](docs/build_guide.md)** for detailed troubleshooting.

---

## 🎨 Development

### Want to Contribute?

1. **Read** [CONTRIBUTING.md](CONTRIBUTING.md)
2. **Fork** the repository
3. **Create** a feature branch
4. **Make** your changes
5. **Submit** a pull request

### Good Starting Points

- Add comments to code
- Improve documentation
- Test on different platforms
- Report bugs
- Suggest features

---

## 🗺️ Roadmap

### Current: v0.0.1 (14 weeks)
- [x] **M1**: Project skeleton ✅
- [ ] **M2**: OpenGL canvas 🔜
- [ ] **M3**: Image I/O & layers
- [ ] **M4**: Editing tools
- [ ] **M5**: Plugin system
- [ ] **M6**: Packaging

### Future: v0.1.0
- Advanced tools
- Layer blend modes
- Plugin marketplace

### Future: v1.0.0
- Full feature set
- Stable API
- AI integration

---

## 💡 Key Features (Planned)

### Professional Editing
- Non-destructive workflow
- Layer system with blend modes
- Advanced selection tools
- Professional-grade filters

### Python Integration
- Script automation
- Custom tools
- AI model integration (SDXL, etc.)
- Batch processing

### Modern UI
- Clean, intuitive interface
- Customizable panels
- Dark/light themes
- Keyboard-driven workflow

### Portable & Fast
- Single-file download
- No installation required
- Hardware acceleration
- Optimized performance

---

## 🌟 Technology Stack

- **UI**: Qt6 (modern, cross-platform)
- **Rendering**: OpenGL 3.3+ (hardware accelerated)
- **Language**: C++17 (modern, fast)
- **Scripting**: Python 3.9+ (extensible)
- **Build**: CMake (cross-platform)

---

## 📖 Learning Resources

### Qt6 Documentation
- https://doc.qt.io/qt-6/

### OpenGL Documentation
- https://www.opengl.org/documentation/

### CMake Tutorial
- https://cmake.org/cmake/help/latest/guide/tutorial/

### C++17 Features
- https://en.cppreference.com/w/cpp/17

---

## 🤝 Community

### Get Help
- GitHub Issues: Report bugs
- GitHub Discussions: Ask questions
- Documentation: Read guides

### Stay Updated
- Watch repository for updates
- Star to show support
- Fork to contribute

---

## 📜 License

Photonix is **GPL v3** licensed - free and open source!

You can:
- ✅ Use freely
- ✅ Modify source
- ✅ Distribute
- ✅ Contribute

See [LICENSE](LICENSE) for details.

---

## ✨ Final Notes

### You're Ready!

You now have:
- ✅ Complete project structure
- ✅ Working build system
- ✅ Professional UI framework
- ✅ Comprehensive documentation
- ✅ Clear development path

### Next Steps

1. **Build** the project
2. **Run** and explore
3. **Read** the documentation
4. **Start** Milestone 2 (OpenGL canvas)
5. **Contribute** your improvements

### Questions?

- Check **[docs/build_guide.md](docs/build_guide.md)** for build issues
- Read **[CONTRIBUTING.md](CONTRIBUTING.md)** for development
- See **[docs/STATUS.md](docs/STATUS.md)** for progress
- Open a GitHub issue for bugs

---

## 🎉 Congratulations!

You've successfully set up **Photonix v0.0.1 - Milestone 1**!

The foundation is solid. Now let's build something amazing! 🚀✨

---

**Ready to start development?**

```bash
cd Photonix
./build.sh
./build/bin/Photonix
```

**Let's create the future of open-source photo editing!** 📸

---

*Generated: November 6, 2025*  
*Version: 0.0.1-dev*  
*Milestone: 1 (Complete) ✅*
