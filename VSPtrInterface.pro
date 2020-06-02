#-------------------------------------------------
#
# Project created by QtCreator 2020-05-30T01:21:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VSPtrInterface
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    client.cpp \
    dialog.cpp \
    jsoncpp.cpp \
    heap.cpp \
    ../VSCODE/VSPtr.cpp \
    ../VSCODE/Node.cpp \
    ../VSCODE/List.cpp \
    ../VSCODE/GarbageCollector.cpp

HEADERS += \
        mainwindow.h \
    client.h \
    dialog.h \
    json-forwards.h \
    json.h \
    heap.h \
    ../VSCODE/VSPtr.h \
    ../VSCODE/Node.h \
    ../VSCODE/List.h \
    ../VSCODE/GarbageCollector.h

FORMS += \
        mainwindow.ui \
    dialog.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src/release/ -lhl++
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src/debug/ -lhl++
else:unix: LIBS += -L$$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src/ -lhl++

INCLUDEPATH += $$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src
DEPENDPATH += $$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src/release/libhl++.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src/debug/libhl++.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src/release/hl++.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src/debug/hl++.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../Downloads/hashlibpp_0_3_4/hashlib2plus/trunk/src/libhl++.a



QT += sql
