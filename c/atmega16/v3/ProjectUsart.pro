TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Usart.cpp \
    useUsart.cpp \
    commands.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Usart.h \
    commands.h

