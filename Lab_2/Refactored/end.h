#ifndef END_H
#define END_H

#include <QDialog>

namespace Ui
{
    class End;
}

class End : public QDialog
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);
    ~End();

private slots:
    void on_pushButton_forPleasure_clicked();
    void on_pushButton_levels_clicked();
    void on_pushButton_exit_clicked();

private:
    Ui::End *ui;
};

#endif // END_H
