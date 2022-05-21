#ifndef LEVELS_H
#define LEVELS_H
#include "mainwindow.h"
#include <QDialog>


namespace Ui {
class levels;
}

class levels : public QDialog
{
    Q_OBJECT

public:
    explicit levels(QWidget *parent = nullptr);
    ~levels();
    void makeInvisible();
    void checkButtons();
    void goToPuzzle(int width, QString way, int level);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::levels *ui;
};

#endif // LEVELS_H
