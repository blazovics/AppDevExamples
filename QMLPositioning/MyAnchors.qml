import QtQuick 2.0

Rectangle{

    width: 220
    height: 220
    color: "lightgray"

    Rectangle{
        id: redRect

        width: 100
        height: 100
        color: "red"

        //anchors.rightMargin: 15
        //anchors.right: blueRect.left
    }

    Rectangle{
        id: blueRect
        width: 100
        height: 100
        color: "blue"

        anchors.left: redRect.right
        anchors.top: redRect.bottom
        //anchors.leftMargin: 15
    }

}
