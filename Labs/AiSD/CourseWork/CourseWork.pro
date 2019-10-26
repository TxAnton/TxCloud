#-------------------------------------------------
#
# Project created by QtCreator 2019-03-25T12:31:31
#
#-------------------------------------------------

QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseWork
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    create_dialog.cpp \
    info_dialog.cpp \
    line_dialog.cpp \
        main.cpp \
        mainwindow.cpp \
    qbmptools.cpp \
    rot_dialog.cpp \
    triangle_dialog.cpp \
    graph_window.cpp \
    drawgraphicsview.cpp \
    graphgraphicview.cpp \
    listviewactionlogger.cpp

HEADERS += \
    BMPTools.h \
    create_dialog.h \
    info_dialog.h \
    line_dialog.h \
        mainwindow.h \
    qbmptools.h \
    rot_dialog.h \
    triangle_dialog.h \
    graph_window.h \
    drawgraphicsview.h \
    graphgraphicview.h \
    AVLTreeClass.h \
    listviewactionlogger.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
