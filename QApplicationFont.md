# 设置编码与字体

```cpp
    QApplication a(argc, argv);

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QApplication::setFont(QFont(QObject::tr("WenQuanYi Micro Hei"), 12, QFont::Normal));
#endif
```
