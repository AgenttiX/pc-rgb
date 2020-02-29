#include "trayicon.h"

#include <QApplication>

TrayIcon::TrayIcon()
{
    // Context menu
    openAction_ = new QAction(tr("&Open GUI"), this);
    quitAction_ = new QAction(tr("&Quit"), this);
    connect(openAction_, &QAction::triggered, this, &TrayIcon::openMainWindow);
    connect(quitAction_, &QAction::triggered, qApp, &QCoreApplication::quit);

    trayIconMenu_ = new QMenu;
    trayIconMenu_->addAction(openAction_);
    trayIconMenu_->addAction(quitAction_);
    this->setContextMenu(trayIconMenu_);

    // Icon
    icon_ = QIcon(":/tray/RGB_color_wheel_24.svg");
    this->setIcon(icon_);
    // this->setToolTip(icon_);
}

void TrayIcon::openMainWindow()
{
    mainWindow_ = new MainWindow;
    mainWindow_->setWindowIcon(icon_);
    mainWindow_->show();
}
