#include "end.h"
#include "ui_end.h"
#include "singleton.h"
#include "levels.h"
#include "menu1.h"
#include "forpleasure.h"
#include "imageutils.h"
#include <QSettings>

End::End(QWidget *parent) : QDialog(parent),
                            ui(new Ui::End)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    int a = Singleton::getInstance().NumberOfStars;
    ui->label_score->setText(QString::number(a));
    ImageUtils::bindImage(":/levels/star.png", ui->gridLayout_star, 100, 100);
}

End::~End()
{
    delete ui;
}

void End::on_pushButton_forPleasure_clicked()
{
    hide();
    forPleasure w;
    w.setModal(true);
    w.exec();
}

void End::on_pushButton_levels_clicked()
{
    hide();
    levels w;
    w.setModal(true);
    w.exec();
}

void End::on_pushButton_exit_clicked()
{
    menu1 wind;
    wind.writeSettings();
    hide();
}
