# Photonix v0.0.1 Development Plan
## Professional-Grade Open-Source Photo Editor

---

## Table of Contents

1. [Executive Summary](#executive-summary)
2. [Architecture & File Structure](#architecture--file-structure)
3. [Core Module Definitions](#core-module-definitions)
4. [Technology Stack & Dependencies](#technology-stack--dependencies)
5. [UI/UX Layout Design](#uiux-layout-design)
6. [Plugin System Architecture](#plugin-system-architecture)
7. [Installation & Packaging Plan](#installation--packaging-plan)
8. [Development Milestones (v0.0.1)](#development-milestones-v001)
9. [Testing & Documentation Strategy](#testing--documentation-strategy)
10. [Build Instructions](#build-instructions)
11. [Next Steps](#next-steps)

---

## Executive Summary

**Photonix** is a lightweight, professional-grade, open-source photo-editing suite designed for portability, extensibility, and ease of use. Version v0.0.1 establishes the foundational architecture with:

- **Cross-platform support** (Windows, Linux, macOS)
- **Modern UI** built with Qt6
- **Hardware-accelerated rendering** via OpenGL
- **Python scripting system** for extensibility and AI integration
- **Portable distribution** (extract-and-run or simple installer)

**Primary Goals for v0.0.1:**
- Establish robust, modular architecture
- Implement basic image editing capabilities
- Create extensible plugin system
- Ensure easy installation and distribution
- Provide comprehensive documentation for contributors

---

## Architecture & File Structure

### Project Directory Structure

```
Photonix/
│
├─ src/                         # All source code
│   ├─ core/                    # Core logic (image engine, layers, I/O)
│   │   ├─ ImageEngine.cpp/h    # Image data management
│   │   ├─ LayerManager.cpp/h   # Layer stack management
│   │   ├─ ImageIO.cpp/h        # File I/O operations
│   │   ├─ ColorSpace.cpp/h     # Color management
│   │   └─ History.cpp/h        # Undo/redo system
│   │
│   ├─ ui/                      # Qt6 UI code, menus, dock panels
│   │   ├─ MainWindow.cpp/h     # Primary application window
│   │   ├─ ToolPanel.cpp/h      # Left-side tool palette
│   │   ├─ LayerPanel.cpp/h     # Right-side layer panel
│   │   ├─ PropertiesPanel.cpp/h # Tool properties
│   │   ├─ MenuBar.cpp/h        # Menu system
│   │   └─ StatusBar.cpp/h      # Bottom status information
│   │
│   ├─ render/                  # OpenGL rendering backend
│   │   ├─ GLCanvas.cpp/h       # QOpenGLWidget-based canvas
│   │   ├─ GLRenderer.cpp/h     # OpenGL rendering logic
│   │   ├─ TextureManager.cpp/h # Texture/image caching
│   │   └─ ViewportController.cpp/h # Zoom/pan/transform
│   │
│   ├─ tools/                   # Tools: brush, crop, filters
│   │   ├─ Tool.cpp/h           # Abstract base tool class
│   │   ├─ BrushTool.cpp/h      # Painting/drawing tool
│   │   ├─ CropTool.cpp/h       # Crop/resize tool
│   │   ├─ ColorPickerTool.cpp/h # Eyedropper
│   │   ├─ SelectionTool.cpp/h  # Selection tools
│   │   └─ FilterTool.cpp/h     # Basic filters
│   │
│   ├─ plugins/                 # C++ plugins and Python plugin loader
│   │   ├─ PluginManager.cpp/h  # Plugin discovery/loading
│   │   ├─ PythonBridge.cpp/h   # Python embedding/API
│   │   ├─ PluginAPI.h          # C++ plugin interface
│   │   └─ examples/            # Example plugins
│   │
│   ├─ scripts/                 # Python scripts/examples
│   │   ├─ demo_filter.py       # Example filter script
│   │   ├─ batch_resize.py      # Batch processing example
│   │   └─ plugin_template.py   # Template for new plugins
│   │
│   └─ main.cpp                 # Application entry point
│
├─ assets/                      # Icons, cursors, UI graphics
│   ├─ icons/                   # Tool icons, UI elements
│   ├─ cursors/                 # Custom cursors
│   └─ themes/                  # UI theme resources
│
├─ docs/                        # Documentation and READMEs
│   ├─ architecture.md          # System architecture overview
│   ├─ build_guide.md           # Building from source
│   ├─ plugin_guide.md          # Plugin development guide
│   ├─ user_manual.md           # End-user documentation
│   └─ api_reference.md         # Python API documentation
│
├─ builds/                      # Compiled executables and installers
│   ├─ windows/                 # Windows build outputs
│   │   ├─ installer/           # NSIS/WiX installer .exe
│   │   └─ portable/            # ZIP portable build
│   ├─ linux/
│   │   ├─ appimage/            # AppImage build
│   │   └─ portable/            # tar.gz portable build
│   └─ macos/                   # macOS app bundle (.dmg)
│
├─ cmake/                       # CMake configuration modules
│   ├─ FindPython3.cmake        # Python detection
│   ├─ Qt6Config.cmake          # Qt6 configuration
│   └─ PackagingConfig.cmake    # Installer configuration
│
├─ third_party/                 # External dependencies
│   ├─ stb/                     # STB image libraries
│   ├─ pybind11/                # Python C++ bindings
│   └─ README.md                # Third-party licenses
│
├─ tests/                       # Unit and functional tests
│   ├─ core/                    # Core module tests
│   ├─ ui/                      # UI component tests
│   └─ plugins/                 # Plugin system tests
│
├─ CMakeLists.txt               # Main build configuration
├─ README.md                    # Project overview
├─ LICENSE                      # GPL v3 license
└─ CONTRIBUTING.md              # Contributor guidelines
```

### Design Principles

1. **Modularity**: Each module has clear responsibilities and minimal dependencies
2. **Extensibility**: Plugin system allows functionality additions without core changes
3. **Performance**: OpenGL acceleration for rendering, efficient image processing
4. **Portability**: Single codebase for Windows, Linux, and macOS
5. **Simplicity**: Clean APIs and well-documented interfaces for contributors

---

## Core Module Definitions

### 1. Core Module (`src/core/`)

**Responsibility**: Image data management, layer operations, file I/O, and undo/redo

**Key Classes**:

- **ImageEngine**: Central image data structure
  - Pixel buffer management
  - Color space handling (RGB, RGBA, grayscale)
  - Image transformations
  - Memory optimization

- **LayerManager**: Layer stack management
  - Layer creation/deletion
  - Layer ordering and visibility
  - Blend modes
  - Layer grouping

- **ImageIO**: File operations
  - Format support: PNG, JPEG, TIFF, BMP
  - Load/save with format detection
  - Metadata preservation
  - Error handling

- **History**: Undo/redo system
  - Command pattern implementation
  - Memory-efficient history storage
  - State serialization

- **ColorSpace**: Color management
  - RGB/RGBA conversions
  - Color profile support (future)
  - Gamma correction

**Dependencies**: STL, Qt Core (for file operations)

---

### 2. UI Module (`src/ui/`)

**Responsibility**: User interface components and event handling

**Key Classes**:

- **MainWindow**: Application window
  - Dock panel management
  - Menu bar integration
  - Toolbar management
  - Window state persistence

- **ToolPanel**: Left-side tool palette
  - Tool selection UI
  - Tool icon grid
  - Active tool highlighting

- **LayerPanel**: Right-side layer list
  - Layer tree view
  - Visibility toggles
  - Thumbnail previews
  - Drag-and-drop reordering

- **PropertiesPanel**: Tool configuration
  - Dynamic property editors
  - Brush size/opacity sliders
  - Color selection widgets

- **MenuBar**: Application menus
  - File, Edit, View, Layer, Tools, Plugins, Help
  - Keyboard shortcuts
  - Recent files list

- **StatusBar**: Bottom information display
  - Current tool status
  - Image dimensions
  - Zoom level
  - Cursor position

**Dependencies**: Qt6 Widgets, Qt6 Core

---

### 3. Render Module (`src/render/`)

**Responsibility**: Hardware-accelerated canvas rendering via OpenGL

**Key Classes**:

- **GLCanvas**: QOpenGLWidget subclass
  - OpenGL context initialization
  - Event handling (mouse, keyboard, tablet)
  - Double-buffered rendering
  - High-DPI support

- **GLRenderer**: Rendering logic
  - Texture-based image display
  - Layer compositing with blend modes
  - Zoom/pan transformations
  - Tool overlay rendering

- **TextureManager**: GPU resource management
  - Image-to-texture conversion
  - Texture caching
  - Memory management
  - Mipmap generation

- **ViewportController**: View transformations
  - Zoom (100%, fit, fill)
  - Pan (drag to move)
  - Rotation (future feature)
  - View persistence

**Dependencies**: Qt6 OpenGL, OpenGL 3.3+

**Rendering Pipeline**:
1. Upload image data to GPU textures
2. Composite layers with blend modes
3. Apply zoom/pan transformation
4. Render tool overlays (selections, guides)
5. Swap buffers

---

### 4. Tools Module (`src/tools/`)

**Responsibility**: Implement editing tools (brush, crop, filters, etc.)

**Key Classes**:

- **Tool** (Abstract Base): Common tool interface
  - `onMousePress()`, `onMouseMove()`, `onMouseRelease()`
  - `onActivate()`, `onDeactivate()`
  - Property system integration
  - Cursor management

- **BrushTool**: Painting and drawing
  - Brush size, opacity, hardness
  - Pressure sensitivity (tablet support)
  - Brush presets
  - Real-time preview

- **CropTool**: Crop and resize
  - Interactive crop rectangle
  - Aspect ratio constraints
  - Grid overlay
  - Preview mode

- **ColorPickerTool**: Eyedropper
  - Sample color from image
  - Average sampling (area mode)
  - Real-time color preview

- **SelectionTool**: Rectangular/elliptical selection
  - Selection shapes
  - Add/subtract modes
  - Anti-aliasing
  - Transform selection

- **FilterTool**: Apply basic filters
  - Blur, sharpen, brightness/contrast
  - Preview before apply
  - Adjustable parameters

**Tool Architecture**:
- Tools receive mouse/keyboard events from GLCanvas
- Tools modify image data through ImageEngine
- Changes recorded in History for undo
- Real-time feedback rendered on canvas

---

### 5. Plugins Module (`src/plugins/`)

**Responsibility**: Plugin discovery, loading, and Python integration

**Key Classes**:

- **PluginManager**: Plugin lifecycle
  - Scan plugin directories
  - Load/unload plugins
  - Plugin metadata management
  - Dependency resolution

- **PythonBridge**: Embedded Python interpreter
  - CPython embedding (pybind11)
  - Python API exposure
  - Script execution environment
  - Error handling and reporting

- **PluginAPI**: C++ interface for plugins
  - Image access API
  - Layer manipulation API
  - UI extension points
  - Event subscription

**Plugin Types**:
1. **Python Scripts**: Simple automation scripts
2. **Python Plugins**: Full-featured extensions with UI
3. **C++ Plugins**: High-performance native plugins (future)

**Python API Structure** (exposed via pybind11):
```python
import photonix

# Access current image
image = photonix.get_active_image()
width, height = image.get_dimensions()
pixels = image.get_pixel_data()  # NumPy array

# Layer manipulation
layer = image.get_active_layer()
layer.set_opacity(0.5)
layer.set_blend_mode("multiply")

# Create new layer
new_layer = image.create_layer("AI Generated")

# Apply transformations
image.resize(800, 600)
image.rotate(90)

# Filters
photonix.filters.gaussian_blur(layer, radius=5.0)
photonix.filters.brightness_contrast(layer, brightness=10, contrast=5)

# UI extensions
def my_tool_function():
    # Tool implementation
    pass

photonix.register_tool("My Custom Tool", my_tool_function, icon="path/to/icon.png")
photonix.add_menu_item("Plugins/My Plugin/Run", my_tool_function)
```

**Plugin Discovery**:
- Search paths: `<app_dir>/plugins`, `<user_home>/.photonix/plugins`
- Plugin metadata: `manifest.json` or Python docstrings
- Auto-loading on startup (configurable)

---

## Technology Stack & Dependencies

### Core Technologies

| Technology | Version | Purpose |
|------------|---------|---------|
| **Qt6** | 6.5+ | UI framework, windowing system |
| **OpenGL** | 3.3+ | Hardware-accelerated rendering |
| **C++** | C++17 | Primary programming language |
| **Python** | 3.9+ | Scripting and plugin system |
| **CMake** | 3.20+ | Build system |

### Key Libraries

1. **Qt6 Modules**:
   - Qt6::Core (fundamental classes)
   - Qt6::Widgets (UI components)
   - Qt6::OpenGL (OpenGL integration)
   - Qt6::OpenGLWidgets (QOpenGLWidget)

2. **Python Integration**:
   - **pybind11**: C++ ↔ Python bindings (header-only)
   - **NumPy** (optional): Efficient pixel buffer access

3. **Image I/O**:
   - **STB Image** (stb_image.h): PNG, JPEG, BMP loading
   - **Qt Image I/O**: TIFF, additional format support
   - **libpng/libjpeg**: Optional direct library usage

4. **Build & Packaging**:
   - **CMake**: Cross-platform build configuration
   - **NSIS** (Windows): Installer creation
   - **linuxdeploy** (Linux): AppImage creation
   - **macdeployqt** (macOS): App bundle packaging

### Platform-Specific Requirements

**Windows**:
- Visual Studio 2019+ or MinGW-w64
- Windows 10+ (OpenGL support)
- Qt6 for Windows (MSVC or MinGW build)

**Linux**:
- GCC 9+ or Clang 10+
- X11 or Wayland
- OpenGL 3.3+ drivers
- Qt6 development packages

**macOS**:
- Xcode 12+ (Command Line Tools)
- macOS 11+ (Big Sur or later)
- Qt6 for macOS

### Dependency Management

**CMake Configuration** (`CMakeLists.txt`):
```cmake
cmake_minimum_required(VERSION 3.20)
project(Photonix VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets OpenGL OpenGLWidgets)

# Find Python3
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add pybind11 subdirectory
add_subdirectory(third_party/pybind11)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/third_party
    ${Python3_INCLUDE_DIRS}
)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

# Create executable
add_executable(Photonix ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(Photonix
    Qt6::Core
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    OpenGL::GL
    Python3::Python
    pybind11::embed
)

# Install targets
install(TARGETS Photonix DESTINATION bin)
install(DIRECTORY assets DESTINATION share/photonix)
```

---

## UI/UX Layout Design

### Design Philosophy

**Inspired by Pixlr** (clean, modern) with **Krita-style** professional features:
- Minimal, uncluttered interface
- Docking panels for flexibility
- Dark theme (default) with light theme option
- Icon-based tools for quick recognition
- Context-sensitive properties panel

### Main Window Layout

```
┌─────────────────────────────────────────────────────────────────┐
│  File  Edit  View  Layer  Tools  Plugins  Help        [_ □ X]   │
├─────────────────────────────────────────────────────────────────┤
│ [New] [Open] [Save] | [Undo] [Redo] | [Zoom: 100%▼] [Fit]      │
├────┬──────────────────────────────────────────────────────┬─────┤
│    │                                                      │     │
│ T  │                                                      │  L  │
│ o  │                                                      │  a  │
│ o  │                                                      │  y  │
│ l  │              Canvas Area                             │  e  │
│ s  │         (OpenGL Rendering)                           │  r  │
│    │                                                      │  s  │
│ P  │                                                      │     │
│ a  │                                                      │  P  │
│ n  │                                                      │  r  │
│ e  │                                                      │  o  │
│ l  │                                                      │  p  │
│    │                                                      │  s  │
├────┴──────────────────────────────────────────────────────┴─────┤
│ Current Tool: Brush | Image: 1920x1080 | Zoom: 100% | (x,y)    │
└─────────────────────────────────────────────────────────────────┘
```

### Component Details

#### 1. Menu Bar (Top)

**File Menu**:
- New... (Ctrl+N)
- Open... (Ctrl+O)
- Open Recent ▶
- Save (Ctrl+S)
- Save As... (Ctrl+Shift+S)
- Export ▶ (PNG, JPEG, TIFF)
- Close (Ctrl+W)
- Exit (Ctrl+Q)

**Edit Menu**:
- Undo (Ctrl+Z)
- Redo (Ctrl+Shift+Z)
- Cut (Ctrl+X)
- Copy (Ctrl+C)
- Paste (Ctrl+V)
- Preferences... (Ctrl+,)

**View Menu**:
- Zoom In (Ctrl++)
- Zoom Out (Ctrl+-)
- Zoom to 100% (Ctrl+1)
- Fit to Window (Ctrl+0)
- Fullscreen (F11)
- Grid / Guides
- Toggle Panels ▶

**Layer Menu**:
- New Layer (Ctrl+Shift+N)
- Duplicate Layer
- Delete Layer (Del)
- Merge Layers
- Flatten Image
- Layer Properties...

**Tools Menu**:
- List of all tools with shortcuts

**Plugins Menu**:
- Manage Plugins...
- Python Scripts ▶
- Installed Plugins ▶
- Install Plugin from ZIP...

**Help Menu**:
- User Manual (F1)
- Plugin API Documentation
- Report Bug...
- About Photonix

#### 2. Toolbar (Below Menu Bar)

Quick-access buttons:
- **File**: New, Open, Save
- **Edit**: Undo, Redo
- **View**: Zoom dropdown, Fit to window
- **Separator**
- **Common Tools**: Brush, Crop, Color Picker

#### 3. Tool Panel (Left Sidebar, ~60px wide)

Vertical icon grid:
- **Selection Tools**: Rectangle, Ellipse, Lasso
- **Painting Tools**: Brush, Eraser, Paint Bucket
- **Transform Tools**: Move, Crop, Rotate
- **Adjustment Tools**: Color Picker, Gradient
- **Other**: Zoom, Hand (pan)

**Interaction**:
- Single-click to activate tool
- Right-click for tool options
- Active tool highlighted
- Tooltip on hover

#### 4. Canvas Area (Center)

**GLCanvas** (QOpenGLWidget):
- Background: checkerboard pattern (transparency indicator)
- Image rendering with current zoom/pan
- Tool overlays (selections, guides, crop rectangles)
- Smooth zooming (Ctrl+Scroll)
- Pan with Space+Drag or Middle Mouse Button
- Tablet pressure support

**Canvas Controls**:
- Zoom level indicator (bottom-right corner)
- Mini-map/navigator (optional, future)

#### 5. Layer Panel (Right Sidebar, ~250px wide)

**Layer List**:
- Thumbnail preview (32x32px)
- Layer name (editable on double-click)
- Visibility toggle (eye icon)
- Lock toggle (lock icon)
- Blend mode dropdown
- Opacity slider

**Layer Controls** (Bottom of panel):
- [+ New Layer]
- [Duplicate]
- [Delete]
- [Merge Down]

**Interaction**:
- Drag to reorder layers
- Right-click for context menu
- Selection highlights active layer

#### 6. Properties Panel (Right Sidebar, below Layers, ~250px wide)

**Dynamic Content** (changes based on active tool):

**Brush Tool Properties**:
- Size: Slider (1-500px)
- Opacity: Slider (0-100%)
- Hardness: Slider (0-100%)
- Spacing: Slider (1-200%)
- Pressure Sensitivity: Checkbox

**Crop Tool Properties**:
- Width / Height (editable)
- Aspect Ratio: Dropdown (Free, 1:1, 4:3, 16:9, custom)
- Grid: Checkbox (rule of thirds)

**Color Picker Properties**:
- Sample Size: Dropdown (Point, 3x3, 5x5 average)
- Continuous: Checkbox

#### 7. Status Bar (Bottom)

Left side:
- Current tool name and shortcut
- Current operation progress bar (for slow operations)

Right side:
- Image dimensions (e.g., "1920 × 1080 px")
- Current zoom level (e.g., "Zoom: 100%")
- Cursor position (e.g., "(512, 384)")
- Memory usage (optional)

### Color Scheme (Dark Theme)

- **Background**: #2B2B2B (dark gray)
- **Panel Background**: #3C3F41 (slightly lighter)
- **Canvas Background**: #1E1E1E (darker for contrast)
- **Text**: #CCCCCC (light gray)
- **Accent**: #4A9EFF (blue for highlights)
- **Border**: #555555 (subtle dividers)

### Keyboard Shortcuts (Standard)

| Shortcut | Action |
|----------|--------|
| Ctrl+N | New image |
| Ctrl+O | Open file |
| Ctrl+S | Save file |
| Ctrl+Z | Undo |
| Ctrl+Shift+Z | Redo |
| Ctrl+C / V | Copy / Paste |
| Ctrl++ / - | Zoom in / out |
| Ctrl+0 | Fit to window |
| Space+Drag | Pan canvas |
| B | Brush tool |
| C | Crop tool |
| I | Color picker |
| M | Move tool |
| Tab | Toggle panels |

---

## Plugin System Architecture

### Overview

The plugin system allows users and developers to extend Photonix with:
- Custom tools and filters
- Automation scripts
- AI integration (SDXL, Stable Diffusion, etc.)
- Batch processing
- Custom file format support

### Plugin Types

1. **Python Scripts** (.py files): Simple automation
2. **Python Plugins** (module with manifest): Full extensions
3. **C++ Plugins** (future): Native performance plugins

### Python Plugin Structure

**Directory Layout**:
```
~/.photonix/plugins/my_plugin/
├─ manifest.json          # Plugin metadata
├─ __init__.py            # Plugin entry point
├─ tool.py                # Tool implementation
├─ ui.py                  # UI components (optional)
└─ resources/             # Icons, assets
   └─ icon.png
```

**manifest.json**:
```json
{
  "name": "My Custom Plugin",
  "version": "1.0.0",
  "author": "Your Name",
  "description": "A custom filter plugin for Photonix",
  "entry_point": "my_plugin",
  "dependencies": ["numpy", "pillow"],
  "photonix_version": ">=0.0.1",
  "permissions": ["image_read", "image_write", "ui_extend"],
  "icon": "resources/icon.png"
}
```

**__init__.py** (Plugin Entry Point):
```python
import photonix

def activate():
    """Called when plugin is loaded"""
    photonix.add_menu_item("Plugins/My Plugin/Run Filter", run_filter)
    photonix.register_tool("My Tool", MyCustomTool)
    print("My Plugin activated!")

def deactivate():
    """Called when plugin is unloaded"""
    photonix.remove_menu_item("Plugins/My Plugin/Run Filter")
    print("My Plugin deactivated!")

def run_filter():
    """Example filter function"""
    image = photonix.get_active_image()
    layer = image.get_active_layer()
    
    # Access pixel data as NumPy array
    pixels = layer.get_pixel_data()
    
    # Apply custom filter (e.g., invert colors)
    pixels[:, :, :3] = 255 - pixels[:, :, :3]
    
    # Update layer
    layer.set_pixel_data(pixels)
    image.update()

class MyCustomTool:
    """Example custom tool"""
    def __init__(self):
        self.name = "My Tool"
        self.cursor = photonix.Cursor.CROSSHAIR
    
    def on_activate(self):
        print("Tool activated")
    
    def on_mouse_press(self, x, y, button):
        print(f"Mouse pressed at ({x}, {y})")
    
    def on_mouse_move(self, x, y):
        pass
    
    def on_mouse_release(self, x, y, button):
        print(f"Mouse released at ({x}, {y})")
```

### Python API (Core Functions)

**Image Access**:
```python
# Get active image
image = photonix.get_active_image()

# Image properties
width, height = image.get_dimensions()
color_mode = image.get_color_mode()  # "RGB", "RGBA", "GRAYSCALE"

# Create new image
new_image = photonix.create_image(800, 600, "RGBA")
```

**Layer Manipulation**:
```python
# Access layers
layer = image.get_active_layer()
all_layers = image.get_layers()
layer_by_name = image.get_layer("Background")

# Layer properties
layer.set_name("New Name")
layer.set_opacity(0.5)  # 0.0 to 1.0
layer.set_visible(True)
layer.set_blend_mode("multiply")

# Create/delete layers
new_layer = image.create_layer("AI Generated")
image.delete_layer(layer)
image.duplicate_layer(layer)
```

**Pixel Data Access** (NumPy integration):
```python
import numpy as np

# Get pixel data as NumPy array
# Shape: (height, width, channels)
pixels = layer.get_pixel_data()

# Modify pixels
pixels[:, :, 0] = 255  # Set all red channel to max

# Set modified data back
layer.set_pixel_data(pixels)

# Selective access
region = pixels[100:200, 100:200, :]  # Get region
```

**Filters & Transformations**:
```python
# Built-in filters
photonix.filters.gaussian_blur(layer, radius=5.0)
photonix.filters.brightness_contrast(layer, brightness=10, contrast=5)
photonix.filters.hue_saturation(layer, hue=0, saturation=10)

# Transformations
image.resize(800, 600, interpolation="bilinear")
image.rotate(90)  # Degrees
layer.flip_horizontal()
layer.flip_vertical()
```

**UI Extensions**:
```python
# Add menu items
photonix.add_menu_item("Plugins/My Plugin/Action", callback_function)

# Register custom tools
photonix.register_tool("Tool Name", ToolClass, icon="path/to/icon.png")

# Show dialogs
result = photonix.ui.show_dialog(
    title="My Plugin",
    message="Choose an option",
    buttons=["OK", "Cancel"]
)

# Progress bar
with photonix.ui.progress("Processing...", max=100) as progress:
    for i in range(100):
        # Do work
        progress.update(i)
```

### Plugin Manager UI

**Settings → Manage Plugins** dialog:
- List of installed plugins
- Enable/disable toggles
- Plugin info (name, version, author, description)
- Update button (check for updates)
- Install from ZIP button
- Uninstall button
- Plugin settings (per-plugin configuration)

### Plugin Security & Sandboxing (Future)

- Permission system (read/write image, filesystem, network)
- Code signing for trusted plugins
- Sandboxed execution environment
- User confirmation for sensitive operations

---

## Installation & Packaging Plan

### Distribution Goals

1. **Easy installation**: Minimal steps from download to running
2. **Portable option**: Extract-and-run without installation
3. **Auto-updates**: Check for updates on startup (optional)
4. **Small size**: Optimize binary and asset sizes
5. **Multiple formats**: Cater to different user preferences

### Platform-Specific Packaging

#### Windows

**Option 1: Installer (.exe)**
- **Tool**: NSIS (Nullsoft Scriptable Install System) or WiX Toolset
- **Features**:
  - Install to Program Files
  - Create Start Menu shortcut
  - Associate .pxp file extension (Photonix Project)
  - Optional: Associate common image formats
  - Uninstaller
  - Add to PATH (optional)

**NSIS Script** (`installer.nsi`):
```nsis
!include "MUI2.nsh"

Name "Photonix"
OutFile "Photonix-v0.0.1-Setup.exe"
InstallDir "$PROGRAMFILES64\Photonix"

; Modern UI settings
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

Section "Install"
    SetOutPath "$INSTDIR"
    File /r "build\windows\*.*"
    
    CreateShortCut "$DESKTOP\Photonix.lnk" "$INSTDIR\Photonix.exe"
    CreateShortCut "$SMPROGRAMS\Photonix.lnk" "$INSTDIR\Photonix.exe"
    
    WriteUninstaller "$INSTDIR\Uninstall.exe"
SectionEnd

Section "Uninstall"
    Delete "$INSTDIR\*.*"
    RMDir "$INSTDIR"
    Delete "$DESKTOP\Photonix.lnk"
    Delete "$SMPROGRAMS\Photonix.lnk"
SectionEnd
```

**Option 2: Portable (.zip)**
- **Contents**:
  - Photonix.exe
  - Qt6 DLLs (Core, Widgets, OpenGL, OpenGLWidgets)
  - Python39.dll (embedded Python)
  - plugins/ folder (with example plugins)
  - assets/ folder
  - README.txt (quick start guide)

**windeployqt** (Qt deployment tool):
```bash
windeployqt --release --no-translations Photonix.exe
```

#### Linux

**Option 1: AppImage** (Recommended)
- **Tool**: linuxdeploy + Qt plugin
- **Features**:
  - Single-file executable
  - No installation required
  - Works on most distributions
  - Self-contained with dependencies

**Build AppImage**:
```bash
# Download linuxdeploy and Qt plugin
wget https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage
wget https://github.com/linuxdeploy/linuxdeploy-plugin-qt/releases/download/continuous/linuxdeploy-plugin-qt-x86_64.AppImage
chmod +x linuxdeploy*.AppImage

# Create AppDir
./linuxdeploy-x86_64.AppImage \
    --executable=Photonix \
    --plugin=qt \
    --appdir=AppDir \
    --output=appimage \
    --desktop-file=Photonix.desktop \
    --icon-file=assets/icons/photonix.png
```

**Option 2: Debian Package (.deb)**
- For Ubuntu/Debian users
- Proper system integration
- Dependency management via apt

**Option 3: Portable (.tar.gz)**
- Extract and run
- Similar to Windows portable

#### macOS

**Option 1: App Bundle (.app)**
- Native macOS application format
- Drag-to-Applications installation
- Code signing (for distribution outside App Store)

**Build App Bundle**:
```bash
macdeployqt Photonix.app -dmg
```

**Option 2: DMG Installer**
- Disk image with drag-to-install UI
- Background image with instructions
- Professional appearance

### Dependency Bundling

**Windows**:
- Bundle all Qt6 DLLs
- Bundle Python DLL
- Bundle OpenGL fallback (software renderer)
- vcredist (Visual C++ Redistributable) check

**Linux**:
- Embed Qt6 libraries in AppImage
- Embed Python libraries
- Rely on system OpenGL drivers

**macOS**:
- Embed Qt6 frameworks in app bundle
- Embed Python framework
- Use system OpenGL

### First-Run Experience

**On first launch**:
1. Welcome screen with quick tips
2. Ask user preferences:
   - Theme (Dark/Light)
   - Tablet support (enable if detected)
   - Telemetry opt-in (crash reports, anonymous usage data)
3. Check for updates (if enabled)
4. Create user directories:
   - `~/.photonix/` (Linux/macOS) or `%APPDATA%/Photonix` (Windows)
   - `~/.photonix/plugins/`
   - `~/.photonix/scripts/`
   - `~/.photonix/presets/`
5. Load example plugins (if included)

### Auto-Update System (Future)

- Check for updates on startup (opt-in)
- Download delta patches
- Apply updates on restart
- Rollback mechanism if update fails

---

## Development Milestones (v0.0.1)

### Milestone 1: Project Skeleton (Week 1-2)

**Goal**: Establish build system and basic application structure

**Tasks**:
1. Set up Git repository with proper `.gitignore`
2. Create directory structure (as outlined above)
3. Configure CMake build system
4. Add Qt6 and Python3 dependencies
5. Create basic `main.cpp` with Qt application
6. Implement MainWindow skeleton (empty)
7. Test compilation on Windows and Linux
8. Write initial README with build instructions

**Deliverables**:
- Compiles on Windows, Linux, macOS
- Opens empty MainWindow
- No functionality yet

**Testing**:
- Verify build on all platforms
- Check for missing dependencies

---

### Milestone 2: Rendering Canvas (Week 3-4)

**Goal**: Implement OpenGL canvas with image display

**Tasks**:
1. Implement GLCanvas (QOpenGLWidget subclass)
2. Set up OpenGL context (version 3.3+)
3. Implement GLRenderer class
4. Load test image and display as texture
5. Implement zoom (100%, fit, custom)
6. Implement pan (Space+Drag, Middle Mouse Button)
7. Add checkerboard transparency background
8. Handle window resize events
9. Optimize rendering for performance

**Deliverables**:
- Canvas displays loaded image
- Smooth zoom and pan
- Renders at 60 FPS

**Testing**:
- Load various image sizes (small, large, 4K)
- Test zoom levels (10% to 3200%)
- Test pan with different input methods
- Check for memory leaks

---

### Milestone 3: Image I/O & Layer Support (Week 5-6)

**Goal**: Load/save images and implement basic layer system

**Tasks**:
1. Implement ImageEngine class
2. Implement ImageIO (PNG, JPEG, TIFF support via STB Image)
3. Add File → Open menu action
4. Add File → Save / Save As menu actions
5. Implement LayerManager class
6. Create LayerPanel UI (list of layers)
7. Add layer visibility toggles
8. Implement layer selection
9. Render multiple layers with compositing
10. Add layer opacity support

**Deliverables**:
- Open PNG, JPEG, TIFF files
- Save in PNG, JPEG formats
- Display and manage multiple layers
- Layer opacity working

**Testing**:
- Load images of different formats
- Save and reload images
- Create multiple layers and verify rendering
- Test layer opacity (0%, 50%, 100%)

---

### Milestone 4: Basic Tools & UI Panels (Week 7-9)

**Goal**: Implement essential editing tools and UI

**Tasks**:
1. Implement Tool base class
2. Implement BrushTool (basic painting)
   - Circular brush with size and opacity
   - Paint on active layer
   - Real-time preview
3. Implement CropTool
   - Interactive crop rectangle
   - Apply crop to image
4. Implement ColorPickerTool
   - Sample color from image
5. Create ToolPanel UI (icon grid)
6. Create PropertiesPanel UI (dynamic properties)
7. Implement MenuBar (File, Edit, View, Tools)
8. Implement Undo/Redo system (History class)
9. Add keyboard shortcuts (Ctrl+Z, etc.)
10. Implement StatusBar (tool info, zoom level)

**Deliverables**:
- Functional brush, crop, and color picker tools
- Tool selection via ToolPanel
- Undo/redo working
- Complete UI layout

**Testing**:
- Paint with brush tool (various sizes, opacities)
- Crop image and verify result
- Pick colors from image
- Undo/redo multiple operations
- Test keyboard shortcuts

---

### Milestone 5: Plugin System (Week 10-12)

**Goal**: Implement Python plugin architecture

**Tasks**:
1. Embed Python interpreter (CPython)
2. Implement PythonBridge with pybind11
3. Expose core API to Python:
   - `photonix.get_active_image()`
   - `photonix.create_layer()`
   - Layer pixel access (NumPy arrays)
4. Implement PluginManager
5. Plugin discovery (scan directories)
6. Create example plugins:
   - `demo_filter.py`: Invert colors
   - `batch_resize.py`: Resize multiple files
7. Add Plugins → Manage Plugins UI
8. Add plugin enable/disable functionality
9. Write plugin development guide

**Deliverables**:
- Python plugins can be loaded
- Example plugins working
- Plugin API documented

**Testing**:
- Load and run example plugins
- Verify Python API functions
- Test plugin enable/disable
- Check for plugin conflicts

---

### Milestone 6: Packaging & Distribution (Week 13-14)

**Goal**: Create distributable installers/packages

**Tasks**:
1. Configure NSIS installer (Windows)
2. Build portable ZIP (Windows)
3. Build AppImage (Linux)
4. Build .dmg (macOS, if accessible)
5. Test installations on clean systems
6. Write user manual (basics)
7. Create quick-start guide
8. Add licensing information (GPL v3)
9. Prepare GitHub release with binaries
10. Write CONTRIBUTING.md for future contributors

**Deliverables**:
- Windows installer (.exe)
- Windows portable (.zip)
- Linux AppImage
- macOS DMG (if available)
- Documentation

**Testing**:
- Install on Windows 10, 11
- Test on Ubuntu 22.04, Fedora 38
- Test on macOS 12+ (if available)
- Verify all features work in installed version

---

### Post-v0.0.1 Roadmap (Future Versions)

**v0.1.0** (3-6 months):
- More tools: Selection tools, transform tools, filters
- Layer blend modes (Multiply, Screen, Overlay)
- Preferences dialog with customization
- Plugin marketplace/repository
- Performance optimizations

**v0.2.0** (6-12 months):
- Text tool (text layers)
- Vector shapes
- Adjustment layers
- Color management (ICC profiles)
- Batch processing UI

**v1.0.0** (12-18 months):
- Full feature set comparable to GIMP/Photoshop basics
- Stable API for plugins
- Comprehensive documentation
- Large plugin ecosystem
- AI tool integration (SDXL, etc.)

---

## Testing & Documentation Strategy

### Testing Approach

#### Unit Tests (C++)
- **Framework**: Google Test or Catch2
- **Location**: `tests/core/`, `tests/ui/`, `tests/render/`
- **Coverage**: Core classes (ImageEngine, LayerManager, History)

**Example Test** (`tests/core/test_image_engine.cpp`):
```cpp
#include <gtest/gtest.h>
#include "core/ImageEngine.h"

TEST(ImageEngineTest, CreateImage) {
    ImageEngine engine(800, 600, ColorMode::RGB);
    EXPECT_EQ(engine.getWidth(), 800);
    EXPECT_EQ(engine.getHeight(), 600);
    EXPECT_EQ(engine.getColorMode(), ColorMode::RGB);
}

TEST(ImageEngineTest, PixelAccess) {
    ImageEngine engine(100, 100, ColorMode::RGB);
    engine.setPixel(50, 50, Color(255, 0, 0));
    Color pixel = engine.getPixel(50, 50);
    EXPECT_EQ(pixel.r, 255);
    EXPECT_EQ(pixel.g, 0);
    EXPECT_EQ(pixel.b, 0);
}
```

#### Integration Tests
- Test plugin loading and execution
- Test file I/O with various formats
- Test undo/redo with complex operations

#### Manual Testing
- UI/UX testing with real workflows
- Performance testing with large images
- Cross-platform compatibility testing

### Documentation Strategy

#### For Developers

1. **architecture.md**: System design overview
   - Module interactions
   - Class hierarchy diagrams
   - Data flow diagrams

2. **build_guide.md**: Building from source
   - Prerequisites for each platform
   - Step-by-step build instructions
   - Troubleshooting common issues

3. **plugin_guide.md**: Plugin development
   - Python API reference
   - Example plugins with explanations
   - Best practices
   - Testing plugins

4. **api_reference.md**: Detailed API docs
   - Auto-generated from code comments (Doxygen)
   - Python API with examples
   - C++ API for native plugins

5. **CONTRIBUTING.md**: Contribution guidelines
   - Code style guide (clang-format config)
   - Pull request process
   - Issue reporting template
   - Community conduct

#### For Users

1. **user_manual.md**: End-user guide
   - Getting started
   - Interface overview
   - Tool tutorials
   - FAQ

2. **README.md**: Project overview
   - Quick description
   - Screenshots
   - Installation instructions
   - Quick start guide
   - Links to documentation

3. **Quick Start Guide** (in-app):
   - First-time user tutorial
   - Tool demonstrations
   - Keyboard shortcuts cheatsheet

### Code Documentation

**C++ Code Comments** (Doxygen style):
```cpp
/**
 * @brief Manages image data and provides pixel-level access.
 * 
 * The ImageEngine class is the core data structure for images in Photonix.
 * It handles pixel storage, color space management, and basic image operations.
 */
class ImageEngine {
public:
    /**
     * @brief Constructs an ImageEngine with specified dimensions.
     * 
     * @param width Image width in pixels
     * @param height Image height in pixels
     * @param colorMode Color mode (RGB, RGBA, GRAYSCALE)
     */
    ImageEngine(int width, int height, ColorMode colorMode);
    
    /**
     * @brief Resizes the image to new dimensions.
     * 
     * @param newWidth New width in pixels
     * @param newHeight New height in pixels
     * @param interpolation Interpolation method ("nearest", "bilinear", "bicubic")
     * @return true if resize successful, false otherwise
     */
    bool resize(int newWidth, int newHeight, const std::string& interpolation = "bilinear");
    
    // ... more methods
};
```

**Python API Comments** (docstrings):
```python
def get_active_image():
    """
    Returns the currently active image in the editor.
    
    Returns:
        Image: The active Image object, or None if no image is open.
    
    Example:
        >>> img = photonix.get_active_image()
        >>> if img:
        >>>     print(f"Image dimensions: {img.get_dimensions()}")
    """
    pass
```

---

## Build Instructions

### Prerequisites

#### All Platforms
- CMake 3.20+
- Qt6 (6.5 or later)
- Python 3.9+
- Git

#### Windows
- Visual Studio 2019 or 2022 (Community Edition)
- Qt6 for MSVC
- Python 3.9+ (from python.org)

#### Linux
- GCC 9+ or Clang 10+
- Qt6 development packages
- Python 3 development packages
- OpenGL development packages

**Ubuntu/Debian**:
```bash
sudo apt update
sudo apt install build-essential cmake git
sudo apt install qt6-base-dev qt6-opengl-dev qt6-openglwidgets-dev
sudo apt install python3-dev python3-pip libgl1-mesa-dev
```

**Fedora**:
```bash
sudo dnf install cmake gcc-c++ git
sudo dnf install qt6-qtbase-devel qt6-qtopengl-devel qt6-qtopenglwidgets-devel
sudo dnf install python3-devel mesa-libGL-devel
```

#### macOS
- Xcode Command Line Tools
- Qt6 (via Homebrew or official installer)
- Python 3 (via Homebrew)

```bash
xcode-select --install
brew install qt@6 python@3.9 cmake
```

### Building from Source

#### Clone Repository
```bash
git clone https://github.com/yourusername/photonix.git
cd photonix
git submodule update --init --recursive
```

#### Build (All Platforms)

**Configure**:
```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
```

**Build**:
```bash
cmake --build . --config Release
```

#### Platform-Specific Notes

**Windows**:
- Use Visual Studio solution or `cmake --build . --config Release`
- Executable: `build/Release/Photonix.exe`

**Linux**:
- Use `make -j$(nproc)` for faster builds
- Executable: `build/Photonix`

**macOS**:
- Executable: `build/Photonix.app`
- Run: `open build/Photonix.app`

### Running Tests

```bash
cd build
ctest --output-on-failure
```

### Creating Packages

**Windows Installer**:
```bash
# Install NSIS first
cd build
cpack -G NSIS
```

**Linux AppImage**:
```bash
# Use linuxdeploy (see Packaging section)
./create_appimage.sh
```

**macOS DMG**:
```bash
cd build
macdeployqt Photonix.app -dmg
```

---

## Next Steps

### Immediate Actions (Post-Plan)

1. **Set up development environment**: Install Qt6, Python, CMake
2. **Create Git repository**: Initialize with proper structure
3. **Begin Milestone 1**: Project skeleton and build system
4. **Regular commits**: Commit frequently with clear messages
5. **Documentation as you go**: Update docs with changes

### Development Best Practices

1. **Version Control**:
   - Use feature branches (e.g., `feature/brush-tool`)
   - Write meaningful commit messages
   - Tag releases (e.g., `v0.0.1-alpha`)

2. **Code Quality**:
   - Follow C++17 best practices
   - Use clang-format for consistent style
   - Run static analysis tools (clang-tidy)
   - Write unit tests for core functionality

3. **Collaboration**:
   - Use GitHub Issues for bug tracking
   - Use Pull Requests for code review
   - Write clear PR descriptions
   - Respond to community feedback

4. **Release Cycle**:
   - Alpha releases: For testing (not feature-complete)
   - Beta releases: Feature-complete, fixing bugs
   - Stable releases: Production-ready

### Questions for Clarification

Before starting implementation, please confirm:

1. **Target Audience**: Are we focusing on photo editing (photography) or more general digital art/painting (like Krita)?
2. **Minimum System Requirements**: Should we support older systems (Windows 7, older OpenGL versions)?
3. **Initial Tool Priority**: Which tools are most critical for v0.0.1? (Brush, crop, and color picker are included, but are there others?)
4. **AI Integration**: Should v0.0.1 include any AI features, or is the plugin system foundation enough?
5. **Licensing**: Confirm GPL v3 for project (compatible with Qt and Python)

---

## Conclusion

This development plan provides a comprehensive roadmap for Photonix v0.0.1, covering:

- **Architecture**: Modular, extensible design with clear separation of concerns
- **Technology**: Modern stack (Qt6, OpenGL, Python) for performance and portability
- **UI/UX**: Clean, professional interface inspired by Pixlr and Krita
- **Plugins**: Flexible Python-based plugin system for extensibility
- **Packaging**: Easy installation across Windows, Linux, and macOS
- **Milestones**: 14-week development timeline with clear deliverables
- **Documentation**: Comprehensive guides for developers and users

The plan is designed to be **immediately actionable**, with step-by-step milestones that progressively build functionality. The architecture is **modular and extensible**, allowing for future enhancements without major rewrites.

**Ready to start building? Let's create something amazing!** 🚀

---

*Document Version: 1.0*  
*Last Updated: 2025-11-06*  
*Project: Photonix v0.0.1*  
*License: GPL v3*
