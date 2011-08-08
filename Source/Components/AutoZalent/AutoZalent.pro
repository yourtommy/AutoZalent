#-------------------------------------------------
#
# Project created by QtCreator 2011-07-09T10:17:27
#
#-------------------------------------------------

QT       += core gui xml

TARGET = AutoZalent
TEMPLATE = app

ROOTDIR = ../../../
COMMONPRI = $$join(ROOTDIR,,,Source/Common/Pri/Common.pri)
exists($$COMMONPRI) {
    !include($$COMMONPRI) : error("include pri falied")
} else {
    error ($$COMMONPRI)
}

CONFIG += precompile_header
PRECOMPILED_HEADER = pch.h

precompile_header : !isEmpty($$PRECOMPILED_HEADER) {
    DEFINES += USEING_PCH
}

SOURCES += main.cpp\
        autozalent.cpp \
    addin.cpp \
    addinmanager.cpp \
    addinxmler.cpp \
    exception.cpp

HEADERS  += autozalent.h \
    pch.h \
    addin.h \
    addinmanager.h \
    addinxmler.h \
    exception.h

FORMS    += autozalent.ui
