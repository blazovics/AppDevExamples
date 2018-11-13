import QtQuick 2.0

Rectangle{
    width: 310
    height: 170
    color:"#ececec"

    Column{

        anchors.centerIn: parent

        spacing: 5

        Rectangle {
            color: "lightblue"
            radius: 10.0
            clip: true
            width: 300
            height: 50
            Text {
                font.pointSize: 24
                text: "Books"
                anchors.centerIn: parent
            }
        }

        Rectangle {
            color: "gold"
            radius: 10.0
            clip: true
            width: 300
            height: 50
            Text {
                font.pointSize: 24
                text: "Music"
                anchors.centerIn: parent
            }
        }

        Rectangle {
            color: "lightgreen"
            radius: 10.0
            clip: true
            width: 300
            height: 50
            Text {
                font.pointSize: 24
                text: "Movies"
                anchors.centerIn: parent
            }
        }
    }
}
