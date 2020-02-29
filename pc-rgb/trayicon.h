#ifndef TRAYICON_H
#define TRAYICON_H

#include "mainwindow.h"

#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>


class TrayIcon : public QSystemTrayIcon
{
public:
    TrayIcon();
public slots:
    void openMainWindow();
private:
    QAction *openAction_;
    QAction *quitAction_;
    QMainWindow *mainWindow_;
    QMenu *trayIconMenu_;

    QIcon icon_;
};

#endif // TRAYICON_H
