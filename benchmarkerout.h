#ifndef BENCHMARKEROUT_H
#define BENCHMARKEROUT_H

#include "benchmarkcolumn.h"
#include <QObject>
#include <QResource>
#include <QString>
#include <QTextStream>
#include <QIODevice>
#include <QFile>
#include <QList>
#include <QDebug>
#include <QtNumeric>

class BenchmarkerOut : public QObject
{
    Q_OBJECT
public:
    explicit BenchmarkerOut(QObject *parent = 0);
    ~BenchmarkerOut();
    void run();
    void appendColumn(BenchmarkColumn & );
    void appendColumn(QList <BenchmarkColumn *>);
    void save();
    QString getJSOutput();

private:
    QString s_head, s_foot, s_results;
    QList<BenchmarkColumn *> l_columns;

signals:

public slots:
};

#endif // BENCHMARKEROUT_H
