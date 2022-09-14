QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        SerialPort.cpp \
        main.cpp \
        serial.cpp \
        win.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    SerialPort.h \
    common.h \
    serial.h \
    v8stdint.h \
    win.h

LIBS += C:\Qt\Tools\mingw1120_64\x86_64-w64-mingw32\lib\libws2_32.a
