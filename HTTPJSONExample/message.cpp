#include "message.h"
#include <QJsonObject>

QString Message::fromUser() const
{
    return m_fromUser;
}

void Message::setFromUser(const QString &value)
{
    m_fromUser = value;
}

QString Message::toUser() const
{
    return m_toUser;
}

void Message::setToUser(const QString &value)
{
    m_toUser = value;
}

QString Message::topic() const
{
    return m_topic;
}

void Message::setTopic(const QString &value)
{
    m_topic = value;
}

QString Message::content() const
{
    return m_content;
}

void Message::setContent(const QString &value)
{
    m_content = value;
}

Message::Message(const QJsonObject & object)
{
    QJsonValue toUserValue = object.value("from_user");
    QJsonValue fromUserValue = object.value("to_user");
    QJsonValue topicValue = object.value("topic");
    QJsonValue contentValue = object.value("content");

    if(toUserValue.isString()){
        this->m_toUser = toUserValue.toString();
    }
    if(fromUserValue.isString()){
        this->m_fromUser = fromUserValue.toString();
    }
    if(topicValue.isString()){
        this->m_topic = topicValue.toString();
    }
    if(contentValue.isString()){
        this->m_content = contentValue.toString();
    }
}
