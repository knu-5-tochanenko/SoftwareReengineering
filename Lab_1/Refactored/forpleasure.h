#ifndef FORPLEASURE_H
#define FORPLEASURE_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class forPleasure;
}

class forPleasure : public QDialog
{
    Q_OBJECT

public:
    explicit forPleasure(QWidget *parent = nullptr);
    ~forPleasure();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::forPleasure *ui;

};

#endif // FORPLEASURE_H
