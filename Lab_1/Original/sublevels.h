#ifndef SUBLEVELS_H
#define SUBLEVELS_H

#include <QDialog>

namespace Ui {
class sublevels;
}

class sublevels : public QDialog
{
    Q_OBJECT

public:
    explicit sublevels(QWidget *parent = nullptr);
    ~sublevels();
 public slots:
    void clickedSlot();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sublevels *ui;
};

#endif // SUBLEVELS_H
