# 📑 Photonix Project Index

**Quick navigation guide for all project files and documentation**

Version: 0.0.1-dev | Milestone: 1 Complete ✅

---

## 🎯 Start Here

New to Photonix? Start with these files in order:

1. **[QUICK-START.md](QUICK-START.md)** ⭐  
   Quick guide to get up and running

2. **[README.md](README.md)**  
   Project overview and features

3. **[docs/build_guide.md](docs/build_guide.md)**  
   Detailed build instructions

4. **[MILESTONE-1-COMPLETE.md](MILESTONE-1-COMPLETE.md)**  
   What's been accomplished

5. **[docs/STATUS.md](docs/STATUS.md)**  
   Current development status

---

## 📂 Core Project Files

### Build & Configuration
- **[CMakeLists.txt](CMakeLists.txt)** - CMake build configuration
- **[build.sh](build.sh)** - Quick build script (Linux/macOS)
- **[.gitignore](.gitignore)** - Git exclusions

### Legal & Licensing
- **[LICENSE](LICENSE)** - GPL v3 license
- **[CONTRIBUTING.md](CONTRIBUTING.md)** - Contribution guidelines

---

## 💻 Source Code

### Application Entry
- **[src/main.cpp](src/main.cpp)** - Application entry point

### User Interface
- **[src/ui/MainWindow.h](src/ui/MainWindow.h)** - Main window header
- **[src/ui/MainWindow.cpp](src/ui/MainWindow.cpp)** - Main window implementation

### Core (Milestone 3+)
- `src/core/` - Image engine, layers, I/O (coming soon)

### Rendering (Milestone 2+)
- `src/render/` - OpenGL canvas and rendering (coming soon)

### Tools (Milestone 4+)
- `src/tools/` - Editing tools (brush, crop, etc.) (coming soon)

### Plugins (Milestone 5+)
- `src/plugins/` - Plugin system (coming soon)
- `src/scripts/` - Python scripts and examples (coming soon)

---

## 📚 Documentation

### Getting Started
- **[QUICK-START.md](QUICK-START.md)** ⭐ - Quick start guide
- **[README.md](README.md)** - Project overview
- **[docs/build_guide.md](docs/build_guide.md)** - Building from source

### Development
- **[CONTRIBUTING.md](CONTRIBUTING.md)** - How to contribute
- **[docs/STATUS.md](docs/STATUS.md)** - Development status
- **[MILESTONE-1-COMPLETE.md](MILESTONE-1-COMPLETE.md)** - M1 summary

### Future Documentation (Coming Soon)
- `docs/architecture.md` - System architecture (M2)
- `docs/plugin_guide.md` - Plugin development (M5)
- `docs/user_manual.md` - End-user manual (M6)
- `docs/api_reference.md` - API documentation (M5)

---

## 🎨 Assets

### Icons, Themes, Cursors
- `assets/icons/` - UI icons (to be populated)
- `assets/themes/` - Theme resources (to be populated)
- `assets/cursors/` - Custom cursors (to be populated)

---

## 🧪 Testing

### Test Files
- `tests/core/` - Core module tests (future)
- `tests/ui/` - UI tests (future)
- `tests/render/` - Rendering tests (future)
- `tests/tools/` - Tool tests (future)
- `tests/plugins/` - Plugin tests (future)

---

## 📦 Dependencies

### Third-Party Libraries
- `third_party/` - External dependencies
  - pybind11 (M5)
  - STB Image (M3)
  - Other libraries as needed

---

## 🏗️ Build Outputs

### Platform Builds
- `builds/windows/installer/` - Windows installer
- `builds/windows/portable/` - Windows portable ZIP
- `builds/linux/appimage/` - Linux AppImage
- `builds/linux/portable/` - Linux portable tar.gz
- `builds/macos/` - macOS app bundle

---

## 📋 Development Roadmap

### Milestones

#### ✅ Milestone 1: Project Skeleton (Complete)
**Files**: All core structure, UI skeleton, documentation

#### 🔜 Milestone 2: Rendering Canvas (Weeks 3-4)
**Files to Create**:
- `src/render/GLCanvas.h`
- `src/render/GLCanvas.cpp`
- `src/render/GLRenderer.h`
- `src/render/GLRenderer.cpp`
- `src/render/TextureManager.h`
- `src/render/TextureManager.cpp`
- `docs/architecture.md`

#### ⏳ Milestone 3: Image I/O & Layers (Weeks 5-6)
**Files to Create**:
- `src/core/ImageEngine.h`
- `src/core/ImageEngine.cpp`
- `src/core/LayerManager.h`
- `src/core/LayerManager.cpp`
- `src/core/ImageIO.h`
- `src/core/ImageIO.cpp`
- `src/ui/LayerPanel.h`
- `src/ui/LayerPanel.cpp`

#### ⏳ Milestone 4: Basic Tools (Weeks 7-9)
**Files to Create**:
- `src/tools/Tool.h`
- `src/tools/BrushTool.h/cpp`
- `src/tools/CropTool.h/cpp`
- `src/tools/ColorPickerTool.h/cpp`
- `src/ui/ToolPanel.h/cpp`
- `src/ui/PropertiesPanel.h/cpp`
- `src/core/History.h/cpp`

#### ⏳ Milestone 5: Plugin System (Weeks 10-12)
**Files to Create**:
- `src/plugins/PluginManager.h/cpp`
- `src/plugins/PythonBridge.h/cpp`
- `src/plugins/PluginAPI.h`
- `src/scripts/demo_filter.py`
- `src/scripts/batch_resize.py`
- `docs/plugin_guide.md`
- `docs/api_reference.md`

#### ⏳ Milestone 6: Packaging (Weeks 13-14)
**Files to Create**:
- `cmake/PackagingConfig.cmake`
- `installer/windows/installer.nsi`
- `installer/linux/create_appimage.sh`
- `installer/macos/create_dmg.sh`
- `docs/user_manual.md`

---

## 🔍 File Descriptions

### Main Documentation

| File | Purpose | Audience |
|------|---------|----------|
| QUICK-START.md | Quick start guide | Everyone |
| README.md | Project overview | Everyone |
| CONTRIBUTING.md | Contribution guide | Developers |
| LICENSE | Legal terms | Everyone |
| MILESTONE-1-COMPLETE.md | M1 summary | Developers |

### Technical Documentation

| File | Purpose | Audience |
|------|---------|----------|
| docs/build_guide.md | Build instructions | Developers |
| docs/STATUS.md | Development status | Developers |
| docs/architecture.md | System design | Developers (M2+) |
| docs/plugin_guide.md | Plugin development | Plugin developers (M5+) |
| docs/user_manual.md | User guide | End users (M6+) |

### Source Code

| File | Purpose | Lines |
|------|---------|-------|
| src/main.cpp | Entry point | ~60 |
| src/ui/MainWindow.h | Window header | ~160 |
| src/ui/MainWindow.cpp | Window impl | ~410 |
| CMakeLists.txt | Build config | ~95 |

---

## 🎓 Learning Path

### For New Contributors

1. **Understand the project**
   - Read QUICK-START.md
   - Read README.md
   - Explore STATUS.md

2. **Set up development**
   - Follow build_guide.md
   - Build successfully
   - Run the application

3. **Learn the codebase**
   - Read MainWindow.h
   - Understand main.cpp
   - Review CMakeLists.txt

4. **Start contributing**
   - Read CONTRIBUTING.md
   - Pick a good first issue
   - Submit a pull request

### For Plugin Developers (M5+)

1. Read docs/plugin_guide.md
2. Study example plugins in src/scripts/
3. Review Python API in docs/api_reference.md
4. Create your plugin
5. Test and submit

---

## 🔗 External Resources

### Qt6 Documentation
- Main: https://doc.qt.io/qt-6/
- Widgets: https://doc.qt.io/qt-6/qtwidgets-index.html
- OpenGL: https://doc.qt.io/qt-6/qtopengl-index.html

### OpenGL Resources
- Docs: https://www.opengl.org/documentation/
- Tutorial: https://learnopengl.com/

### CMake Documentation
- Main: https://cmake.org/documentation/
- Tutorial: https://cmake.org/cmake/help/latest/guide/tutorial/

### C++ Resources
- C++17: https://en.cppreference.com/w/cpp/17
- Best practices: https://isocpp.org/

---

## 📊 Project Statistics

### Current State (M1 Complete)

| Metric | Value |
|--------|-------|
| Source files | 3 |
| Header files | 1 |
| Lines of code | ~630 |
| Documentation files | 6 |
| Lines of docs | ~2,800 |
| Build scripts | 2 |
| Milestones complete | 1/6 |

### Code Distribution

| Category | Lines | Percentage |
|----------|-------|------------|
| UI | ~570 | 90% |
| Entry point | ~60 | 10% |
| Core | 0 | 0% (M3+) |
| Render | 0 | 0% (M2+) |
| Tools | 0 | 0% (M4+) |
| Plugins | 0 | 0% (M5+) |

---

## 🎯 Quick Links by Task

### I want to...

**Build Photonix**  
→ [docs/build_guide.md](docs/build_guide.md)

**Understand the code**  
→ [src/ui/MainWindow.h](src/ui/MainWindow.h)  
→ [src/main.cpp](src/main.cpp)

**Contribute**  
→ [CONTRIBUTING.md](CONTRIBUTING.md)

**Report a bug**  
→ GitHub Issues

**Request a feature**  
→ GitHub Issues

**Learn about progress**  
→ [docs/STATUS.md](docs/STATUS.md)

**See what's coming**  
→ [MILESTONE-1-COMPLETE.md](MILESTONE-1-COMPLETE.md)

**Get started quickly**  
→ [QUICK-START.md](QUICK-START.md) ⭐

---

## 📧 Contact & Support

- **GitHub Repository**: [URL]
- **Issues**: Report bugs and request features
- **Discussions**: Ask questions
- **Email**: For security issues

---

## 🌟 Key Achievements

✅ Complete project structure  
✅ Professional UI framework  
✅ Build system working  
✅ Comprehensive documentation  
✅ Ready for development  

---

## ⏭️ Next Steps

1. ✅ Complete Milestone 1
2. 🔜 Start Milestone 2 (OpenGL Canvas)
3. ⏳ Continue through M3-M6
4. 🎯 Release v0.0.1

---

**Current Status**: Milestone 1 Complete ✅  
**Next Milestone**: M2 - Rendering Canvas 🔜  
**Progress**: 1/6 milestones (17%)

---

*Last updated: November 6, 2025*  
*Photonix v0.0.1-dev*
