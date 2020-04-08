#include <QCoreApplication>
#include "randname.h"
#include <QDebug>
#include <QRandomGenerator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RandName rn;

    QString test_name;

    test_name = QString("随机女孩名:%1%2").arg(rn.randFirstName()).arg(rn.randName(0));
    qDebug("%s",test_name.toUtf8().data());

    test_name = QString("随机女孩名:%1%2").arg(rn.randFirstName()).arg(rn.randName(0));
    qDebug("%s",test_name.toUtf8().data());

    test_name = QString("随机男孩名:%1%2").arg(rn.randFirstName()).arg(rn.randName(1));
    qDebug() << test_name;

    test_name = QString("随机男孩名:%1%2").arg(rn.randFirstName()).arg(rn.randName(1));
    qDebug() << test_name;


    qDebug("=====随机产生 50 位学生姓名:");
    for(int index = 0; index < 5000; index++)
    {
        int gender = QRandomGenerator::global()->bounded(2);

        int k1 = QRandomGenerator::global()->bounded(101);
        int k2 = QRandomGenerator::global()->bounded(101);
        int k3 = QRandomGenerator::global()->bounded(101);

        test_name = QString("学号:%1 \t :%2孩名:%3%4 -- 数学:%5 \t 语文:%6 \t 英语: %7")
                .arg(index + 1)
                .arg(gender == 0? "女" : "男")
                .arg(rn.randFirstName())
                .arg(rn.randName(gender))
                .arg(k1)
                .arg(k2)
                .arg(k3);

    //qDebug() << test_name;
        qDebug("%s",test_name.toUtf8().data());
    }


    return a.exec();
}



