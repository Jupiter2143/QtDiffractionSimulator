SOURCES += \
        backend.cpp \
        dialog.cpp \
        diffraction.cpp \
        main.cpp \
        mainwindow.cpp \
        mydelegate.cpp \
        mydoublespinbox.cpp \
        mygraphicsview.cpp \
        opencl.cpp \
        viewwindow.cpp

QMAKE_CXXFLAGS += /openmp /arch:AVX2 /Ox /fp:fast

HEADERS += \
    backend.h \
    dialog.h \
    diffraction.h \
    mainwindow.h \
    mydelegate.h \
    mydoublespinbox.h \
    mygraphicsview.h \
    opencl.h \
    viewwindow.h


QT += core gui widgets
QT+=quick quickwidgets

DISTFILES +=

win32: LIBS += -LE:/Programming/opencl/lib/ -lOpenCL

INCLUDEPATH += E:/Programming/opencl/include
DEPENDPATH += E:/Programming/opencl/include

win32:!win32-g++: PRE_TARGETDEPS += E:/Programming/opencl/lib/OpenCL.lib
else:win32-g++: PRE_TARGETDEPS += E:/Programming/opencl/lib/libOpenCL.a

FORMS += \
    dialog.ui \
    mainwindow.ui \
    viewwindow.ui

RESOURCES += \
    res.qrc

#resources.files += Mymodel.qml
