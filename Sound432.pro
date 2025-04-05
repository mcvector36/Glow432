QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG+= static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    floatingbutton.cpp \
    main.cpp \
    sound432.cpp

HEADERS += \
    floatingbutton.h \
    sound432.h

FORMS += \
    sound432.ui

RESOURCES += resources.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    sound432-off.png \
    sound432-on.png
