#include "authorization.h"
#include "ui_authorization.h"
#include "menu1.h"
#include "singleton.h"
#include "imageutils.h"
#include <QSettings>

authorization::authorization(QWidget *parent) : QMainWindow(parent),
                                                ui(new Ui::authorization)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    readSettings();
    ui->setupUi(this);
    ui->label_score->setText(
                QString::number(Singleton::getInstance().numberOfStars)
    );
    ImageUtils::bindImage<QGridLayout>(":/levels/star.png", ui->gridLayout_label, 100, 100);

    connect(ui->pushButton_exit, SIGNAL(clicked()), this, SLOT(on_pushButton_exit_clicked()));
    connect(ui->pushButton_continue, SIGNAL(clicked()), this, SLOT(on_pushButton_continue_clicked()));
    connect(ui->pushButton_newGame, SIGNAL(clicked()), this, SLOT(on_pushButton_newGame_clicked()));
}

void authorization::readSettings()
{
    QSettings users("Users", "puzzle1");
    users.beginGroup("puzzle1");
    Singleton::getInstance().numberOfStars = users.value("numberOfStars", 0).toInt();
    QString visitedLevels = users.value("visited Levels", "").toString();

    int pos = visitedLevels.lastIndexOf(QChar(';'));
    if (pos == -1)
    {
        Singleton::getInstance().visitedLevels.push_back(visitedLevels);
    }
    else
    {
        while (pos != -1)
        {
            QString newVisitedLevels = "";
            for (int i = pos + 1; i < visitedLevels.size(); i++)
            {
                newVisitedLevels += visitedLevels[i];
            }
            visitedLevels = visitedLevels.left(pos);
            Singleton::getInstance().visitedLevels.push_back(newVisitedLevels);
            pos = visitedLevels.lastIndexOf(QChar(';'));
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

void clearData() {
    Singleton::getInstance().wayToTheElement.clear();
    Singleton::getInstance().width = NULL;
    Singleton::getInstance().ifLevels = NULL;
    Singleton::getInstance().sublevel = NULL;
    Singleton::getInstance().numberOfStars = 0;
    Singleton::getInstance().sort = NULL;
    Singleton::getInstance().step = NULL;
    Singleton::getInstance().stepsForSorting.clear();
    Singleton::getInstance().visitedLevels.clear();

    QSettings users("Users", "puzzle1");
    users.beginGroup("puzzle1");
    users.remove("");
    users.endGroup();
}

void authorization::on_pushButton_newGame_clicked()
{
    clearData();
    hide();
    menu1 window;
    window.setModal(true);
    window.writeSettings();
    window.exec();
}
