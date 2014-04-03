#include "testobject.h"
#include <QList>

TestObject::TestObject(QObject *parent) :
    BenchmarkColumn(parent)
{
}

void TestObject::test(){
        int i = 0;
        QList<int> vector= QList<int>();
        for(i = 0; i < 10024; i++){
               vector.append(i);
        }
}
