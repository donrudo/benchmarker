#include "benchmarkerout.h"
#include "testobject.h"
#include "testobject2.h"
#include <iostream>

/**
 * @brief BenchmarkerOut::BenchmarkerOut
 * @param parent
 *
 * reads the template files from the QRC to be used to generate the JS output
 *
 */
BenchmarkerOut::BenchmarkerOut(QObject *parent) :
    QObject(parent)
{
   // QResource::registerResource("templates.qrc");

    // Loads Header template.
    QFile mF_head(":/js/Head.js");
    mF_head.open(QFile::ReadOnly);
    QTextStream inh(&mF_head);
    s_head = inh.readAll();
    inh.reset();
    mF_head.close();

    QFile mF_foot(":/js/Foot.js");
    mF_foot.open(QFile::ReadOnly);
    QTextStream inf(&mF_foot);
    s_foot = inf.readAll();
    inf.reset();
    mF_foot.close();

    s_results = "[";
}

BenchmarkerOut::~BenchmarkerOut(){
    qDeleteAll(this->l_columns);
}

/**
 * @brief BenchmarkerOut::save
 * Saves the results to the default path
 * @TODO add the chance to customize the output path
 */
void BenchmarkerOut::save()
{
    QFile mF_out("html/benchmarkout.js");
    mF_out.open(QFile::WriteOnly | QFile::Truncate);
    QTextStream out(&mF_out);
    out << s_head << s_results << s_foot;
    out.reset();
    mF_out.close();
}

/**
 * @brief BenchmarkerOut::run
 * Executes all the tests and gets the current results from each given column
 * @TODO May Need optimization.
 */
void BenchmarkerOut::run()
{
    int i = 0;
    int y = 0;

    if(l_columns.size() == 0) {
        return;
    }

    s_results += "[ \"" + l_columns.at(0)->getUnitName() + "\"";
    for(i = 0; i < l_columns.size(); i++){

        l_columns.at(i)->start();
        s_results +=",\"" + l_columns.at(i)->getTestName() + "\"";

    }

    s_results += "]";
    for( y = 0; y < l_columns.at(0)->getLimit(); y++){
        QString value;
        for( i = 0; i < l_columns.size(); i++){

            if(i == 0) {
                s_results += QString(",\n[") ;
                s_results += QString("\"") + value.setNum(y) + "\",";
            }

            s_results += value.setNum(l_columns.at(i)->getXValue(y));

            if(i < (l_columns.size()-1) ) {
                s_results += QString(",");
            } else {
                s_results += QString("]");
            }

        }

    }
    s_results += QString("]");

}

void BenchmarkerOut::appendColumn(BenchmarkColumn &column)
{
    l_columns.append(&column);
}

void BenchmarkerOut::appendColumn(QList <BenchmarkColumn *> columnGroup)
{
    l_columns.append(columnGroup) ;
}

