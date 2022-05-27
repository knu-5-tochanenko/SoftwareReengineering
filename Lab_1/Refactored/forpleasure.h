#ifndef FORPLEASURE_H
#define FORPLEASURE_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui
{
    class forPleasure;
}

class forPleasure : public QDialog
{
    Q_OBJECT

public:
    explicit forPleasure(QWidget *parent = nullptr);
    ~forPleasure();

private slots:
    void on_pushButton_selectPicture_clicked();
    void on_pushButton_play_clicked();
    void on_pushButton_menu_clicked();
    void on_pushButton_exit_clicked();

private:
    Ui::forPleasure *ui;
};

#endif // FORPLEASURE_H
