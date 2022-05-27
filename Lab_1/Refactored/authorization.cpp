#include "authorization.h"
#include "ui_authorization.h"
#include "menu1.h"
#include "singleton.h"
#include "imageutils.h"
#include <QSettings>
#include <QDebug>

authorization::authorization(QWidget *parent) : QMainWindow(parent),
                                                ui(new Ui::authorization)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    readSettings();
    ui->setupUi(this);
    int a = Singleton::getInstance().NumberOfStars;
    ui->label_score->setText(QString::number(a));
    ImageUtils::bindImage(":/levels/star.png", ui->gridLayout_label, 100, 100);

    connect(ui->pushButton_exit, SIGNAL(clicked()), this, SLOT(on_pushButton_exit_clicked()));
    connect(ui->pushButton_continue, SIGNAL(clicked()), this, SLOT(on_pushButton_continue_clicked()));
    connect(ui->pushButton_newGame, SIGNAL(clicked()), this, SLOT(on_pushButton_newGame_clicked()));
}

void authorization::readSettings()
{
    QSettings users("Users", "puzzle1");
    users.beginGroup("puzzle1");
    Singleton::getInstance().NumberOfStars = users.value("numberOfStars", 0).toInt();
    QString w = users.value("visited Levels", "").toString();

    int pos = w.lastIndexOf(QChar(';'));
    if (pos == -1)
    {
        Singleton::getInstance().visitedLevels.push_back(w);
    }
    else
    {
        while (pos != -1)
        {
            QString a = "";
            for (int i = pos + 1; i < w.size(); i++)
            {
                a += w[i];
            }
            w = w.left(pos);
            Singleton::getInstance().visitedLevels.push_back(a);
            pos = w.lastIndexOf(QChar(';'));
        }
    }
    users.endGroup();
}

authorization::~authorization()
{
    delete ui;
}

void authorization::on_pushButton_continue_clicked()
{
    hide();
    menu1 window;
    window.setModal(true);
    window.writeSettings();
    window.exec();
}

void authorization::on_pushButton_exit_clicked()
{
    hide();
}

void authorization::on_pushButton_newGame_clicked()
{
    Singleton::getInstance().NumberOfStars = 0;
    Singleton::getInstance().wayToTheElement.clear();
    hide();
    menu1 window;
    window.setModal(true);
    window.writeSettings();
    window.exec();
}
