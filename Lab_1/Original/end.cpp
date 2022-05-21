#include "end.h"
#include "ui_end.h"
#include "singleton.h"
#include "levels.h"
#include "menu1.h"
#include "forpleasure.h"
#include<QSettings>

End::End(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    int a= Singleton::getInstance().NumberOfStars;
    ui->label->setText(QString::number(a));
    QPixmap pixmap(":/levels/star.png");
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
    QLabel *label=new QLabel;
    label->setPixmap(pixmap);
    ui->gridLayout->addWidget(label, 0,0);
}

End::~End()
{
    delete ui;
}

void End::on_pushButton_2_clicked()
{
    hide();
    forPleasure w;
    w.setModal(true);
    w.exec();
}

void End::on_pushButton_clicked()
{
    hide();
    levels w;
    w.setModal(true);
    w.exec();
}

void End::on_pushButton_3_clicked()
{
    menu1 wind;
    wind.writeSettings();
    hide();
}
