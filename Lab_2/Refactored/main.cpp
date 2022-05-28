#include "authorization.h"
#include "singleton.h"
#include <QApplication>
#include <QDialog>
#include <QString>
#include <QDebug>
#include <QSettings>
#include <QQuickStyle>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile styleFile(":/styles/orange.qss");
    styleFile.open( QFile::ReadOnly );
    QString style(styleFile.readAll());
    app.setStyleSheet(style);

    authorization window;
    window.show();
    return app.exec();
}
