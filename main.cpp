#include <QApplication>
#include "html5applicationviewer.h"

#include "testobject.h"
#include "testobject2.h"
#include "testobject3.h"
#include "testobject4.h"

#include "benchmarkerout.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Html5ApplicationViewer viewer;
    BenchmarkerOut bench;

    TestObject try1;
    TestObject2 try2;
    TestObject3 try3;
    TestObject4 try4;

    try1.setName("Vector vs QList");
    try1.setLimit(1024);
    try1.setUnitName("Nanoseconds");
    try1.setTestName("QList int");
    try2.setTestName("STD Vector int");
    try3.setTestName("QVector int");
    try4.setTestName("STD List int");

    bench.appendColumn((BenchmarkColumn &)try1);
    bench.appendColumn((BenchmarkColumn &)try2);
    bench.appendColumn((BenchmarkColumn &)try3);
    bench.appendColumn((BenchmarkColumn &)try4);

    bench.run();
    bench.save();

    viewer.setOrientation(Html5ApplicationViewer::ScreenOrientationAuto);
    viewer.showExpanded();
    viewer.loadFile(QLatin1String("html/index.html"));

    return app.exec();
}
