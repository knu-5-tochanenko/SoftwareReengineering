#ifndef PUZZLE_H
#define PUZZLE_H

#include <QLayout>
#include <QDialog>
#include <QTime>
#include <QTimer>
#include "clickablelabel.h"

namespace Ui
{
    class puzzle;
}

class puzzle : public QDialog
{
    Q_OBJECT

public:
    explicit puzzle(QWidget *parent = nullptr);
    ~puzzle();
    ClickableLabel *picture1;

    int N;

    void swapElements(QLayoutItem *l1, QLayoutItem *l2);
    void sort();
    void help();
    bool ifFinished(QVector<int> places);
    void showStep();

private slots:
    void updateTime();
    void pic_clicked();
    void on_pushButton_toEnd_clicked();
    void on_pushButton_exit_clicked();
    void on_pushButton_forward_clicked();
    void on_pushButton_back_clicked();
    void on_pushButton_goBack_clicked();

private:
    Ui::puzzle *ui;
    QTimer *tmr;
};

#endif // PUZZLE_H
