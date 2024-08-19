#include <QCoreApplication>
#include <QDebug>
#include "sigwatch.h"
#include "sigreceiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    qDebug() << "Hello from process" << QCoreApplication::applicationPid();

#if defined (Q_OS_LINUX)
    UnixSignalWatcher& sigwatch = UnixSignalWatcher::instance();
    //sigwatch.watchForSignal(SIGINT);
    //sigwatch.watchForSignal(SIGTERM);
    //QObject::connect(&sigwatch, SIGNAL(unixSignal(int)), &app, SLOT(quit()));

    // pkill -SIGHUP sigwatch-demo
    sigwatch.watchForSignal(SIGHUP);

    // pkill -SIGUSR1 sigwatch-demo
    sigwatch.watchForSignal(SIGUSR1);
	SignalReseiver rx;
	
    QObject::connect(&sigwatch, SIGNAL(unixSignal(int)), &rx, SLOT(onSignal(int)));
#endif
    int exitcode = app.exec();
    qDebug() << "Goodbye";
    return exitcode;
}

