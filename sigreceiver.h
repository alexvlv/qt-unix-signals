#pragma once

#include <QDebug>

class SignalReseiver : public QObject
{
    Q_OBJECT
public:
	    explicit SignalReseiver(QObject *parent = 0);
		~SignalReseiver();
public slots:
	void onSignal(int i);
};
