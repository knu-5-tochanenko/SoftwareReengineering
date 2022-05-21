#ifndef PUZZLE_H
#define PUZZLE_H

#include<QLayout>
#include <QDialog>
#include<QTime>
#include<QTimer>
#include "clickablelabel.h"

namespace Ui {
class puzzle;
}

class puzzle : public QDialog
{
    Q_OBJECT

public:
    explicit puzzle(QWidget *parent = nullptr);
    ~puzzle();
    ClickableLabel* picture1;

       int N;
    void swapElements(QLayoutItem *l1,QLayoutItem *l2);
    void sort();
    void help();
    bool IfFinished(QVector<int> places);
    void showStep();
    void NewSort(QVariant a);
private slots:
     void updateTime();
    void pic_clicked();



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();


private:
    Ui::puzzle *ui;
    QTimer *tmr;
};

#endif // PUZZLE_H
