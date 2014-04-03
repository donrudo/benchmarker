#include "benchmarkcolumn.h"

 QString BenchmarkColumn::s_cName="";
 QString BenchmarkColumn::s_XName="";
 QString BenchmarkColumn::s_UName="";
 quint16 BenchmarkColumn::i_limit=50;


BenchmarkColumn::BenchmarkColumn(QObject *parent) :
    QObject(parent)
{

   setName("");
   setXName("");
   this->setTestName("");
   setUnitName("");
   i_ValueX = QVector <quint64>(i_limit);

   for(int i; i < getLimit(); i++){
       i_ValueX[i] = 0;
   }
}

BenchmarkColumn::BenchmarkColumn(QString name, QString xname, QString testname, QString unitname) :
QObject(0)
{
   setName(name);
   setXName(xname);
   this->setTestName(testname);
   setUnitName(unitname);
   i_ValueX = QVector <quint64>(i_limit);
   for(int i; i < getLimit(); i++){
       i_ValueX[i] = 0;
   }
}

/**
 * @brief BenchmarkColumn::BenchmarkColumn
 * @param testname sets the name of the test to be run
 */
BenchmarkColumn::BenchmarkColumn(QString testname) :
QObject(0)
{
   this->setTestName(testname);
   i_ValueX = QVector <quint64>(i_limit);
}

/**
 * @brief BenchmarkColumn::start
 * @description executes the test methods and gets the time it takes to finish each test.
 *
 */
void BenchmarkColumn::start(){
    i_ValueX = QVector<quint64>(i_limit);
    this->i_counter = 0;
    for (int i =0; i < BenchmarkColumn::getLimit(); i++){
        QElapsedTimer myTimer;
        myTimer.start();
        this->test();
        this->i_ValueX[i_counter] = myTimer.nsecsElapsed();
        this->i_counter++;
    }
}

/**
 * @brief BenchmarkColumn::getXValue
 * @param pos
 * @return the nanoseconds result from a given ran point.
 */
quint64 BenchmarkColumn::getXValue(quint16 pos){
    int returnval = 0;
    if(pos > 0 && pos < getLimit()){
            returnval = this->i_ValueX[pos];
    }
    return returnval;
}

/**
 * @brief BenchmarkColumn::getTestName
 * @return the name given to the current test
 */
QString BenchmarkColumn::getTestName(){
    return this->s_TName;
}

/**
 * @brief BenchmarkColumn::setTestName
 * @param tname the test name to identify the current execution.
 */
void BenchmarkColumn::setTestName(QString tname){
    this->s_TName = tname;
}

/**
 * @brief BenchmarkColumn::test
 * Virtual function to be overriden by each executed test.
 */
void BenchmarkColumn::test(){

}

/*
 * Static Setters and getters
 */
quint16 BenchmarkColumn::getLimit(){
    return i_limit;
}

void BenchmarkColumn::setLimit(quint16 limit)
{
    i_limit = limit;
}

void BenchmarkColumn::setName(QString cName){
    s_cName = cName;
}

QString BenchmarkColumn::getName() {
    return s_cName;
}

void BenchmarkColumn::setXName(QString xName){
    s_XName = xName;
}

QString BenchmarkColumn::getXName() {
    return s_XName;
}

/*
 * getUnitName
 * Returns the Unit Name for the run benchmark
 */
QString BenchmarkColumn::getUnitName() {
    return s_UName;
}

void BenchmarkColumn::setUnitName(QString uName){
    s_UName = uName;
}
