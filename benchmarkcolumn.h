#ifndef BENCHMARKCOLUMN_H
#define BENCHMARKCOLUMN_H

#include <QObject>
#include <QTime>
#include <QElapsedTimer>
#include <QList>
#include <QVector>

class BenchmarkColumn : public QObject
{
    Q_OBJECT
public:
    explicit BenchmarkColumn(QObject *parent = 0);
    BenchmarkColumn(QString, QString, QString, QString);
    BenchmarkColumn(QString);
    static void setName(QString cName);
    static void setXName(QString xName);
    static void setUnitName(QString uName);
    static void setLimit(quint16);
    static QString getName();
    static QString getXName();
    static QString getUnitName();
    static quint16 getLimit();

    quint64 getXValue(quint16);
    QString getTestName();
    void setTestName(QString);
    void start();
    virtual void test();

private:
    static QString s_cName;
    static QString s_XName;
    static QString s_UName;
    static quint16 i_limit;
    QVector <quint64> i_ValueX;
    quint16 i_counter;
    QString s_TName;

signals:

public slots:

};

#endif // BENCHMARKCOLUMN_H
