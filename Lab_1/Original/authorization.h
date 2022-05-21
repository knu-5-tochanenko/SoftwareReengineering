#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QMainWindow>

namespace Ui {
class authorization;
}

class authorization : public QMainWindow
{
    Q_OBJECT

public:
    explicit authorization(QWidget *parent = nullptr);
    ~authorization();
    void readSettings();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::authorization *ui;
};

#endif // AUTHORIZATION_H
