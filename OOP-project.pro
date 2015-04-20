TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/dict.cpp \
    src/main.cpp \
    src/wordlist.cpp \
    src/wordstatus.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    include/dict.h \
    include/wordlist.h \
    include/wordstatus.h

INCLUDEPATH += include
