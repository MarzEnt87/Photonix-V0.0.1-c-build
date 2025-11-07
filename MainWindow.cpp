/**
 * @file MainWindow.cpp
 * @brief Implementation of MainWindow class
 */

#include "MainWindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QCloseEvent>
#include <QDebug>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , currentFilePath("")
    , isModified(false)
{
    qDebug() << "Initializing MainWindow...";
    
    // Set window properties
    setWindowTitle("Photonix");
    resize(1280, 720);
    
    // Create UI components
    createActions();
    createMenus();
    createToolbars();
    createStatusBar();
    setupCentralWidget();
    createDockPanels();
    
    // Load saved settings
    loadSettings();
    
    // Update UI state
    updateWindowTitle();
    updateStatusBar();
    
    qDebug() << "MainWindow initialization complete";
}

MainWindow::~MainWindow()
{
    qDebug() << "Destroying MainWindow";
    saveSettings();
}

void MainWindow::createActions()
{
    // File menu actions
    newAction = new QAction(QIcon::fromTheme("document-new"), tr("&New..."), this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new image"));
    connect(newAction, &QAction::triggered, this, &MainWindow::newImage);
    
    openAction = new QAction(QIcon::fromTheme("document-open"), tr("&Open..."), this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing image"));
    connect(openAction, &QAction::triggered, this, &MainWindow::openImage);
    
    saveAction = new QAction(QIcon::fromTheme("document-save"), tr("&Save"), this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the current image"));
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveImage);
    
    saveAsAction = new QAction(QIcon::fromTheme("document-save-as"), tr("Save &As..."), this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save the image with a new name"));
    connect(saveAsAction, &QAction::triggered, this, &MainWindow::saveImageAs);
    
    closeAction = new QAction(tr("&Close"), this);
    closeAction->setShortcut(QKeySequence::Close);
    closeAction->setStatusTip(tr("Close the current image"));
    connect(closeAction, &QAction::triggered, this, &MainWindow::closeImage);
    
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit Photonix"));
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApplication);
    
    // Edit menu actions
    undoAction = new QAction(QIcon::fromTheme("edit-undo"), tr("&Undo"), this);
    undoAction->setShortcut(QKeySequence::Undo);
    undoAction->setStatusTip(tr("Undo the last action"));
    undoAction->setEnabled(false);
    connect(undoAction, &QAction::triggered, this, &MainWindow::undo);
    
    redoAction = new QAction(QIcon::fromTheme("edit-redo"), tr("&Redo"), this);
    redoAction->setShortcut(QKeySequence::Redo);
    redoAction->setStatusTip(tr("Redo the last undone action"));
    redoAction->setEnabled(false);
    connect(redoAction, &QAction::triggered, this, &MainWindow::redo);
    
    cutAction = new QAction(QIcon::fromTheme("edit-cut"), tr("Cu&t"), this);
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut the selection"));
    connect(cutAction, &QAction::triggered, this, &MainWindow::cut);
    
    copyAction = new QAction(QIcon::fromTheme("edit-copy"), tr("&Copy"), this);
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy the selection"));
    connect(copyAction, &QAction::triggered, this, &MainWindow::copy);
    
    pasteAction = new QAction(QIcon::fromTheme("edit-paste"), tr("&Paste"), this);
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste from clipboard"));
    connect(pasteAction, &QAction::triggered, this, &MainWindow::paste);
    
    preferencesAction = new QAction(tr("&Preferences..."), this);
    preferencesAction->setShortcut(QKeySequence::Preferences);
    preferencesAction->setStatusTip(tr("Configure Photonix settings"));
    connect(preferencesAction, &QAction::triggered, this, &MainWindow::preferences);
    
    // View menu actions
    zoomInAction = new QAction(QIcon::fromTheme("zoom-in"), tr("Zoom &In"), this);
    zoomInAction->setShortcut(QKeySequence::ZoomIn);
    zoomInAction->setStatusTip(tr("Zoom in on the image"));
    connect(zoomInAction, &QAction::triggered, this, &MainWindow::zoomIn);
    
    zoomOutAction = new QAction(QIcon::fromTheme("zoom-out"), tr("Zoom &Out"), this);
    zoomOutAction->setShortcut(QKeySequence::ZoomOut);
    zoomOutAction->setStatusTip(tr("Zoom out on the image"));
    connect(zoomOutAction, &QAction::triggered, this, &MainWindow::zoomOut);
    
    zoomToFitAction = new QAction(QIcon::fromTheme("zoom-fit-best"), tr("&Fit to Window"), this);
    zoomToFitAction->setShortcut(tr("Ctrl+0"));
    zoomToFitAction->setStatusTip(tr("Fit the image to the window"));
    connect(zoomToFitAction, &QAction::triggered, this, &MainWindow::zoomToFit);
    
    zoom100Action = new QAction(QIcon::fromTheme("zoom-original"), tr("&100%"), this);
    zoom100Action->setShortcut(tr("Ctrl+1"));
    zoom100Action->setStatusTip(tr("View at 100% zoom"));
    connect(zoom100Action, &QAction::triggered, this, &MainWindow::zoom100);
    
    fullscreenAction = new QAction(tr("&Fullscreen"), this);
    fullscreenAction->setShortcut(Qt::Key_F11);
    fullscreenAction->setStatusTip(tr("Toggle fullscreen mode"));
    fullscreenAction->setCheckable(true);
    connect(fullscreenAction, &QAction::triggered, this, &MainWindow::toggleFullscreen);
    
    // Help menu actions
    aboutAction = new QAction(tr("&About Photonix"), this);
    aboutAction->setStatusTip(tr("Show information about Photonix"));
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
    
    helpAction = new QAction(QIcon::fromTheme("help-contents"), tr("&Help"), this);
    helpAction->setShortcut(QKeySequence::HelpContents);
    helpAction->setStatusTip(tr("Show Photonix help"));
    connect(helpAction, &QAction::triggered, this, &MainWindow::showHelp);
}

void MainWindow::createMenus()
{
    // File menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(closeAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    
    // Edit menu
    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addSeparator();
    editMenu->addAction(preferencesAction);
    
    // View menu
    viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(zoomInAction);
    viewMenu->addAction(zoomOutAction);
    viewMenu->addAction(zoomToFitAction);
    viewMenu->addAction(zoom100Action);
    viewMenu->addSeparator();
    viewMenu->addAction(fullscreenAction);
    
    // Layer menu (placeholder for now)
    layerMenu = menuBar()->addMenu(tr("&Layer"));
    
    // Tools menu (placeholder for now)
    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    
    // Plugins menu (placeholder for now)
    pluginsMenu = menuBar()->addMenu(tr("&Plugins"));
    
    // Help menu
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAction);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutAction);
}

void MainWindow::createToolbars()
{
    // Main toolbar
    mainToolbar = addToolBar(tr("Main Toolbar"));
    mainToolbar->setObjectName("MainToolbar"); // For settings persistence
    mainToolbar->addAction(newAction);
    mainToolbar->addAction(openAction);
    mainToolbar->addAction(saveAction);
    mainToolbar->addSeparator();
    mainToolbar->addAction(undoAction);
    mainToolbar->addAction(redoAction);
    mainToolbar->addSeparator();
    mainToolbar->addAction(zoomInAction);
    mainToolbar->addAction(zoomOutAction);
    mainToolbar->addAction(zoomToFitAction);
}

void MainWindow::createDockPanels()
{
    // Tool panel (left side) - will be implemented in Milestone 4
    toolDock = new QDockWidget(tr("Tools"), this);
    toolDock->setObjectName("ToolDock");
    QWidget *toolWidget = new QWidget();
    QLabel *toolLabel = new QLabel("Tool Panel\n(Coming in Milestone 4)", toolWidget);
    toolLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *toolLayout = new QVBoxLayout(toolWidget);
    toolLayout->addWidget(toolLabel);
    toolDock->setWidget(toolWidget);
    addDockWidget(Qt::LeftDockWidgetArea, toolDock);
    
    // Layer panel (right side) - will be implemented in Milestone 3
    layerDock = new QDockWidget(tr("Layers"), this);
    layerDock->setObjectName("LayerDock");
    QWidget *layerWidget = new QWidget();
    QLabel *layerLabel = new QLabel("Layer Panel\n(Coming in Milestone 3)", layerWidget);
    layerLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *layerLayout = new QVBoxLayout(layerWidget);
    layerLayout->addWidget(layerLabel);
    layerDock->setWidget(layerWidget);
    addDockWidget(Qt::RightDockWidgetArea, layerDock);
    
    // Properties panel (right side, below layers) - will be implemented in Milestone 4
    propertiesDock = new QDockWidget(tr("Properties"), this);
    propertiesDock->setObjectName("PropertiesDock");
    QWidget *propsWidget = new QWidget();
    QLabel *propsLabel = new QLabel("Properties Panel\n(Coming in Milestone 4)", propsWidget);
    propsLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *propsLayout = new QVBoxLayout(propsWidget);
    propsLayout->addWidget(propsLabel);
    propertiesDock->setWidget(propsWidget);
    addDockWidget(Qt::RightDockWidgetArea, propertiesDock);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::setupCentralWidget()
{
    // Create central widget with placeholder for canvas
    // Canvas will be implemented in Milestone 2
    centralWidget = new QWidget(this);
    
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    QLabel *placeholder = new QLabel("Canvas Area\n(OpenGL Canvas coming in Milestone 2)", centralWidget);
    placeholder->setAlignment(Qt::AlignCenter);
    placeholder->setStyleSheet("QLabel { background-color: #2B2B2B; color: #CCCCCC; font-size: 24px; }");
    layout->addWidget(placeholder);
    
    setCentralWidget(centralWidget);
}

// File menu action implementations
void MainWindow::newImage()
{
    qDebug() << "New image action triggered";
    QMessageBox::information(this, tr("New Image"),
        tr("New image dialog will be implemented in Milestone 3."));
}

void MainWindow::openImage()
{
    qDebug() << "Open image action triggered";
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "",
        tr("Images (*.png *.jpg *.jpeg *.tiff *.tif *.bmp);;All Files (*)"));
    
    if (!fileName.isEmpty()) {
        qDebug() << "Selected file:" << fileName;
        QMessageBox::information(this, tr("Open Image"),
            tr("Image loading will be implemented in Milestone 3.\n\nSelected: %1").arg(fileName));
    }
}

void MainWindow::saveImage()
{
    qDebug() << "Save image action triggered";
    QMessageBox::information(this, tr("Save Image"),
        tr("Image saving will be implemented in Milestone 3."));
}

void MainWindow::saveImageAs()
{
    qDebug() << "Save image as action triggered";
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Image As"), "",
        tr("PNG Image (*.png);;JPEG Image (*.jpg *.jpeg);;TIFF Image (*.tiff *.tif)"));
    
    if (!fileName.isEmpty()) {
        qDebug() << "Selected save path:" << fileName;
        QMessageBox::information(this, tr("Save Image As"),
            tr("Image saving will be implemented in Milestone 3.\n\nWould save to: %1").arg(fileName));
    }
}

void MainWindow::closeImage()
{
    qDebug() << "Close image action triggered";
    // Will be implemented when image management is added
}

void MainWindow::exitApplication()
{
    qDebug() << "Exit application triggered";
    close();
}

// Edit menu action implementations
void MainWindow::undo()
{
    qDebug() << "Undo action triggered";
    // Will be implemented with History system in Milestone 4
}

void MainWindow::redo()
{
    qDebug() << "Redo action triggered";
    // Will be implemented with History system in Milestone 4
}

void MainWindow::cut()
{
    qDebug() << "Cut action triggered";
    // Will be implemented with selection tools
}

void MainWindow::copy()
{
    qDebug() << "Copy action triggered";
    // Will be implemented with selection tools
}

void MainWindow::paste()
{
    qDebug() << "Paste action triggered";
    // Will be implemented with clipboard support
}

void MainWindow::preferences()
{
    qDebug() << "Preferences action triggered";
    QMessageBox::information(this, tr("Preferences"),
        tr("Preferences dialog will be implemented in a future update."));
}

// View menu action implementations
void MainWindow::zoomIn()
{
    qDebug() << "Zoom in action triggered";
    // Will be implemented with canvas in Milestone 2
}

void MainWindow::zoomOut()
{
    qDebug() << "Zoom out action triggered";
    // Will be implemented with canvas in Milestone 2
}

void MainWindow::zoomToFit()
{
    qDebug() << "Zoom to fit action triggered";
    // Will be implemented with canvas in Milestone 2
}

void MainWindow::zoom100()
{
    qDebug() << "Zoom 100% action triggered";
    // Will be implemented with canvas in Milestone 2
}

void MainWindow::toggleFullscreen()
{
    if (isFullScreen()) {
        showNormal();
    } else {
        showFullScreen();
    }
}

// Help menu action implementations
void MainWindow::showAbout()
{
    QMessageBox::about(this, tr("About Photonix"),
        tr("<h2>Photonix v0.0.1</h2>"
           "<p>Professional-grade open-source photo editing suite</p>"
           "<p>Built with Qt6, OpenGL, and Python</p>"
           "<p>License: GPL v3</p>"
           "<p><a href='https://github.com/yourusername/photonix'>GitHub Repository</a></p>"));
}

void MainWindow::showHelp()
{
    qDebug() << "Help action triggered";
    QMessageBox::information(this, tr("Help"),
        tr("User manual will be available in the docs/ folder."));
}

// Helper methods
void MainWindow::updateWindowTitle()
{
    QString title = "Photonix";
    
    if (!currentFilePath.isEmpty()) {
        title += " - " + QFileInfo(currentFilePath).fileName();
    }
    
    if (isModified) {
        title += " *";
    }
    
    setWindowTitle(title);
}

void MainWindow::updateStatusBar()
{
    if (currentFilePath.isEmpty()) {
        statusBar()->showMessage(tr("Ready"));
    } else {
        statusBar()->showMessage(tr("Current file: %1").arg(currentFilePath));
    }
}

void MainWindow::loadSettings()
{
    QSettings settings;
    
    // Restore window geometry
    restoreGeometry(settings.value("mainWindow/geometry").toByteArray());
    restoreState(settings.value("mainWindow/state").toByteArray());
    
    qDebug() << "Settings loaded";
}

void MainWindow::saveSettings()
{
    QSettings settings;
    
    // Save window geometry
    settings.setValue("mainWindow/geometry", saveGeometry());
    settings.setValue("mainWindow/state", saveState());
    
    qDebug() << "Settings saved";
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (isModified) {
        QMessageBox::StandardButton response = QMessageBox::question(this,
            tr("Unsaved Changes"),
            tr("You have unsaved changes. Do you want to save before closing?"),
            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        
        if (response == QMessageBox::Save) {
            saveImage();
            event->accept();
        } else if (response == QMessageBox::Discard) {
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        event->accept();
    }
    
    if (event->isAccepted()) {
        saveSettings();
    }
}
