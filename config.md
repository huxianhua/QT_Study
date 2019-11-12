```cpp
#ifndef CONFIG_H
#define CONFIG_H
/**
 * @file        config.h
 * @brief       关于打印相关常用信息
 * @details     细节
 * @mainpage    工程概览
 * @author      huxianhua
 * @email       huxianhua@zoncare.cn
 * @version     版本号
 * @date        年-月-日
 * @license     版权
 */

#include <QTime>
#include <QDateTime>
#include <QApplication>
#include <QDesktopWidget>
#include <QMetaEnum>
#include <QDebug>
#include <QFileInfo>

#define TIMEMS        qPrintable (QTime::currentTime().toString("HH:mm:ss zzz"))
#define TIME          qPrintable (QTime::currentTime().toString("HH:mm:ss"))
#define QDATE         qPrintable (QDate::currentDate().toString("yyyy-MM-dd"))
#define QTIME         qPrintable (QTime::currentTime().toString("HH-mm-ss"))
#define DATETIME      qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
#define STRDATETIME   qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss"))
#define STRDATETIMEMS qPrintable (QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss-zzz"))

#define AppName       "AppName"
#define AppPath       qApp->applicationDirPath()
#define AppVersion    "V0.1"

#define AppDeskWidth  qApp->desktop()->availableGeometry().width()
#define AppDeskHeight qApp->desktop()->availableGeometry().height()

#ifndef qUtf8Printable
#define qUtf8Printable(str) str.toUtf8().data()
#endif

/*
0.[A]：断言(Assert)
1.[E]：错误(Error)
2.[W]：警告(Warn)
3.[I]：信息(Info)
4.[D]：调试(Debug)
5.[V]：详细(Verbose)
*/
#define FILEBASENAME        qUtf8Printable(QFileInfo(__FILE__).baseName())

#define LOG_A(format,...)   qDebug("Assert [%s %s-%s-%d]   "#format,STRDATETIMEMS,FILEBASENAME,__FUNCTION__,__LINE__,##__VA_ARGS__)
#define LOG_E(format,...)   qDebug("Error [%s %s-%s-%d]    "#format,STRDATETIMEMS,FILEBASENAME,__FUNCTION__,__LINE__,##__VA_ARGS__)
#define LOG_W(format,...)   qDebug("Warn [%s %s-%s-%d]     "#format,STRDATETIMEMS,FILEBASENAME,__FUNCTION__,__LINE__,##__VA_ARGS__)
#define LOG_I(format,...)   qDebug("Info [%s %s-%s-%d]     "#format,STRDATETIMEMS,FILEBASENAME,__FUNCTION__,__LINE__,##__VA_ARGS__)
#define LOG_D(format,...)   qDebug("Debug [%s %s-%s-%d]    "#format,STRDATETIMEMS,FILEBASENAME,__FUNCTION__,__LINE__,##__VA_ARGS__)
#define LOG_V(format,...)   qDebug("Verbose [%s %s-%s-%d]  "#format,STRDATETIMEMS,FILEBASENAME,__FUNCTION__,__LINE__,##__VA_ARGS__)


#endif // CONFIG_H
```
