# Contributing to Photonix

Thank you for your interest in contributing to Photonix! This document provides guidelines and information for contributors.

## Table of Contents
- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Development Workflow](#development-workflow)
- [Coding Standards](#coding-standards)
- [Submitting Changes](#submitting-changes)
- [Reporting Bugs](#reporting-bugs)
- [Requesting Features](#requesting-features)

---

## Code of Conduct

### Our Pledge
We are committed to providing a welcoming and inspiring community for all. Please be respectful and constructive in all interactions.

### Expected Behavior
- Be respectful and inclusive
- Accept constructive criticism gracefully
- Focus on what is best for the community
- Show empathy towards other community members

### Unacceptable Behavior
- Harassment, discrimination, or offensive comments
- Trolling or insulting remarks
- Publishing others' private information
- Other conduct which could reasonably be considered inappropriate

---

## Getting Started

### Prerequisites
1. Familiarity with C++17 and Qt6
2. Understanding of Git and GitHub workflow
3. Read the [Architecture Documentation](docs/architecture.md)
4. Build Photonix successfully on your system (see [Build Guide](docs/build_guide.md))

### Setting Up Development Environment

1. **Fork the repository** on GitHub

2. **Clone your fork**
```bash
git clone https://github.com/YOUR_USERNAME/photonix.git
cd photonix
```

3. **Add upstream remote**
```bash
git remote add upstream https://github.com/yourusername/photonix.git
```

4. **Create a development branch**
```bash
git checkout -b feature/my-new-feature
```

5. **Build and test**
```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

---

## Development Workflow

### Branch Naming Convention
- **Features**: `feature/feature-name` (e.g., `feature/brush-tool`)
- **Bug fixes**: `fix/bug-description` (e.g., `fix/crash-on-save`)
- **Documentation**: `docs/what-changed` (e.g., `docs/update-api-reference`)
- **Refactoring**: `refactor/what-changed` (e.g., `refactor/render-pipeline`)

### Commit Messages
Follow the conventional commits format:

```
type(scope): brief description

Detailed explanation of changes (optional)

Fixes #issue_number (if applicable)
```

**Types**:
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting, no logic change)
- `refactor`: Code refactoring
- `test`: Adding or updating tests
- `chore`: Build process or auxiliary tool changes

**Examples**:
```
feat(render): add OpenGL canvas with zoom and pan

Implements GLCanvas widget using QOpenGLWidget.
Supports mouse-based zoom and pan operations.

Closes #12
```

```
fix(ui): prevent crash when closing unsaved image

Added proper null check in MainWindow::closeImage()

Fixes #45
```

### Keeping Your Branch Updated
```bash
# Fetch latest changes from upstream
git fetch upstream

# Merge upstream changes into your branch
git checkout main
git merge upstream/main

# Rebase your feature branch
git checkout feature/my-feature
git rebase main
```

---

## Coding Standards

### C++ Style Guide

#### Naming Conventions
- **Classes**: `PascalCase` (e.g., `ImageEngine`, `MainWindow`)
- **Functions/Methods**: `camelCase` (e.g., `loadImage()`, `applyFilter()`)
- **Variables**: `camelCase` (e.g., `currentLayer`, `zoomLevel`)
- **Constants**: `UPPER_SNAKE_CASE` (e.g., `MAX_ZOOM_LEVEL`)
- **Private members**: prefix with `m_` (e.g., `m_canvas`, `m_layers`)

#### File Organization
- Header files: `.h` extension
- Source files: `.cpp` extension
- One class per file (generally)
- Header guards: `#ifndef CLASSNAME_H` / `#define CLASSNAME_H` / `#endif`

#### Code Formatting
```cpp
// Class declaration
class ImageEngine {
public:
    ImageEngine(int width, int height);
    ~ImageEngine();
    
    bool loadImage(const QString& path);
    void saveImage(const QString& path);
    
private:
    int m_width;
    int m_height;
    QImage m_image;
};

// Function implementation
bool ImageEngine::loadImage(const QString& path)
{
    if (path.isEmpty()) {
        return false;
    }
    
    m_image = QImage(path);
    return !m_image.isNull();
}
```

#### Best Practices
- Use smart pointers (`std::unique_ptr`, `std::shared_ptr`) over raw pointers
- Prefer `const` references for parameters: `void process(const QImage& image)`
- Use `nullptr` instead of `NULL` or `0`
- Initialize all member variables in constructor
- Use RAII (Resource Acquisition Is Initialization)
- Avoid memory leaks - use Qt parent-child relationship for QObject-based classes

### Documentation

#### Header Comments
```cpp
/**
 * @file ImageEngine.h
 * @brief Core image data management
 * 
 * The ImageEngine class handles all image data operations including
 * loading, saving, and pixel-level manipulations.
 */
```

#### Class Documentation
```cpp
/**
 * @class ImageEngine
 * @brief Manages image data and provides pixel access
 * 
 * ImageEngine is the central class for image representation in Photonix.
 * It provides efficient pixel buffer management and color space handling.
 * 
 * Example usage:
 * @code
 * ImageEngine engine(800, 600);
 * engine.loadImage("photo.png");
 * QImage img = engine.getImage();
 * @endcode
 */
class ImageEngine {
    // ...
};
```

#### Function Documentation
```cpp
/**
 * @brief Resizes the image to specified dimensions
 * 
 * @param newWidth Target width in pixels
 * @param newHeight Target height in pixels
 * @param interpolation Interpolation method ("nearest", "bilinear", "bicubic")
 * @return true if resize successful, false otherwise
 * 
 * The resize operation creates a new image buffer and copies data
 * using the specified interpolation method. Original data is preserved
 * until the operation completes successfully.
 */
bool resize(int newWidth, int newHeight, const QString& interpolation = "bilinear");
```

### Qt-Specific Guidelines
- Use Qt signal/slot mechanism for loose coupling
- Use Qt containers (`QVector`, `QList`, `QString`) when interfacing with Qt APIs
- Use Qt's parent-child relationship for automatic memory management
- Prefer `Q_OBJECT` macro for classes that use signals/slots
- Use `tr()` for all user-facing strings (internationalization)

---

## Submitting Changes

### Before Submitting

1. **Ensure code compiles** without warnings
```bash
cmake --build . --verbose
```

2. **Test your changes** thoroughly
   - Manual testing of affected functionality
   - Run existing tests (when available)

3. **Update documentation** if needed
   - Update relevant .md files
   - Add code comments
   - Update API documentation

4. **Check code style**
   - Follow coding standards above
   - Run clang-format (if available)

### Pull Request Process

1. **Push your branch** to your fork
```bash
git push origin feature/my-feature
```

2. **Create Pull Request** on GitHub
   - Go to your fork on GitHub
   - Click "New Pull Request"
   - Select your branch
   - Fill out the PR template

3. **PR Description Template**
```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Code refactoring

## Changes Made
- List key changes
- Explain technical decisions
- Note any breaking changes

## Testing
- Describe testing performed
- List test cases covered

## Screenshots (if applicable)
Include before/after screenshots for UI changes

## Related Issues
Closes #issue_number
```

4. **Code Review**
   - Address reviewer feedback
   - Make requested changes
   - Push additional commits to same branch
   - PR will update automatically

5. **Merging**
   - Maintainer will merge when approved
   - Branch will be deleted after merge

---

## Reporting Bugs

### Before Reporting
1. Search existing issues to avoid duplicates
2. Verify bug exists in latest version
3. Try to reproduce consistently

### Bug Report Template
```markdown
**Description**
Clear description of the bug

**Steps to Reproduce**
1. Step one
2. Step two
3. Step three

**Expected Behavior**
What should happen

**Actual Behavior**
What actually happens

**Environment**
- OS: [e.g., Windows 11, Ubuntu 22.04]
- Photonix Version: [e.g., 0.0.1]
- Qt Version: [e.g., 6.5.3]
- GPU: [e.g., NVIDIA GTX 1660]

**Additional Context**
- Screenshots
- Error messages
- Log output
```

---

## Requesting Features

### Feature Request Template
```markdown
**Feature Description**
Clear description of proposed feature

**Use Case**
Why is this feature needed?
What problem does it solve?

**Proposed Solution**
How should it work?
Any UI mockups?

**Alternatives Considered**
Other approaches you've thought about

**Additional Context**
Any other relevant information
```

---

## Development Milestones

### Current Focus (v0.0.1)
- Milestone 2: OpenGL Canvas
- Milestone 3: Image I/O & Layers
- Milestone 4: Basic Tools
- Milestone 5: Plugin System
- Milestone 6: Packaging

Good areas for contribution:
- Bug fixes in existing code
- Documentation improvements
- Unit tests
- Example plugins (when plugin system is ready)

---

## Questions?

- **General Questions**: GitHub Discussions
- **Bug Reports**: GitHub Issues
- **Feature Requests**: GitHub Issues
- **Security Issues**: Email maintainers privately

---

## Recognition

Contributors will be recognized in:
- CONTRIBUTORS.md file
- Release notes
- About dialog in application

Thank you for contributing to Photonix! 🎨✨
