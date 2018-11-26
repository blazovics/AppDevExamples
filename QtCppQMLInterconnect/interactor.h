#ifndef INTERACTOR_H
#define INTERACTOR_H

#include <QObject>

#include <QVariant>

class Interactor : public QObject
{
    Q_OBJECT
public:
    explicit Interactor(QObject *parent = nullptr);

signals:
    void updateButtonTitle(QVariant);

public slots:
    void buttonClick();
};

#endif // INTERACTOR_H
