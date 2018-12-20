```cpp
QFile *global_logfile;

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString & str)
{
    QString txt=str;

    if(!global_logfile && !(global_logfile->isOpen()))
    {
        return;
    }

    static QMutex mutex;

    mutex.lock();
    QString log;

    switch(type)
    {
    case QtDebugMsg:
        log = QString("Debug: ");
        break;
    case QtWarningMsg:
        log = QString("Error: ");
        break;
    case QtCriticalMsg:
        log = QString("Critical Error: ");
        break;
    case QtFatalMsg:
        log = QString("Fatal Error: ");
        abort();
        break;
    default:
        log = QString("Unknow Msg Type : ");
        break;

    };


    log += QTime::currentTime().toString("hh:mm:ss.zzz, File: ") + QString(context.file) ;

    log += QString(", Line: " ) + QString::number(context.line) + QString(" : %1\n").arg(str);
    global_logfile->write(log.toStdString().c_str());
    global_logfile->flush();

    mutex.unlock();
}

#define LOG_DIR QString("%1/log").arg(qApp->applicationDirPath())


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setFont(QFont("msyh", 10, QFont::Normal));


    QDir dir(LOG_DIR);

    if(dir.exists())
    {
        QString path = QString("%1/log%2.log").arg(LOG_DIR).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd-HH_mm_ss"));
        global_logfile = new QFile(path);

        if (!global_logfile->open(QIODevice::ReadWrite | QIODevice::Append))
        {
            QString erinfo = global_logfile->errorString();
            printf("%s",erinfo.toUtf8().data());
        }
        qInstallMessageHandler(customMessageHandler);

    }else
    {
        qDebug("日志目录: %s  不存在，所以也不会生成日记",qUtf8Printable(LOG_DIR));
    }
    
    
    
    return a.exec();
}
    
    
```
