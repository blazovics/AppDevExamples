#ifndef DATADOWNLOADER_H
#define DATADOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "message.h"
#include "messagemodell.h"

class DataDownloader : public QObject
{
    Q_OBJECT
    QNetworkAccessManager* manager;

    MessageModell model;

public:
    explicit DataDownloader(QObject *parent = nullptr);

    MessageModell *getModel();

signals:

public slots:
    void downloadJSON(QString url);

    void managerGetFinished(QNetworkReply* reply);

private:
    //Helper function for decoding JSON data
    void decodeJSON(QByteArray rawData);

};

#endif // DATADOWNLOADER_H
