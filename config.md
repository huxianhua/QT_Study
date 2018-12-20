```cpp
#ifndef CONFIG_H
#define CONFIG_H

#include <QTime>
#include <QDateTime>
#include <QApplication>
#include <QDesktopWidget>

#include <qDebug>

#define TIMEMS        qPrintable (QTime::currentTime().toString("HH:mm:ss zzz"))
#define TIME          qPrintable (QTime::currentTime().toString("HH:mm:ss"))
#define QDATE         qPrintable (QDate::currentDate().toString("yyyy-MM-dd"))
#define QTIME         qPrintable (QTime::currentTime().toString("HH-mm-ss"))
#define DATETIME      qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
#define STRDATETIME   qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss"))
#define STRDATETIMEMS qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss-zzz"))

#define AppName       "应用名称"
#define AppPath       qApp->applicationDirPath()
#define AppDeskWidth  qApp->desktop()->availableGeometry().width()
#define AppDeskHeight qApp->desktop()->availableGeometry().height()

#define AppVersion    "V0.1"




#define LOG_FFL       qDebug("[%s-%s-%d]",__FILE__,__FUNCTION__,__LINE__)
#define LOG_DEBUG(format,...) qDebug("[%s-%s-%d]  "#format,__FILE__,__FUNCTION__,__LINE__,##__VA_ARGS__)
#define LOG_Fatal qFatal("[%s-%s-%d]",__FILE__,__FUNCTION__,__LINE__)




#endif // CONFIG_H


```
