#include "testobject4.h"
#include <list>

TestObject4::TestObject4(QObject *parent) :
    BenchmarkColumn(parent)
{
}

void TestObject4::test(){
    int i = 0;
    std::list<int> Vector= std::list<int>(10024);
    for(i = 0; i < 10024; i++){
           Vector.push_back(i);
    }
}
