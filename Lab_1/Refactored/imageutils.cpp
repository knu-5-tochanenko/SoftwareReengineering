#include "imageutils.h"

#include <QLabel>
#include <QPixmap>

ImageUtils::ImageUtils()
{

}

void ImageUtils::bindImage(const char *imageSource, QGridLayout *object, int w, int h)
{
    QPixmap pixmap(imageSource);
    pixmap = pixmap.scaled(w, h, Qt::KeepAspectRatio);
    QLabel *labelScore = new QLabel;
    labelScore->setPixmap(pixmap);
    object->addWidget(labelScore, 0, 0);
}

void ImageUtils::bindImage(QString imageSource, QGridLayout *object, int w, int h)
{
    bindImage(imageSource.toLocal8Bit().data(), object, w, h);
}
