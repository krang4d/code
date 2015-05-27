TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    ../5/search.c \
    ../3/HW-5-6/HW-5-6/rec.c \
    ../3/HW-5-6/HW-5-6/search.c \
    ../2/start_to_flags.c \
    ../2/SumOfDigits/SumOfDigits/SumOfDigits.c \
    ../2/Ops/Ops/Ops.c

include(deployment.pri)
qtcAddDeployment()

