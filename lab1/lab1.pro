QT       += core gui
QT += sql
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_employee_dialog.cpp \
    database_manager.cpp \
    delete_confirmation_dialog.cpp \
    employees.cpp \
    main.cpp \
    mainwindow.cpp \
    tickets.cpp

HEADERS += \
    add_employee_dialog.h \
    database_manager.h \
    delete_confirmation_dialog.h \
    employees.h \
    mainwindow.h \
    tickets.h

FORMS += \
    add_employee_dialog.ui \
    delete_confirmation_dialog.ui \
    employees.ui \
    mainwindow.ui \
    tickets.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
