# Лабораторна 1. Рефакторинг програмного коду.

**Автор проєкту:** Анонімний студент ФКНК Київського національного університету ім. Тараса Шевченка.

**Рефакторинг виконав:** Точаненко Владислав

## Звіт рефакторингу

### 1. Видалення зайвих коментарів та пустих строчок. Додавання фігурних дужок до `if`, `else`, `while` і інших програмних структур; переміщення фігурних дужок згідно стандартів C++

Приклад роботи на файлі `main.cpp`. Повні зміни [у мердж реквесті](https://www.google.com).

**Було:**

```cpp
#include "authorization.h"
#include "singleton.h"
//#include "testing.h"
#include <QApplication>
#include <QDialog>
#include <QString>
#include<QDebug>
#include<QSettings>





int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    authorization w;
    //w.readSettings();
    w.show();
    /*TestQString test;
    test.FinishingThePuzzle();*/

    return a.exec();
}
```

**Стало:**

```cpp
#include "authorization.h"
#include "singleton.h"
#include <QApplication>
#include <QDialog>
#include <QString>
#include <QDebug>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    authorization w;
    w.show();
    return a.exec();
}
```