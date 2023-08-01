SOURCES += \
        backend.cpp \
        diffraction.cpp \
        main.cpp \
        mainwindow.cpp \
        mydoublespinbox.cpp \
        mygraphicsview.cpp \
        opencl.cpp \
        qwcomboboxdelegate.cpp \
        qwdoublespindelegate.cpp


QMAKE_CXXFLAGS += /openmp /arch:AVX2 /Ox /fp:fast


HEADERS += \
    backend.h \
    createimage.h \
    diffraction.h \
    mainwindow.h \
    mydoublespinbox.h \
    mygraphicsview.h \
    opencl.h \
    qwcomboboxdelegate.h \
    qwdoublespindelegate.h

QT += core gui widgets quickwidgets

DISTFILES +=

win32: LIBS += -LE:/Programming/opencl/lib/ -lOpenCL

INCLUDEPATH += E:/Programming/opencl/include
DEPENDPATH += E:/Programming/opencl/include

win32:!win32-g++: PRE_TARGETDEPS += E:/Programming/opencl/lib/OpenCL.lib
else:win32-g++: PRE_TARGETDEPS += E:/Programming/opencl/lib/libOpenCL.a

FORMS += \
    mainwindow.ui

RESOURCES += \
    res.qrc
