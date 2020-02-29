#include "mainwindow.h"
#include <QApplication>

#include "audiorecorder.h"
#include "trayicon.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(resources);

    QApplication a(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false);
    // QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    TrayIcon* trayIcon = new TrayIcon;
    trayIcon->show();

    // MainWindow w;
    // w.show();

    AudioRecorder* recorder = new AudioRecorder;
    // recorder->start();

    // AudioRecorder recorder = AudioRecorder();
    // recorder.start();

    list_devices();

    return a.exec();
}
