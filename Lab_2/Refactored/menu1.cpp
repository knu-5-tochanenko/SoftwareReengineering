#include "singleton.h"
#include "menu1.h"
#include "ui_menu1.h"
#include "levels.h"
#include "authorization.h"
#include "forpleasure.h"
#include <QSettings>

menu1::menu1(QWidget *parent) : QDialog(parent),
                                ui(new Ui::menu1)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
}

void menu1::writeSettings()
{
    QSettings users("Users", "puzzle1");
    users.beginGroup("puzzle1");
    users.setValue("numberOfStars", Singleton::getInstance().numberOfStars);
    QString visited = "";
    for (int i = 0; i < Singleton::getInstance().visitedLevels.size(); i++)
    {
        visited += Singleton::getInstance().visitedLevels[i];
        if (i + 1 < Singleton::getInstance().visitedLevels.size())
        {
            visited += ";";
        }
    }
    users.setValue("visited Levels", visited);
    users.endGroup();
}

void menu1::on_pushButton_exit_clicked()
{
    writeSettings();
    hide();
    QApplication::quit();
}

void menu1::on_pushButton_forPleasure_clicked()
{
    hide();
    forPleasure window;
    window.setModal(true);
    window.exec();
}

void menu1::on_pushButton_levels_clicked()
{
    hide();
    levels window;
    window.setModal(true);
    window.exec();
}
menu1::~menu1()
{
    delete ui;
}
