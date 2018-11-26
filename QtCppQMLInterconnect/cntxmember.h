#ifndef CNTXMEMBER_H
#define CNTXMEMBER_H

#include <QObject>
#include <QVariant>

class CntxMember : public QObject
{
    Q_OBJECT
private:
    QString m_title;
public:
    explicit CntxMember(QObject *parent = nullptr);

    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)

    /*
     * A MEMBER variable association is required if no READ accessor
     * function is specified. This makes the given member variable
     * readable and writable without the need of creating READ and WRITE
     * accessor functions.
     * It's still possible to use READ or WRITE accessor
     * functions in addition to MEMBER variable association (but not both),
     * if you need to control the variable access.
     */

    //Q_PROPERTY(QString title MEMBER m_title NOTIFY titleChanged)

signals:
    void titleChanged();
    void demoSignal();

public slots:
    void setTitle(QString);
    QString getTitle();

    void emitTheSignal(){
        emit demoSignal();
    }
};

#endif // CNTXMEMBER_H
