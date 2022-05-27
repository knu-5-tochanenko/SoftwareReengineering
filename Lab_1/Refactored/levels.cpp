#include "levels.h"
#include "puzzle.h"
#include "menu1.h"
#include "singleton.h"
#include "sublevels.h"
#include "ui_levels.h"
#include <QStyle>
#include <QSettings>

levels::levels(QWidget *parent) : QDialog(parent),
                                  ui(new Ui::levels)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    makeInvisible();
    checkButtons();
    Singleton::getInstance().IfLevels = true;
}

levels::~levels()
{
    delete ui;
}

void levels::makeInvisible()
{
    ui->pushButton_1Level1Sublevel->setVisible(false);
    ui->pushButton_1Level2Sublevel->setVisible(false);
    ui->pushButton_2Level1Sublevel->setVisible(false);
    ui->pushButton_2Level2Sublevel->setVisible(false);
    ui->pushButton_3Level1Sublevel->setVisible(false);
    ui->pushButton_3Level2Sublevel->setVisible(false);
    ui->pushButton_4Level1Sublevel->setVisible(false);
    ui->pushButton_4Level2Sublevel->setVisible(false);
}

void levels::checkButtons()
{
    if (Singleton::getInstance().NumberOfStars >= 10)
    {
        ui->pushButton_2Level->setEnabled(true);
    }
    if (Singleton::getInstance().NumberOfStars >= 25)
    {
        ui->pushButton_3Level->setEnabled(true);
    }
    if (Singleton::getInstance().NumberOfStars >= 45)
    {
        ui->pushButton_4Level->setEnabled(true);
    }
    if (Singleton::getInstance().NumberOfStars >= 100)
    {
        ui->pushButton_5Level->setEnabled(true);
    }
}

void levels::on_pushButton_1Level_clicked()
{
    makeInvisible();
    ui->pushButton_1Level1Sublevel->setVisible(true);
    ui->pushButton_1Level2Sublevel->setVisible(true);
}

void levels::goToPuzzle(int width, QString way, int level)
{
    Singleton::getInstance().width = width;
    Singleton::getInstance().wayToTheElement = way;
    Singleton::getInstance().sublevel = level;
    hide();
    int lev = Singleton::getInstance().sublevel / 10;
    if (lev == 1 || lev == 5)
    {
        hide();
        puzzle window;
        window.setModal(true);
        window.exec();
    }
    else
    {
        sublevels window;
        window.setModal(true);
        window.exec();
    }
}

void levels::on_pushButton_2Level_clicked()
{
    showLevelButtons(ui->pushButton_2Level1Sublevel, ui->pushButton_2Level2Sublevel);
}

void levels::on_pushButton_3Level_clicked()
{
    showLevelButtons(ui->pushButton_3Level1Sublevel, ui->pushButton_3Level2Sublevel);
}

void levels::on_pushButton_4Level_clicked()
{
    showLevelButtons(ui->pushButton_4Level1Sublevel, ui->pushButton_4Level2Sublevel);
}

void levels::showLevelButtons(QPushButton *left, QPushButton *right)
{
    makeInvisible();
    left->setVisible(true);
    right->setVisible(true);
}

void levels::on_pushButton_5Level_clicked()
{

    goToPuzzle(4, ":/levels/9.png", 51);
}

void levels::on_pushButton_1Level1Sublevel_clicked()
{
    goToPuzzle(2, ":/levels/1.jpg", 11);
}

void levels::on_pushButton_1Level2Sublevel_clicked()
{
    goToPuzzle(2, ":/levels/2.jpg", 12);
}

void levels::on_pushButton_2Level1Sublevel_clicked()
{
    goToPuzzle(3, ":/levels/3.jpg", 23);
}

void levels::on_pushButton_2Level2Sublevel_clicked()
{
    goToPuzzle(3, ":/levels/4.jpg", 24);
}

void levels::on_pushButton_3Level1Sublevel_clicked()
{
    goToPuzzle(3, ":/levels/5.jpg", 35);
}

void levels::on_pushButton_3Level2Sublevel_clicked()
{
    goToPuzzle(4, ":/levels/6.jpg", 36);
}

void levels::on_pushButton_4Level1Sublevel_clicked()
{
    goToPuzzle(3, ":/levels/7.jpg", 47);
}

void levels::on_pushButton_4Level2Sublevel_clicked()
{
    goToPuzzle(4, ":/levels/8.jpg", 48);
}

void levels::on_pushButton_menu_clicked()
{
    hide();
    menu1 window;
    window.setModal(true);
    window.writeSettings();
    window.exec();
}

void levels::on_pushButton_exit_clicked()
{
    menu1 window;
    window.writeSettings();
    hide();
}
