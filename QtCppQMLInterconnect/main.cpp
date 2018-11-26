#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QObject>

#include <QMetaObject>
#include "interactor.h"

#include "cntxmember.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    //retreive the window QML component
    QObject* window = engine.rootObjects()[0];

    QObject* myText = window->findChild<QObject*>("myText");

    QVariant newTextValue(QString("Hello from C++!"));

    myText->setProperty("text",newTextValue);


    QObject* secondaryText = window->findChild<QObject*>("secondaryText");
    QVariant returnValue;
    QVariant newValueString = "It was set from C++ to!";

    //invoking method
    QMetaObject::invokeMethod(secondaryText,"setSecondaryText",
                              Q_RETURN_ARG(QVariant,returnValue),
                              Q_ARG(QVariant, newValueString));

    //connecting signals and slots
    Interactor* myInteractor = new Interactor();

    QObject* myButton = window->findChild<QObject*>("myButton");

    QObject::connect(myButton,SIGNAL(clicked()),myInteractor,SLOT(buttonClick()));

    QObject::connect(myInteractor,SIGNAL(updateButtonTitle(QVariant)),myButton,SLOT(updateButtonTitle(QVariant)));

    //using the context to pass references
    CntxMember* myCntxMember = new CntxMember();

    engine.rootContext()->setContextProperty("myCntxMember",myCntxMember);

    myCntxMember->emitTheSignal();

    return app.exec();
}
