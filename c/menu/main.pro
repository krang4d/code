TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    menu.c \
    data.c \
    do_it.c \
    in_out.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    menu.h \
    data.h \
    do_it.h \
    in_out.h

DISTFILES +=

