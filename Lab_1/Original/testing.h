#ifndef TESTING_H
#define TESTING_H
#include"puzzle.h"
#include <QtTest/QtTest>


class TestQString: public QObject
{
    Q_OBJECT
public slots:
    void FinishingThePuzzle(){
        QVector<int> arr1;
        QVector<int> arr2;
        QVector<int> arr3;
        arr1.clear();
        arr2.clear();
        arr3.clear();
        for(int i=0;i<8;i++){
            arr1.push_back(i);
            arr2.push_back(2);
            arr3.push_back(8-i);
        }
        puzzle w;
        w.IfFinished(arr1);
        QCOMPARE(w.IfFinished(arr1), bool (true));
        QCOMPARE(w.IfFinished(arr2), bool (false));
        QCOMPARE(w.IfFinished(arr3), bool (false));

    }
};

#endif // TESTING_H
