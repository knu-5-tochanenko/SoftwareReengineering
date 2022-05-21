#include "levels.h"
#include "puzzle.h"
#include "menu1.h"
#include "singleton.h"
#include "sublevels.h"
#include "ui_levels.h"
#include<QStyle>
#include<QSettings>

levels::levels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::levels)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    makeInvisible();
    checkButtons();
    Singleton::getInstance().IfLevels=true;
}

levels::~levels()
{
    delete ui;
}



void levels:: makeInvisible(){
    ui->pushButton_6->setVisible(false);
    ui->pushButton_7->setVisible(false);
    ui->pushButton_8->setVisible(false);
    ui->pushButton_9->setVisible(false);
    ui->pushButton_10->setVisible(false);
    ui->pushButton_11->setVisible(false);
    ui->pushButton_12->setVisible(false);
    ui->pushButton_13->setVisible(false);
}

void levels:: checkButtons(){
    if(Singleton::getInstance().NumberOfStars>=10){
        ui->pushButton_2->setEnabled(true);
    }
    if(Singleton::getInstance().NumberOfStars>=25){
        ui->pushButton_3->setEnabled(true);
    }
    if(Singleton::getInstance().NumberOfStars>=45){
        ui->pushButton_4->setEnabled(true);
    }
    if(Singleton::getInstance().NumberOfStars>=100){
        ui->pushButton_5->setEnabled(true);
    }

}

void levels::on_pushButton_clicked()
{
    makeInvisible();
    ui->pushButton_6->setVisible(true);
    ui->pushButton_7->setVisible(true);

}

void levels::goToPuzzle(int width, QString way, int level){
    Singleton::getInstance().width=width;
    Singleton::getInstance().wayToTheElement=way;
    Singleton::getInstance().sublevel=level;
    hide();
    int lev= Singleton::getInstance().sublevel/10;
    if(lev==1 || lev==5){
        hide();
        puzzle window;
        window.setModal(true);
        window.exec();
    }else{
    sublevels window;
    window.setModal(true);
    window.exec();
    }
}


void levels::on_pushButton_2_clicked()
{
    makeInvisible();
    ui->pushButton_8->setVisible(true);
    ui->pushButton_9->setVisible(true);

}

void levels::on_pushButton_3_clicked()
{
    makeInvisible();
    ui->pushButton_10->setVisible(true);
    ui->pushButton_11->setVisible(true);

}

void levels::on_pushButton_4_clicked()
{
    makeInvisible();
    ui->pushButton_12->setVisible(true);
    ui->pushButton_13->setVisible(true);

}



void levels:: on_pushButton_5_clicked(){

    goToPuzzle(4,":/levels/9.png",51);
}


void levels:: on_pushButton_6_clicked(){
    goToPuzzle(2,":/levels/1.jpg",11);
}

void levels:: on_pushButton_7_clicked(){
    goToPuzzle(2,":/levels/2.jpg",12);
}

void levels:: on_pushButton_8_clicked(){
    goToPuzzle(3,":/levels/3.jpg",23);
}

void levels:: on_pushButton_9_clicked(){
    goToPuzzle(3,":/levels/4.jpg",24);
}

void levels:: on_pushButton_10_clicked(){
    goToPuzzle(3,":/levels/5.jpg",35);
}

void levels:: on_pushButton_11_clicked(){
    goToPuzzle(4,":/levels/6.jpg",36);
}

void levels:: on_pushButton_12_clicked(){
    goToPuzzle(3,":/levels/7.jpg",47);
}

void levels:: on_pushButton_13_clicked(){
    goToPuzzle(4,":/levels/8.jpg",48);
}



void levels::on_pushButton_14_clicked()
{
    hide();
    menu1 window;
    window.setModal(true);
    window.writeSettings();
    window.exec();

}

void levels::on_pushButton_15_clicked()
{
    menu1 window;
    window.writeSettings();
    hide();
}
