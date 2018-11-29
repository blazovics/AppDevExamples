/*
 * This file is used to create a reactive list for a
 * QML ListView in order to automatically update the
 * ListView when the data chages.
 *
 */

#ifndef MESSAGEMODELL_H
#define MESSAGEMODELL_H

#include <QAbstractListModel>
#include <QStringList>
#include "message.h"

class MessageModell : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MessageRoles{
        FromUserRole = Qt::UserRole + 1,
        ToUserRole,
        TopicRole,
        ContentRole
    };

    MessageModell(QObject *parent = nullptr);

    void addMessage(const Message &message);

    void removeMessages();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Message> m_messages;
};

#endif // MESSAGEMODELL_H
