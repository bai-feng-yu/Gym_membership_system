QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT+=sql
TARGET =MembershipSystem
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    controler.cpp \
    customer.cpp \
    help.cpp \
    information.cpp \
    main.cpp \
    dialog.cpp

HEADERS += \
    connection.h \
    controler.h \
    customer.h \
    dialog.h \
    help.h \
    information.h

FORMS += \
    controler.ui \
    dialog.ui \
    help.ui \
    information.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
