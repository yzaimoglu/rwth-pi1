QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractmap.cpp \
    addcitydialog.cpp \
    addstreetdialog.cpp \
    bigcity.cpp \
    city.cpp \
    dijkstra.cpp \
    dijkstradialog.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mapio.cpp \
    mapiofileinput.cpp \
    mapionrw.cpp \
    motorway.cpp \
    smallcity.cpp \
    stateroad.cpp \
    street.cpp

HEADERS += \
    abstractmap.h \
    addcitydialog.h \
    addstreetdialog.h \
    bigcity.h \
    city.h \
    dijkstra.h \
    dijkstradialog.h \
    mainwindow.h \
    map.h \
    mapio.h \
    mapiofileinput.h \
    mapionrw.h \
    motorway.h \
    smallcity.h \
    stateroad.h \
    street.h

FORMS += \
    addcitydialog.ui \
    addstreetdialog.ui \
    dijkstradialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
