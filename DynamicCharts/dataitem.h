#ifndef DATAITEM_H
#define DATAITEM_H

#include <QObject>

class DataItem : public QObject
{
    Q_OBJECT
    float m_x;
    float m_y;
public:
    explicit DataItem(QObject *parent = nullptr);
    DataItem(float x, float y){
        m_x = x;
        m_y = y;
    }

    Q_PROPERTY(float x MEMBER m_x NOTIFY xValueChanged)
    Q_PROPERTY(float y MEMBER m_y NOTIFY yValueChanged)

signals:
    void xValueChanged();
    void yValueChanged();

public slots:
};

#endif // DATAITEM_H
