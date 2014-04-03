#include "testobject3.h"
#include <QVector>

TestObject3::TestObject3(QObject *parent) :
    BenchmarkColumn(parent)
{
}

void TestObject3::test(){
    int i = 0;
    QVector<int> Vector= QVector<int>(10024);
    for(i = 0; i < 10024; i++){
           Vector.append(i);
    }
}

