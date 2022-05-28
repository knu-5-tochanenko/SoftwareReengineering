#include <QSettings>
#include "forpleasure.h"
#include "ui_forpleasure.h"
#include "menu1.h"
#include "puzzle.h"
#include "singleton.h"
#include "imageutils.h"
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

forPleasure::forPleasure(QWidget *parent) : QDialog(parent),
                                            ui(new Ui::forPleasure)
{
    ui->setupUi(this);
    ui->spinBox_sort->setRange(1, 4);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    Singleton::getInstance().ifLevels = false;
}

forPleasure::~forPleasure()
{
    delete ui;
}

void forPleasure::on_pushButton_selectPicture_clicked()
{
    if (ui->horizontalLayout_picture->count() == 1)
    {
        ui->horizontalLayout_picture->removeItem(ui->horizontalLayout_picture->takeAt(0));
    }

    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "/pic",
        tr("Images (*.png *.xpm *.jpg)"));

    Singleton::getInstance().wayToTheElement = fileName;
    QPixmap pixmap(fileName);
    Singleton::getInstance().width = ui->spinBox_puzzleSize->value();
    pixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio);
    ImageUtils::bindPixmap<QBoxLayout>(pixmap, ui->horizontalLayout_picture);
}

void forPleasure::on_pushButton_play_clicked()
{
    hide();
    puzzle window;
    window.setModal(true);
    window.exec();
    Singleton::getInstance().sort = ui->spinBox_sort->value();
}

void forPleasure::on_pushButton_menu_clicked()
{
    hide();
    menu1 window;
    window.setModal(true);
    window.exec();
}

void forPleasure::on_pushButton_exit_clicked()
{
    hide();
    menu1 window;
    window.writeSettings();
}
