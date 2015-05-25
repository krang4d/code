TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    usec.c

include(deployment.pri)
qtcAddDeployment()

SUBDIRS += \
    ../CppProjects/StringCpp/String.pro

