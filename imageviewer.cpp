#include "imageviewer.h"

ImageViewer::ImageViewer(QQuickItem* parent) :
    QQuickPaintedItem(parent)
{

}

void ImageViewer::setImage(const QImage& image)
{
    currentImage = image.copy();
    update();
}

void ImageViewer::paint(QPainter* painter)
{
    QSizeF scaled = QSizeF(currentImage.width(), currentImage.height())
                    .scaled(boundingRect().size(), Qt::KeepAspectRatio);

    QRect center(qAbs(scaled.width() - width()) / 2.0,
                 qAbs(scaled.height() - height()) / 2.0,
                 scaled.width(), scaled.height());

    painter->drawImage(center, currentImage);
}
