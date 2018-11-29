#ifndef SINSOURCE_H
#define SINSOURCE_H

#include <QObject>

#include <QTimer>

#include <QVariant>

class SinSource : public QObject
{
    Q_OBJECT

    QTimer* ticker;
    //this will be 'x' coordinate
    float timeStamp;

public:
    explicit SinSource(QObject *parent = nullptr);

signals:
    void newSinData(QVariant x, QVariant y);

public slots:
    void handleTimer();
};

#endif // SINSOURCE_H
