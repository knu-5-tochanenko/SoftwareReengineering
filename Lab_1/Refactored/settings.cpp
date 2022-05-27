#include "settings.h"
#include "menu1.h"
#include "puzzle.h"
#include "singleton.h"
#include "ui_settings.h"
#include "puzzle.h"
#include "levels.h"
#include <QStyle>
#include <QSettings>

Settings::Settings(QWidget *parent) : QDialog(parent),
                                      ui(new Ui::Settings)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    int a = Singleton::getInstance().NumberOfStars;
    ui->labelScore->setText(QString::number(a));
    QPixmap pixmap(":/levels/star.png");
    pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
    QLabel *labelScore = new QLabel;
    labelScore->setPixmap(pixmap);
    ui->gridLayout_2->addWidget(labelScore, 0, 0);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_continue_clicked()
{
    hide();
}

void Settings::on_pushButton_goBack_clicked()
{
    close();
    puzzle wind;
    wind.close();
    levels w;
    w.setModal(true);
    w.exec();
}
