QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bitmap.cpp \
    BlueSaturationChannel.cpp \
    BlueSelectionChannel.cpp \
    DecreaseBrightness.cpp \
    FileHeader.cpp \
    Filter.cpp \
    GrayScale.cpp \
    GreenSaturationChannel.cpp \
    GreenSelectionChannel.cpp \
    HorizontalMirror.cpp \
    Image.cpp \
    IncreaseBrightness.cpp \
    InfoHeader.cpp \
    Negative.cpp \
    Pixel.cpp \
    RedSaturationChannel.cpp \
    RedSelectionChannel.cpp \
    Rotation.cpp \
    Sepia.cpp \
    Sharpness.cpp \
    Smoothing.cpp \
    Threshold.cpp \
    VerticalMirror.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Bitmap.h \
    BlueSaturationChannel.h \
    BlueSelectionChannel.h \
    DecreaseBrightness.h \
    FileHeader.h \
    Filter.h \
    GrayScale.h \
    GreenSaturationChannel.h \
    GreenSelectionChannel.h \
    HorizontalMirror.h \
    Image.h \
    IncreaseBrightness.h \
    InfoHeader.h \
    Negative.h \
    Pixel.h \
    RedSaturationChannel.h \
    RedSelectionChannel.h \
    Rotation.h \
    Sepia.h \
    Sharpness.h \
    Smoothing.h \
    Threshold.h \
    VerticalMirror.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    projeto_ATC_pt_PT.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Resources.qrc
