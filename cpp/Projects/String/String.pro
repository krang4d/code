TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    String.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    String.h

