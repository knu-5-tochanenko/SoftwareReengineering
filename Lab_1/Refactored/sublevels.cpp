#include "sublevels.h"
#include "clickablelabel.h"
#include "singleton.h"
#include "puzzle.h"
#include "levels.h"
#include "menu1.h"
#include "ui_sublevels.h"
#include "imageutils.h"
#include <QMessageBox>
#include <QDebug>
#include <QSettings>

sublevels::sublevels(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::sublevels)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    int level = Singleton::getInstance().sublevel / 10;
    if (level == 1 || level == 5)
    {
        close();
        puzzle window;
        window.setModal(true);
        window.exec();
    }

    ImageUtils::bindImage(Singleton::getInstance().wayToTheElement, ui->gridLayout_picture, 200, 200);

    int NumberOfSublevels;
    if (level == 4)
    {
        NumberOfSublevels = 5;
    }
    else
    {
        if (level == 1 || level == 5)
        {
            NumberOfSublevels = 0;
        }
        else
        {
            NumberOfSublevels = level;
        }
    }
    for (int i = 0; i < NumberOfSublevels; i++)
    {
        QPushButton *button = new QPushButton("picture " + QString::number(i + 1));
        ui->verticalLayout_sublevelButtons->addWidget(button);
        QString newWay = "";
        newWay += Singleton::getInstance().wayToTheElement;
        int pos = newWay.lastIndexOf(QChar('.'));
        newWay = newWay.left(pos);
        newWay += QString::number(i + 1) + ".jpg";
        button->setStatusTip(newWay);
        QObject::connect(button, SIGNAL(clicked()), this, SLOT(clickedSlot()));
    }
}

void sublevels::clickedSlot()
{
    Singleton::getInstance().wayToTheElement = ((QPushButton *)sender())->statusTip();
    hide();
    puzzle wind;
    wind.setModal(true);
    wind.exec();
}

sublevels::~sublevels()
{
    delete ui;
}

void sublevels::on_pushButton_menu_clicked()
{
    close();
    menu1 w;
    w.setModal(true);
    w.exec();
}
