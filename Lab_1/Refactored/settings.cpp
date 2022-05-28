#include "settings.h"
#include "menu1.h"
#include "puzzle.h"
#include "singleton.h"
#include "ui_settings.h"
#include "puzzle.h"
#include "levels.h"
#include "imageutils.h"
#include <QStyle>
#include <QSettings>

Settings::Settings(QWidget *parent) : QDialog(parent),
                                      ui(new Ui::Settings)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    ui->label_score->setText(
                QString::number(Singleton::getInstance().numberOfStars)
    );
    ImageUtils::bindImage<QGridLayout>(":/levels/star.png", ui->gridLayout_star, 50, 50);
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
