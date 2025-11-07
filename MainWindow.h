/**
 * @file MainWindow.h
 * @brief Main application window for Photonix
 * 
 * The MainWindow class provides the primary user interface container,
 * including menu bar, toolbars, dock panels, and canvas area.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QAction>
#include <QString>

// Forward declarations (will be implemented in later milestones)
class GLCanvas;
class ToolPanel;
class LayerPanel;
class PropertiesPanel;

/**
 * @class MainWindow
 * @brief Main application window
 * 
 * MainWindow manages the overall application layout, including:
 * - Menu bar (File, Edit, View, Layer, Tools, Plugins, Help)
 * - Toolbar with quick actions
 * - Central canvas area for image editing
 * - Dock panels for tools, layers, and properties
 * - Status bar with image information
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the main window
     * @param parent Parent widget (typically nullptr for main window)
     */
    explicit MainWindow(QWidget *parent = nullptr);
    
    /**
     * @brief Destructor
     */
    ~MainWindow();

private:
    // UI Creation methods
    void createActions();
    void createMenus();
    void createToolbars();
    void createDockPanels();
    void createStatusBar();
    void setupCentralWidget();
    
    // File menu actions
    void newImage();
    void openImage();
    void saveImage();
    void saveImageAs();
    void closeImage();
    void exitApplication();
    
    // Edit menu actions
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void preferences();
    
    // View menu actions
    void zoomIn();
    void zoomOut();
    void zoomToFit();
    void zoom100();
    void toggleFullscreen();
    
    // Help menu actions
    void showAbout();
    void showHelp();
    
    // Helper methods
    void updateWindowTitle();
    void updateStatusBar();
    void loadSettings();
    void saveSettings();
    
protected:
    /**
     * @brief Handle window close event
     * @param event Close event
     */
    void closeEvent(QCloseEvent *event) override;

private:
    // Menu bar
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *layerMenu;
    QMenu *toolsMenu;
    QMenu *pluginsMenu;
    QMenu *helpMenu;
    
    // Toolbars
    QToolBar *mainToolbar;
    
    // Actions - File menu
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *closeAction;
    QAction *exitAction;
    
    // Actions - Edit menu
    QAction *undoAction;
    QAction *redoAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *preferencesAction;
    
    // Actions - View menu
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *zoomToFitAction;
    QAction *zoom100Action;
    QAction *fullscreenAction;
    
    // Actions - Help menu
    QAction *aboutAction;
    QAction *helpAction;
    
    // Dock widgets (will be implemented in later milestones)
    QDockWidget *toolDock;
    QDockWidget *layerDock;
    QDockWidget *propertiesDock;
    
    // Central widget (canvas will be added in Milestone 2)
    QWidget *centralWidget;
    
    // Component pointers (to be implemented)
    // GLCanvas *canvas;
    // ToolPanel *toolPanel;
    // LayerPanel *layerPanel;
    // PropertiesPanel *propertiesPanel;
    
    // State
    QString currentFilePath;
    bool isModified;
};

#endif // MAINWINDOW_H
