TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    useUsart.cpp \
    Usart.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Usart.h

