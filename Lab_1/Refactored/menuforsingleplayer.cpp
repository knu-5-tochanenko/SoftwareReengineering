#include "menuforsingleplayer.h"
#include "ui_menuforsingleplayer.h"

menuForSinglePlayer::menuForSinglePlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menuForSinglePlayer)
{
    ui->setupUi(this);
}

menuForSinglePlayer::~menuForSinglePlayer()
{
    delete ui;
}
