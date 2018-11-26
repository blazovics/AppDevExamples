#include "interactor.h"
#include <QDebug>

Interactor::Interactor(QObject *parent) : QObject(parent)
{

}

void Interactor::buttonClick()
{
    //Simmilar to std::cout but it is intended to serve as logger for Qt
    qDebug() << "Button clicked signal handled";
    emit updateButtonTitle(QVariant("C++ click"));
}
