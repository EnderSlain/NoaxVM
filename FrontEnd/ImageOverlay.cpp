#include "ImageOverlay.h"
#include <QPainter>
#include <QImageReader>

QImage ImageOverlay::applyOverlay(const QImage &image, const QColor &overlay) {
    QImage overlayImage = image.copy();
    QPainter painter(&overlayImage);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QColor pixelColor = image.pixelColor(x, y);
            
            if (pixelColor.alpha() > 0) {
                QColor newColor = overlay;
                newColor.setAlpha(pixelColor.alpha());
                painter.setPen(newColor);
                painter.drawPoint(x, y);
            }
        }
    }
    
    painter.end();
    return overlayImage;
}
