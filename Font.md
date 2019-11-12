# 打印所有字体名称
```cpp
qDebug("打印所有字体名称:");
QFontDatabase database;
foreach (const QString &family, database.families())
{
    qDebug()<<family;
}
```
# 打印中文字体
```cpp
qDebug("打印中文字体名称:");
foreach (const QString &family, database.families(QFontDatabase::SimplifiedChinese))
{
    qDebug()<<family;
}
```
