#ifndef MENUFORSINGLEPLAYER_H
#define MENUFORSINGLEPLAYER_H

#include <QMainWindow>

namespace Ui {
class menuForSinglePlayer;
}

class menuForSinglePlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit menuForSinglePlayer(QWidget *parent = nullptr);
    ~menuForSinglePlayer();

private:
    Ui::menuForSinglePlayer *ui;
};

#endif // MENUFORSINGLEPLAYER_H
