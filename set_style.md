```cpp
void set_style(QString qssfile)
{
    QString qss = "";

    QFile f_qssfile(qssfile);

    if(f_qssfile.exists())
    {
         if(!f_qssfile.open(QIODevice::ReadOnly | QIODevice::Text))
         {
             return;
         }
         qss = f_qssfile.readAll();

         f_qssfile.close();
    }else
    {
        //加载默认的风格
        qss.append("#top_frame{background: #1E2D5A; border: none; min-height: 45px;}");
        qss.append("#top_frame QLabel{color: #0000FF; background: transparent; background-color: transparent;}");
        qss.append("#top_frame QToolButton{color: #FFFFFF; background: transparent; background-color: transparent;}");
    }
    //qDebug("%s -- %s %d 设置界面风格: qss:(%s)",__FILE__,__FUNCTION__,__LINE__,qss.toUtf8().data() );
    qApp->setStyleSheet(qss);
}
```
