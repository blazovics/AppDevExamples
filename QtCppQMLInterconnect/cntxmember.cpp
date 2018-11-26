#include "cntxmember.h"

CntxMember::CntxMember(QObject *parent) : QObject(parent)
{
    m_title = "Member of Context.";
}

void CntxMember::setTitle(QString newTitle)
{
    m_title = newTitle + "!!";
    emit titleChanged();
}

QString CntxMember::getTitle()
{
    QString returnString = m_title + "?";
    return returnString;
}
