TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../../class/account.cpp \
    ../../class/extraaccount.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../class/account.h \
    ../../class/extraaccount.h

