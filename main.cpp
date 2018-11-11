#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "imageprocessor.h"
#include "imageviewer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<ImageProcessor>("com.caio.classes", 1, 0, "ImageProcessor");
    qmlRegisterType<ImageViewer>("com.caio.classes", 1, 0, "ImageViewer");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
