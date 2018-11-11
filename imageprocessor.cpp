#include "imageprocessor.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>

#include <QImage>

ImageProcessor::ImageProcessor(QObject *parent) : QObject(parent)
{

}

void ImageProcessor::processImage(const QString& path)
{
    cv::Mat im = cv::imread(path.toStdString());

    cv::Mat grey;

    if (!im.empty())
    {
        cv::cvtColor(im, grey, cv::COLOR_BGR2GRAY);
        cv::CascadeClassifier fCascade("/home/caio/recognition/haarcascade_frontalface_default.xml");

        std::vector<cv::Rect> faces;

        fCascade.detectMultiScale(grey, faces, 1.3, 5);

        for (cv::Rect &face : faces)
            cv::rectangle(im, face, cv::Scalar(255, 0, 0), 2);

        cv::cvtColor(im, im, cv::COLOR_BGR2RGB);

        QImage resultedImage(im.data, im.cols, im.rows, im.step, QImage::Format::Format_RGB888);

        emit imageProcessed(resultedImage);
    }
}
