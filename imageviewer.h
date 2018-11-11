#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QPainter>
#include <QQuickPaintedItem>

class ImageViewer : public QQuickPaintedItem
{
    Q_OBJECT
public:
    ImageViewer(QQuickItem *parent = nullptr);

    Q_INVOKABLE void setImage(const QImage& image);

private:
    void paint(QPainter *painter);

private:
    QImage currentImage;
};

#endif // IMAGEVIEWER_H
