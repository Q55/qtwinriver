#-------------------------------------------------
#
# Project created by QtCreator 2016-05-15T22:18:16
#
#-------------------------------------------------
include (/usr/local/qwt-6.1.2/features/qwt.prf)
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtwinriver
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scatterplot.cpp \
    plot.cpp \
    rawdatafromdb.cpp \
    tgraphdatamodel.cpp

HEADERS  += mainwindow.h \
    scatterplot.h \
    plot.h \
    rawdatafromdb.h \
    tgraphdatamodel.h

FORMS    += mainwindow.ui
