import QtQuick 2.0

Rectangle{
    width: 320
    height: 110
    color: "lightgrey"

    Row{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        spacing: 5

        Rectangle{
            width: 100; height: 100; radius: 20.0
            color: "red"
        }
        Rectangle{
            width: 100; height: 100; radius: 20.0
            color: "green"
        }
        Rectangle{
            width: 100; height: 100; radius: 20.0
            color: "blue"
        }
    }
}
