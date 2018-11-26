```cpp
QRandomGenerator rg;
int r = QRandomGenerator::global()->bounded(256);
int g = QRandomGenerator::global()->bounded(256);
int b = QRandomGenerator::global()->bounded(256);

QColor(r,g,b);

```
