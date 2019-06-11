#ifndef BACKEND_CHARTSDATA_H
#define BACKEND_CHARTSDATA_H
#include "Backend_ChartsData.h"
#include <QObject>
#include <QVector>

class BackendChartsData : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE QVector<double> getChartData();
    BackendChartsData();
};

#endif // BACKEND_CHARTSDATA_H
