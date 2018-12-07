#include "dataitem.h"

DataItem::DataItem(QObject *parent) : QObject(parent)
{

}

void DataItem::Serialize(QDataStream &outStream)
{
    outStream << m_x;
    outStream << m_y;
}

void DataItem::DeSerialize(QDataStream &inStream)
{
    inStream >> m_x;
    inStream >> m_y;
}
