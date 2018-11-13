import QtQuick 2.0

Rectangle{
    width: 370
    height: 110
    color: "yellow"

    Rectangle{
        id: rect1
        width: 100
        height: 100
        color: "red"
    }

    Rectangle{
        id: rect2
        color: "green"
        anchors.left: rect1.right
        anchors.right: rect3.left
        anchors.bottom: rect1.bottom
        anchors.top: rect1.top

        anchors.margins: 5

    }
    Rectangle{
        id: rect3
        x:260
        width: 100
        height: 100
        color: "blue"
    }
}
