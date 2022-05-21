#include "authorization.h"
#include "ui_authorization.h"
#include "menu1.h"
#include "singleton.h"
#include<QSettings>
#include<QDebug>


authorization::authorization(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    readSettings();
    //qDebug()<<Singleton::getInstance().NumberOfStars;
    ui->setupUi(this);
    int a= Singleton::getInstance().NumberOfStars;
    ui->label->setText(QString::number(a));
    QPixmap pixmap(":/levels/star.png");
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
    QLabel *label=new QLabel;
    label->setPixmap(pixmap);
    ui->gridLayout_3->addWidget(label, 0,0);

    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(on_pushButton_2_clicked()));
    connect(ui->pushButton, SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()),this,SLOT(on_pushButton_3_clicked()));
}


void authorization::readSettings(){
    QSettings users("Users", "puzzle1");
    users.beginGroup("puzzle1");
    Singleton::getInstance().NumberOfStars = users.value("numberOfStars", 0).toInt();
    QString w = users.value("visited Levels", "").toString();

    int pos = w.lastIndexOf(QChar(';'));
    if(pos==-1)
        Singleton::getInstance().visitedLevels.push_back(w);
    else{
        while(pos!=-1){
    //qDebug()<<w;
    QString a="";
    for(int i=pos+1; i<w.size();i++){

        a+=w[i];
    }
    w=w.left(pos);
   // qDebug()<<a;
    Singleton::getInstance().visitedLevels.push_back(a);
    //qDebug()<<w;
   // w= w.left(pos);
    pos=w.lastIndexOf(QChar(';'));

    }
    }
    users.endGroup();

}



authorization::~authorization()
{
    delete ui;
}

void authorization::on_pushButton_clicked()
{
    hide();
    menu1 window;
    window.setModal(true);
    window.writeSettings();
    window.exec();
}

void authorization::on_pushButton_2_clicked()
{
    hide();
}

void authorization::on_pushButton_3_clicked()
{
    Singleton::getInstance().NumberOfStars=0;
    Singleton::getInstance().wayToTheElement.clear();
    hide();
    menu1 window;
    window.setModal(true);
    window.writeSettings();
    window.exec();

}

