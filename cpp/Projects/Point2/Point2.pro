TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    point.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    point.h

