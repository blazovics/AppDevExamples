#ifndef MESSAGE_H
#define MESSAGE_H

/*
 * Message class for storing a list element
 */

#include <QJsonObject>

class Message
{

    QString m_fromUser;
    QString m_toUser;
    QString m_topic;
    QString m_content;

public:

    Message(const QJsonObject&);

    QString fromUser() const;
    void setFromUser(const QString &value);

    QString toUser() const;
    void setToUser(const QString &value);

    QString topic() const;
    void setTopic(const QString &value);

    QString content() const;
    void setContent(const QString &value);
};

#endif // MESSAGE_H
