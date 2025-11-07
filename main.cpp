/**
 * @file main.cpp
 * @brief Entry point for Photonix photo editor
 * 
 * Photonix - Professional-grade open-source photo editing suite
 * Version: 0.0.1
 * License: GPL v3
 */

#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "ui/MainWindow.h"

int main(int argc, char *argv[])
{
    // Create Qt application
    QApplication app(argc, argv);
    
    // Set application metadata
    QApplication::setApplicationName("Photonix");
    QApplication::setApplicationVersion("0.0.1");
    QApplication::setOrganizationName("Photonix");
    QApplication::setOrganizationDomain("photonix.org");
    
    qDebug() << "Starting Photonix v0.0.1";
    qDebug() << "Qt version:" << qVersion();
    
    try {
        // Create and show main window
        MainWindow mainWindow;
        mainWindow.show();
        
        qDebug() << "Main window created and displayed";
        
        // Start event loop
        return app.exec();
    }
    catch (const std::exception& e) {
        qCritical() << "Fatal error:" << e.what();
        QMessageBox::critical(nullptr, "Fatal Error", 
            QString("Photonix encountered a fatal error:\n\n%1").arg(e.what()));
        return 1;
    }
    catch (...) {
        qCritical() << "Unknown fatal error occurred";
        QMessageBox::critical(nullptr, "Fatal Error",
            "Photonix encountered an unknown fatal error.");
        return 1;
    }
}
