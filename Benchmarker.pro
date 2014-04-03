greaterThan(QT_MAJOR_VERSION, 4):QT += widgets webkitwidgets

# Add more folders to ship with the application, here
folder_01.source = html
folder_01.target = .
DEPLOYMENTFOLDERS = folder_01

# Define TOUCH_OPTIMIZED_NAVIGATION for touch optimization and flicking
DEFINES += TOUCH_OPTIMIZED_NAVIGATION

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    benchmarkerout.cpp \
    benchmarkcolumn.cpp \
    testobject.cpp \
    testobject2.cpp \
    testobject3.cpp \
    testobject4.cpp

# Please do not modify the following two lines. Required for deployment.
include(html5applicationviewer/html5applicationviewer.pri)
qtcAddDeployment()

RESOURCES += \
    templates.qrc

HEADERS += \
    benchmarkerout.h \
    benchmarkcolumn.h \
    testobject.h \
    testobject2.h \
    testobject3.h \
    testobject4.h
