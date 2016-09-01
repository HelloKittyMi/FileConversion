#-------------------------------------------------
#
# Project created by QtCreator 2016-04-14T15:07:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileConversion
#TARGET = pdbToPd2
TEMPLATE = app

#TEMPLATE = lib CONFIG += staticlib
#TEMPLATE = lib

SOURCES +=\
    main.cpp\
    mainwindow.cpp \
    FileHandle.cpp \
    Logger.cpp \
    Conversion.cpp

HEADERS  +=\
    mainwindow.h \
    FileHandle.h \
    Logger.h \
    Conversion.h

FORMS    += mainwindow.ui

#QMAKE_CXXFLAGS += -g -Wno-psabi -Wno-write-strings -Wno-unused-parameter -Wno-unused-local-typedefs  -Wall -Werror  -O2 -fomit-frame-pointer -fno-strict-aliasing
QMAKE_CXXFLAGS += -g -Wno-unused-parameter -Wno-narrowing
