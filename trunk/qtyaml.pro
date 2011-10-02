#-------------------------------------------------
#
# Project created by QtCreator 2011-10-02T15:48:07
#
#-------------------------------------------------

QT       -= gui

TARGET = qtyaml
TEMPLATE = lib

DEFINES += QTYAML_LIBRARY

SOURCES += QtYaml.cpp

HEADERS += QtYaml.hpp\
        qtyaml_global.hpp

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE4F154B2
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = qtyaml.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
