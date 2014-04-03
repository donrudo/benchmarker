#include "testobject2.h"
#include <vector>

TestObject2::TestObject2(QObject *parent) :
    BenchmarkColumn(parent)
{
}

void TestObject2::test(){
    int i = 0;
    std::vector<int> Vector= std::vector<int>(10024);
    for(i = 0; i < 10024; i++){
           Vector[i] =i;
    }
}
