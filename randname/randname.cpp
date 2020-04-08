#include "randname.h"
#include <QFile>
#include <QDebug>
#include <QTime>
#include <QRandomGenerator>

RandName::RandName(QObject *parent) : QObject(parent)
{
    loadDB();
}

void RandName::loadDB()
{
    QString name_1 = QString(":/name/resources/百家姓.txt");
    QString name_2 = QString(":/name/resources/男孩常用名.txt");
    QString name_3 = QString(":/name/resources/女孩常用名.txt");

    //- 加载 百家姓
    m_first_name = readFile(name_1);
    m_first_name_len = m_first_name.length();
    //print_first_name();

    //- 加载 男孩常用名
    m_boy_name   = readFile(name_2);
    m_boy_name_list = m_boy_name.split(',');
    m_boy_name_list_len = m_boy_name_list.length();
    //print_boy_name();

    //- 加载 女孩常用名
    m_gril_name   = readFile(name_3);
    m_gril_name_list = m_gril_name.split(',');
    m_gril_name_list_len = m_gril_name_list.length();
    //print_gril_name();
}

QString RandName::randFirstName()
{
    int random_value = QRandomGenerator::global()->bounded(m_first_name_len);
    return m_first_name.mid(random_value,1);
}

QString RandName::randName(int gender)
{
    int random_value;

    if(gender == 0)
    {
        random_value = QRandomGenerator::global()->bounded(m_gril_name_list_len);
        return m_gril_name_list.at(random_value);
    }else
    if(gender == 1)
    {
        random_value = QRandomGenerator::global()->bounded(m_boy_name_list_len);
        return m_boy_name_list.at(random_value);
    }else
    {
        qDebug("参数错误，性别只能为 0或1, (%d)",gender);
        return QString();
    }
}

QString RandName::readFile(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return QString();
    }
    QByteArray byteArray = file.readAll();
    file.close();
    return QString(byteArray);
}

void RandName::print_first_name()
{
    qDebug("百家姓:(%s)",qUtf8Printable(m_first_name));

    int len = m_first_name.length();
    qDebug("len:(%d)",len);

    for(int index = 0; index < len; index++)
    {
        qDebug() << index << ":" << m_first_name.mid(index,1).toUtf8().data();
    }
}

void RandName::print_boy_name()
{
    qDebug("男孩名:(%s)",qUtf8Printable(m_boy_name));

    int len = m_boy_name_list.length();
    qDebug("len:(%d)",len);

    for(int index = 0; index < len; index++)
    {
        qDebug() << index << ":" << m_boy_name_list.at(index);
    }
}
void RandName::print_gril_name()
{
    qDebug("女孩名:(%s)",qUtf8Printable(m_gril_name));

    int len = m_gril_name_list.length();
    qDebug("len:(%d)",len);

    for(int index = 0; index < len; index++)
    {
        qDebug() << index << ":" << m_gril_name_list.at(index);
    }
}
