TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    UsePixel.cpp \
    Pixel.cpp \
    Point.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Pixel.h \
    Point.h

