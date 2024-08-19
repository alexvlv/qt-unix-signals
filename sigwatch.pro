TEMPLATE = app
QT       = core

TARGET   = sigwatch-demo

SOURCES += example.cpp \

unix {
    SOURCES += sigwatch.cpp \
               sigreceiver.cpp \
}

unix {
    HEADERS += sigwatch.h \
               sigreceiver.h \
}
