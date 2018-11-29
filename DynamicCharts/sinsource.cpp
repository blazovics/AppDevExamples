#include "sinsource.h"
#include <math.h>

SinSource::SinSource(QObject *parent) : QObject(parent)
{
    timeStamp = 0.0f;
    ticker = new QTimer();

    connect(ticker, SIGNAL(timeout()),this,SLOT(handleTimer()));

    ticker->start(30);
}

void SinSource::handleTimer()
{
    timeStamp += 0.03;

    float x = timeStamp;
    float y = sin(timeStamp);

    emit newSinData(QVariant(x), QVariant(y));
}
