#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QMainWindow>

namespace Ui
{
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
    void on_pushButton_continue_clicked();
    void on_pushButton_exit_clicked();
    void on_pushButton_newGame_clicked();

private:
    Ui::authorization *ui;
};

#endif // AUTHORIZATION_H
