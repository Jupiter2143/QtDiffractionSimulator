SOURCES += \
        backend.cpp \
        dialog.cpp \
        diffraction.cpp \
        main.cpp \
        mainwindow.cpp \
        mydoublespinbox.cpp \
        mygraphicsview.cpp \
        myopenglwidget.cpp \
        opencl.cpp \
        qwcomboboxdelegate.cpp \
        qwdoublespindelegate.cpp


QMAKE_CXXFLAGS += /openmp /arch:AVX2 /Ox /fp:fast

HEADERS += \
    backend.h \
    createimage.h \
    dialog.h \
    diffraction.h \
    mainwindow.h \
    mydoublespinbox.h \
    mygraphicsview.h \
    myopenglwidget.h \
    opencl.h \
    qwcomboboxdelegate.h \
    qwdoublespindelegate.h

QT += core gui widgets openglwidgets

DISTFILES += \
    kernel.cl

win32: LIBS += -LE:/Programming/opencl/lib/ -lOpenCL -lOpenGL32 -lGlU32

INCLUDEPATH += E:/Programming/opencl/include
DEPENDPATH += E:/Programming/opencl/include

win32:!win32-g++: PRE_TARGETDEPS += E:/Programming/opencl/lib/OpenCL.lib
else:win32-g++: PRE_TARGETDEPS += E:/Programming/opencl/lib/libOpenCL.a

FORMS += \
    dialog.ui \
    mainwindow.ui
