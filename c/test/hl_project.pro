TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += usehl.c

include(deployment.pri)
qtcAddDeployment()

