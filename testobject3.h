#ifndef TESTOBJECT3_H
#define TESTOBJECT3_H
#include <QObject>
#include "benchmarkcolumn.h"

class TestObject3 : public BenchmarkColumn
{
    Q_OBJECT
public:
    explicit TestObject3(QObject *parent = 0);

    void test();
signals:

public slots:

};

#endif // TESTOBJECT3_H
