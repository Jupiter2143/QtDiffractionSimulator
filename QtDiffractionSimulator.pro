SOURCES += \
        kernelDir/backend.cpp \
        windowDir/dialog.cpp \
        kernelDir/diffraction.cpp \
        main.cpp \
        mainwindow.cpp \
        classDir/mydelegate.cpp \
        classDir/mydoublespinbox.cpp \
        classDir/mygraphicsview.cpp \
        KernelDir/opencl.cpp \
        windowDir/rasterwindow.cpp \
        windowDir/viewwindow.cpp

QMAKE_CXXFLAGS += /openmp /Ox

HEADERS += \
    kernelDir/backend.h \
    windowDir/dialog.h \
    kernelDir/diffraction.h \
    mainwindow.h \
    classDir/mydelegate.h \
    classDir/mydoublespinbox.h \
    classDir/mygraphicsview.h \
    kernelDir/opencl.h \
    windowDir/rasterwindow.h \
    windowDir/viewwindow.h

QT += core gui widgets
QT += quick quickwidgets


FORMS += \
    windowDir/dialog.ui \
    mainwindow.ui \
    windowDir/rasterwindow.ui \
    windowDir/viewwindow.ui

RESOURCES += \
    res.qrc

resources.files += \
        sourceDir/CustomSlider.qml      \
        sourceDir/3D.qml  #以添加多个文件或者文件夹

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/opencl/lib/ -lOpenCL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/opencl/lib/ -lOpenCL

INCLUDEPATH += $$PWD/lib/opencl/include
DEPENDPATH += $$PWD/lib/opencl/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/opencl/lib/libOpenCL.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/opencl/lib/libOpenCL.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/opencl/lib/OpenCL.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/opencl/lib/OpenCL.lib
