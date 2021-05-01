QT       += core gui serialport uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 qscintilla2


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include

SOURCES += \
    src/controller.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/port/portmanager.cpp \
    src/port/serialport.cpp \
    src/toolbox/toolboxmanager.cpp \
    src/views/texttr/textedit.cpp \
    src/views/texttr/texttrview.cpp \
    src/views/viewmanager.cpp \
    src/portsetbox.cpp

HEADERS += \
    include/controller.h \
    include/mainwindow.h \
    include/version.h \
    include/portsetbox.h \
    src/port/abstractport.h \
    src/port/portmanager.h \
    src/port/serialport.h \ \
    src/toolbox/abstracttoolbox.h \
    src/toolbox/toolboxmanager.h \
    src/views/abstractview.h \
    src/views/texttr/textedit.h \
    src/views/texttr/texttrview.h \
    src/views/viewmanager.h

FORMS += \
    ui/mainwindow.ui \
    ui/serialport.ui \
    ui/portsetbox.ui \
    ui/texttrview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource/serialtool.qrc
