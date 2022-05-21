#ifndef MENU1_H
#define MENU1_H

#include <QDialog>

namespace Ui {
class menu1;
}

class menu1 : public QDialog
{
    Q_OBJECT

public:
    explicit menu1(QWidget *parent = nullptr);
    ~menu1();
    void writeSettings();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::menu1 *ui;
};

#endif // MENU1_H
