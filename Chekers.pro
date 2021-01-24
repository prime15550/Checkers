QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Chekers
TEMPLATE = app



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    box.cpp \
    button.cpp \
    file.cpp \
    game.cpp \
    help.cpp \
    king.cpp \
    main.cpp \
    piece.cpp \
    popup.cpp \
    stamp.cpp

HEADERS += \
    board.h \
    box.h \
    button.h \
    file.h \
    game.h \
    help.h \
    king.h \
    piece.h \
    popup.h \
    stamp.h

FORMS += \
    file.ui \
    help.ui \
    popup.ui


RESOURCES += \
    resource.qrc



