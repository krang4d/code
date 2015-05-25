TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Point.cpp \
    Pixel.cpp \
    UsePixel.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Point.h \
    Pixel.h

