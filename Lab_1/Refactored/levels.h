#ifndef LEVELS_H
#define LEVELS_H

#include "mainwindow.h"
#include <QDialog>
#include <QPushButton>

namespace Ui
{
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
    void on_pushButton_1Level_clicked();
    void on_pushButton_2Level_clicked();
    void on_pushButton_3Level_clicked();
    void on_pushButton_4Level_clicked();
    void on_pushButton_5Level_clicked();
    void on_pushButton_1Level1Sublevel_clicked();
    void on_pushButton_1Level2Sublevel_clicked();
    void on_pushButton_2Level1Sublevel_clicked();
    void on_pushButton_2Level2Sublevel_clicked();
    void on_pushButton_3Level1Sublevel_clicked();
    void on_pushButton_3Level2Sublevel_clicked();
    void on_pushButton_4Level1Sublevel_clicked();
    void on_pushButton_4Level2Sublevel_clicked();
    void on_pushButton_menu_clicked();
    void on_pushButton_exit_clicked();
    void showLevelButtons(QPushButton* left, QPushButton* right);

private:
    Ui::levels *ui;
};

#endif // LEVELS_H
