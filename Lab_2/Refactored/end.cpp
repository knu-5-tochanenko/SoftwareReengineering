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
    ui->label_score->setText(
                QString::number(Singleton::getInstance().numberOfStars)
    );
    ImageUtils::bindImage<QGridLayout>(":/levels/star.png", ui->gridLayout_star, 100, 100);
}

End::~End()
{
    delete ui;
}

void End::on_pushButton_forPleasure_clicked()
{
    hide();
    forPleasure window;
    window.setModal(true);
    window.exec();
}

void End::on_pushButton_levels_clicked()
{
    hide();
    levels window;
    window.setModal(true);
    window.exec();
}

void End::on_pushButton_exit_clicked()
{
    menu1 window;
    window.writeSettings();
    hide();
}
