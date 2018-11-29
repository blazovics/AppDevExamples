#include "datadownloader.h"
#include <QDebug>
#include <QNetworkReply>

#include <QJsonArray>
#include <QJsonObject>

#include <QThread>

MessageModell* DataDownloader::getModel()
{
    return &model;
}

DataDownloader::DataDownloader(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager();

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(managerGetFinished(QNetworkReply*)));
}

void DataDownloader::downloadJSON(QString url)
{
    QUrl baseURL(url);
    QNetworkRequest request(baseURL);
    manager->get(request);
}

void DataDownloader::managerGetFinished(QNetworkReply* reply)
{
    QByteArray rawdata = reply->readAll();

    decodeJSON(rawdata);

    qDebug()<<"download finished";
}

void DataDownloader::decodeJSON(QByteArray rawData)
{
    QJsonDocument data = QJsonDocument::fromJson(rawData);

    if(data.isEmpty())
    {
        qDebug()<<"Data is not valid.";
    }
    if(data.isArray())
    {
        QJsonArray rootArray = data.array();
        qDebug()<<"Array is created";

        //Update the messages list
        for(int i=0; i< rootArray.size(); i++)
        {

            if(rootArray[i].isObject())
            {
                QJsonObject object = rootArray[i].toObject();

                Message msg(object);

                model.addMessage(msg);
            }
        }
    }

}


