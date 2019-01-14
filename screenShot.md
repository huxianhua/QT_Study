```cpp
void QtUtil::printscreen()
{
    QPixmap originalPixmap = QPixmap::grabWindow(QApplication::desktop()->winId());
    QString size_path;

    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep); //取得当地时间

    QDir dir;

    if(dir.exists("/mnt/udisk"))
    {
        size_path = "/mnt/udisk/screenshots";
    }else
    if(dir.exists("/mnt/sd"))
    {
        size_path = "/mnt/sd/screenshots";
    }

    if(size_path.length() > 0)
    {
        if(!dir.exists(size_path))
        {
            dir.mkdir(size_path);
        }

        QString fileName;

        fileName.sprintf("%s/%d%.2d%.2d%.2d%.2d%.2d.png",
                         qPrintable(size_path),
                         (1900+p->tm_year), (1+p->tm_mon), p->tm_mday,
                         p->tm_hour, p->tm_min, p->tm_sec);

        if( !fileName.isEmpty() )
        {
            originalPixmap.save(fileName);
            system("sync");
        }
    }
}
```
