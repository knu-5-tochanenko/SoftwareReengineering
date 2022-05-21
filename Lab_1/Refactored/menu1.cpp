#include "singleton.h"
#include "menu1.h"
#include "ui_menu1.h"
#include "levels.h"
#include "authorization.h"
#include "forpleasure.h"
#include<QSettings>

menu1::menu1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu1)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
}

void menu1::writeSettings(){
    QSettings users("Users", "puzzle1");
    users.beginGroup("puzzle1");
    users.setValue("numberOfStars", Singleton::getInstance().NumberOfStars);
    QString Visited="";
    for(int i=0; i<Singleton::getInstance().visitedLevels.size();i++){
        Visited+=Singleton::getInstance().visitedLevels[i];
        if(i+1<Singleton::getInstance().visitedLevels.size())
            Visited+=";";
    }
    users.setValue("visited Levels",Visited);
    users.endGroup();
}


void menu1::on_pushButton_3_clicked()
{
    writeSettings();
    hide();


}

void menu1::on_pushButton_2_clicked()
{
    hide();
   forPleasure wind;
   wind.setModal(true);
   wind.exec();
}

void menu1::on_pushButton_clicked()
{
    hide();
   levels window;
   //forPleasure window;
   window.setModal(true);
   window.exec();


}
menu1::~menu1()
{
    delete ui;
}
