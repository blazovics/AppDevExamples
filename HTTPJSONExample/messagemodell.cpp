/*
 * This file is used to create a reactive list for a
 * QML ListView in order to automatically update the
 * ListView when the data chages.
 *
 */

#include "messagemodell.h"

MessageModell::MessageModell(QObject *parent):QAbstractListModel (parent)
{
}

void MessageModell::addMessage(const Message &message)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_messages << message;
    endInsertRows();
}

void MessageModell::removeMessages()
{
    beginRemoveRows(QModelIndex(),0,rowCount());
    m_messages.clear();
    endRemoveRows();
}

int MessageModell::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_messages.count();
}

QVariant MessageModell::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_messages.count())
    {
        return  QVariant();
    }

    const Message &message = m_messages[index.row()];

    switch (role) {
        case FromUserRole:
            return message.fromUser();
        case ToUserRole:
            return message.toUser();
        case TopicRole:
            return message.topic();
        case ContentRole:
            return message.content();
    }
    return QVariant();
}

QHash<int, QByteArray> MessageModell::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FromUserRole] = "fromUser";
    roles[ToUserRole] = "toUser";
    roles[TopicRole] = "topic";
    roles[ContentRole] = "content";

    return roles;
}
