QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include/
VPATH += src/
SOURCES += \
    main.cpp \
    src/mythread.cpp \
    src/plotnetworkdata.cpp \
    src/qcustomplot.cpp

HEADERS += \
    include/mythread.h \
    include/plotnetworkdata.h \
    include/qcustomplot.h

FORMS += \
    ui/plotnetworkdata.ui

#MOC_DIR     = ./build/moc
#OBJECTS_DIR = ./build/obj
#RCC_DIR     = ./build/qrc
#UI_DIR      = ./build/uic

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
