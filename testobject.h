#ifndef TESTOBJECT_H
#define TESTOBJECT_H
#include <QObject>
#include "benchmarkcolumn.h"

class TestObject : public BenchmarkColumn
{
    Q_OBJECT
public:
    explicit TestObject(QObject *parent = 0);
    void test();

signals:

public slots:

};

#endif // TESTOBJECT_H
