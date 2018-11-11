import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import com.caio.classes 1.0

Window {
    visible: true
    width: 640
    height: 480

    Camera
    {
        id: camera
        imageCapture
        {
            onImageSaved:
            {
                imgProcessor.processImage(path)
            }
        }
    }

    ImageProcessor
    {
        id: imgProcessor
        onImageProcessed:
        {
            imgViewer.setImage(image);
            imageDrawer.open()
        }
    }

    Drawer
    {
        id: imageDrawer
        width: parent.width
        height: parent.height
        ImageViewer
        {
            id: imgViewer
            anchors.fill: parent
            Label
            {
                text: "Swipe to right or left<br> to return to capture!"
                color: "red"
            }
        }
    }

    VideoOutput
    {
        source: camera
        anchors.fill: parent
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                camera.imageCapture.capture()
            }
        }
        Label
        {
            text: "Take photo"
            color: "red"
        }
    }
}
