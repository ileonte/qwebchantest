#-------------------------------------------------
#
# Project created by QtCreator 2015-09-09T21:37:08
#
#-------------------------------------------------

QT += core gui widgets webenginewidgets webchannel

linux-g++ {
        QMAKE_CXXFLAGS += -std=c++11
}

TARGET = qwebchantest
TEMPLATE = app

SOURCES += main.cc\
        widget.cc

HEADERS  += widget.h

DISTFILES +=

RESOURCES += \
    res.qrc
