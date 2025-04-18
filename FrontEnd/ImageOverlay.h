#ifndef IMAGEOVERLAY_H
#define IMAGEOVERLAY_H

#include <QImage>
#include <QColor>

class ImageOverlay {
    public:
        static QImage applyOverlay(const QImage &image, const QColor &overlay);
};

#endif