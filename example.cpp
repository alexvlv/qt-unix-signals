#include <QCoreApplication>
#include <QDebug>
#include "sigwatch.h"
#include "sigreceiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    qDebug() << "Hello from process" << QCoreApplication::applicationPid();

    UnixSignalWatcher sigwatch;
    //sigwatch.watchForSignal(SIGINT);
    //sigwatch.watchForSignal(SIGTERM);
    //QObject::connect(&sigwatch, SIGNAL(unixSignal(int)), &app, SLOT(quit()));

    sigwatch.watchForSignal(SIGHUP);
	SignalReseiver rx;
	
    QObject::connect(&sigwatch, SIGNAL(unixSignal(int)), &rx, SLOT(onSignal(int)));

    int exitcode = app.exec();
    qDebug() << "Goodbye";
    return exitcode;
}

