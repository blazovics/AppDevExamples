#ifndef BURSTDATASOURCE_H
#define BURSTDATASOURCE_H

#include <QObject>

#include <QVariant>

class BurstDataSource : public QObject
{
    Q_OBJECT

    QList<QObject*> m_dataItems;

    QList<QObject*> m_savedDataItems;

public:
    explicit BurstDataSource(QObject *parent = nullptr);

    Q_PROPERTY(QList<QObject*> dataItems MEMBER m_dataItems NOTIFY dataItemsChanged)

    void generateData();

    void saveData();
    void loadData();

signals:
    void dataItemsChanged();
    void dataReady();

public slots:

};

#endif // BURSTDATASOURCE_H
