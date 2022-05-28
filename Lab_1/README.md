# Лабораторна 1. Рефакторинг програмного коду.

**Автор проєкту:** Анонімний студент ФКНК Київського національного університету ім. Тараса Шевченка.

**Опис проєкту:** Додаток для систем Windows 7+ який дозволяє користувачеві пройти 5 рівнів складання пазлів різної складності, а також дозволяє завантажувати своє зображення для гри у пазл з ним.

**Рефакторинг виконав:** Точаненко Владислав

## Звіт рефакторингу

### 1. Видалення зайвих коментарів та пустих строчок. Додавання фігурних дужок до `if`, `else`, `while` і інших програмних структур; переміщення фігурних дужок згідно стандартів C++

Приклад роботи на файлі `main.cpp`. Повні зміни [у мердж реквесті](https://github.com/knu-5-tochanenko/SoftwareReengineering/pull/1/files).

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

### 2. Зміна назв об'єктів на інтерфейсі користувача.

Багато об'єктів було названо за схемою `objectType_X`, де `objectType` - тип об'єкту, а `X` - порядковий номер об'єкту цього типу на кожному вікні. Приклад об'єкту: `pushButton`, `pushButton_2` і `pushButton_3`. Під час рефакторингу назв таких об'єктів у `*.ui` файлах також необхідно було зробити відповідні модифікації і в `*.h` та `*.cpp` файлах.

Повні зміни [у мердж реквесті](https://github.com/knu-5-tochanenko/SoftwareReengineering/pull/2/files).

### 3. Вилучення дубльованого коду

Повні зміни [у мердж реквесті](https://github.com/knu-5-tochanenko/SoftwareReengineering/pull/3/files).

Прикладом дубльованого коду є додавання зображення у об'єкт в UI:

```cpp
QPixmap pixmap(":/levels/star.png");
pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
QLabel *labelScore = new QLabel;
labelScore->setPixmap(pixmap);
ui->gridLayout_star->addWidget(labelScore, 0, 0);
```

На прикладі цього було розроблено допоміжний клас, який спрощує використання до:

```cpp
ImageUtils::bindImage<QGridLayout>(":/levels/star.png", ui->gridLayout_star, 50, 50);
```

Другий приклад у класі `Levels`:

```cpp
void levels::on_pushButton_2_clicked()
{
    makeInvisible();
    ui->pushButton_8->setVisible(true);
    ui->pushButton_9->setVisible(true);

}

void levels::on_pushButton_3_clicked()
{
    makeInvisible();
    ui->pushButton_10->setVisible(true);
    ui->pushButton_11->setVisible(true);

}

void levels::on_pushButton_4_clicked()
{
    makeInvisible();
    ui->pushButton_12->setVisible(true);
    ui->pushButton_13->setVisible(true);

}
```

:arrow_down:

```cpp
void levels::on_pushButton_2Level_clicked()
{
    showLevelButtons(ui->pushButton_2Level1Sublevel, ui->pushButton_2Level2Sublevel);
}

void levels::on_pushButton_3Level_clicked()
{
    showLevelButtons(ui->pushButton_3Level1Sublevel, ui->pushButton_3Level2Sublevel);
}

void levels::on_pushButton_4Level_clicked()
{
    showLevelButtons(ui->pushButton_4Level1Sublevel, ui->pushButton_4Level2Sublevel);
}
```

### 4. Оптимізація циклів і структур розгалудження

Повні зміни [у мердж реквесті](https://github.com/knu-5-tochanenko/SoftwareReengineering/pull/4/files).

Змінна `q` під час виконання циклу змінюється на `true`, що робить входження програми у блок `if` неможливим до самого кінця виконання циклу. Таким чином необхідно або прибрати конструкцію `break` і додати умову завершення циклу при `q == true`, або прибрати змінну `q` взагалі:

```cpp
void puzzle::help()
{
    bool q = false;
    for (int i = 0; i < places.size(); i++)
    {
        if (places[i] != i && q == false)
        {
            /* ... */
            q = true;
            break;
        }
    }
}
```

:arrow_down:

```cpp
void puzzle::help()
{
    for (int i = 0; i < places.size(); i++)
    {
        if (places[i] != i)
        {
            /* ... */
            break;
        }
    }
}
```

У наступному прикладі порівняння змінної із значенням `true` непотрібна, адже вона і так є змінною типу `bool`:

```cpp
if (Singleton::getInstance().IfLevels == true)
{
    /* ... */
}
```

:arrow_down:

```cpp
if (Singleton::getInstance().IfLevels)
{
    /* ... */
}
```

У наступному прикладі необхідно знайти чи є підрівень пройденим чи ні. Для цього використовується змінна `a`. При проходженні усіх пройдених рівнів можливий такий випадок, що підрівень був пройдений на одній із перших ітерацій циклу. Необхідно, щоби він перестав виконуватись одразу як змінна `a` стане дорівнювати `true`:

```cpp
bool a = false;
for (int i = 0; i < Singleton::getInstance().visitedLevels.size(); i++)
{
    if (Singleton::getInstance().visitedLevels[i] == Singleton::getInstance().sublevel)
    {
        a = true;
    }
}
```

:arrow_down:

```cpp
bool a = false;
for (int i = 0; i < Singleton::getInstance().visitedLevels.size() && a; i++)
{
    if (Singleton::getInstance().visitedLevels[i] == Singleton::getInstance().sublevel)
    {
        a = true;
    }
}
```

У наступному прикладі функція повертає `true` або `false` в залежності від значення змінної `trueN`, тому структура `if` тут зайва, можна просто повернути значення порівняння:

```cpp
bool puzzle::IfFinished(QVector<int> places)
{
    int trueN = 0;
    
    /* ... */

    if (trueN == places.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
```

:arrow_down:

```cpp
bool puzzle::IfFinished(QVector<int> places)
{
    int trueN = 0;
    
    /* ... */

    return trueN == places.size();
}
```

У прикладі нижче було прибрана зайва вкладеність:

```cpp
if (level == 4)
{
    NumberOfSublevels = 5;
}
else
{
    if (level == 1 || level == 5)
    {
        NumberOfSublevels = 0;
    }
    else
    {
        NumberOfSublevels = level;
    }
}
```

:arrow_down:

```cpp
if (level == 4)
{
    NumberOfSublevels = 5;
}
else if (level == 1 || level == 5)
{
    NumberOfSublevels = 0;
}
else
{
    NumberOfSublevels = level;
}
```

### 5. Перейменування змінних або їх прибирання

Повні зміни [у мердж реквесті](https://github.com/knu-5-tochanenko/SoftwareReengineering/pull/5/files).

Деякі змінні використовуються для одноразового отримання результату. У данному прикладі її можна прибрати:

```cpp
int a = Singleton::getInstance().NumberOfStars;
ui->label_score->setText(QString::number(a));
```

:arrow_down:

```cpp
ui->label_score->setText(
    QString::number(Singleton::getInstance().NumberOfStars)
);
```

Деякі змінні мають назву, яка зовсім не відноситься до їх призначення:

```cpp
int trueN = 0;
for (int i = 0; i < places.size(); i++)
{
    if (places[i] == i)
    {
        trueN++;
    }
}
return trueN == places.size();
```

:arrow_down:

```cpp
int correctTiles = 0;
for (int i = 0; i < places.size(); i++)
{
    if (places[i] == i)
    {
        correctTiles++;
    }
}
return correctTiles == places.size();
```

Деякі змінні мають назву, яка не співпадає зі стандартним неймінгом змінних:

```cpp
int IfLevels;
int NumberOfStars;
```

:arrow_down:

```cpp
int ifLevels;
int numberOfStars;
```

## Висновок

У результаті виконання лабораторної роботи було покращено структуру коду, збільшена його ефективність, полегшана можливість його розширення, виправлені помилки у неймінгу змінних та методів, проаналізований проект на баги, які будуть пофікшені у наступній лабораторній.