#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "datadownloader.h"

int main(int argc, char *argv[])
{
    //Leave it here because the download is asynchronous
    QGuiApplication app(argc, argv);

    DataDownloader downloader;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    engine.rootContext()->setContextProperty("myModel",downloader.getModel());

    downloader.downloadJSON("http://atleast.aut.bme.hu/ait-ios/messenger/messages");

    return app.exec();
}
