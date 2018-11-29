#include "burstdatasource.h"
#include "dataitem.h"
#include "math.h"

BurstDataSource::BurstDataSource(QObject *parent) : QObject(parent)
{

}

void BurstDataSource::generateData()
{
    for(int t = 0; t< 100; t++)
    {
        DataItem* newData = new DataItem(float(t),cos(float(t)));

        m_dataItems.append(newData);
    }

    emit dataReady();
}
