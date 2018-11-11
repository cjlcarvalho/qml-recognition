#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>

class ImageProcessor : public QObject
{
    Q_OBJECT
public:
    explicit ImageProcessor(QObject *parent = nullptr);
    Q_INVOKABLE void processImage(const QString& path);

signals:
    void imageProcessed(const QImage& image);
};

#endif // IMAGEPROCESSOR_H
