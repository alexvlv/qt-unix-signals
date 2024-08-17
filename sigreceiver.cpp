#include "sigreceiver.h"

SignalReseiver::SignalReseiver(QObject *parent) :
    QObject(parent)
{
}

SignalReseiver::~SignalReseiver() {}

void SignalReseiver::onSignal(int i) {
	qDebug() << "Received signal:" << i;
}
