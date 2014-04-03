#ifndef TESTOBJECT2_H
#define TESTOBJECT2_H

#include <QObject>
#include "benchmarkcolumn.h"


class TestObject2 : public BenchmarkColumn
{
    Q_OBJECT
public:
    explicit TestObject2(QObject *parent = 0);
    void test();

signals:

public slots:


};

#endif // TESTOBJECT2_H
