#ifndef IMAGEUTILS_H
#define IMAGEUTILS_H

#include <typeinfo>

#include <QLayout>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QHBoxLayout>


class ImageUtils
{
public:
    ImageUtils();

    template<class T>
    static void bindImage(const char* imageSource, T* object, int w, int h)
    {
        QPixmap pixmap(imageSource);
        pixmap = pixmap.scaled(w, h, Qt::KeepAspectRatio);
        bindPixmap(pixmap, object);
    }

    template<class T>
    static void bindImage(QString imageSource, T* object, int w, int h)
    {
        bindImage(imageSource.toLocal8Bit().data(), object, w, h);
    }

    template<class T>
    static void bindPixmap(QPixmap pixmap, T* object)
    {
        QLabel *labelScore = new QLabel;
        labelScore->setPixmap(pixmap);
        if (typeid(object) == typeid(QGridLayout*))
        {
            dynamic_cast<QGridLayout*>(object)->addWidget(labelScore, 0, 0);
        }
        else if (typeid(object) == typeid(QBoxLayout*))
        {
            dynamic_cast<QBoxLayout*>(object)->addWidget(labelScore);
        }
    }
};

#endif // IMAGEUTILS_H
