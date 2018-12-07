//changed from QGuiApplication
#include <QApplication>

#include <QQmlApplicationEngine>

#include "sinsource.h"

#include "burstdatasource.h"

#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //changed from QGuiApplication
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    SinSource sine;

    BurstDataSource burstData;

    QQmlContext* rootCtx = engine.rootContext();

    rootCtx->setContextProperty("sinSource",&sine);
    rootCtx->setContextProperty("burstData",&burstData);

    //burstData.generateData();

    burstData.saveData();
    burstData.loadData();

    return app.exec();
}
