#ifndef IMAGEUTILS_H
#define IMAGEUTILS_H

#include <QGridLayout>


class ImageUtils
{
public:
    ImageUtils();

    static void bindImage(const char* imageSource, QGridLayout* object, int w, int h);
    static void bindImage(QString imageSource, QGridLayout* object, int w, int h);
};

#endif // IMAGEUTILS_H
