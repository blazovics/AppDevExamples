#include "burstdatasource.h"
#include "dataitem.h"
#include "math.h"

#include <QFile>
#include <QDataStream>

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

void BurstDataSource::saveData()
{
    QFile file("burstData.dat");

    file.open(QIODevice::ReadWrite);

    QDataStream writeStream(&file);

    for(int t = 0; t< 100; t++)
    {
        DataItem* newData = new DataItem(float(t),cos(float(t)));
        newData->Serialize(writeStream);
    }

    file.close();
}

void BurstDataSource::loadData()
{
    QFile file("burstData.dat");

    file.open(QIODevice::ReadOnly);

    QDataStream readStream(&file);

    for(int t = 0; t< 100; t++)
    {
        DataItem* newData = new DataItem(0.0,0.0);
        newData->DeSerialize(readStream);

        m_dataItems.append(newData);
    }

    file.close();
    emit dataReady();
}
