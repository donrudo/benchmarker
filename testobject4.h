#ifndef TESTOBJECT4_H
#define TESTOBJECT4_H
#include <QObject>
#include "benchmarkcolumn.h"

class TestObject4 : public BenchmarkColumn
{
    Q_OBJECT
public:
    explicit TestObject4(QObject *parent = 0);
    void test();

signals:

public slots:

};

#endif // TESTOBJECT4_H
