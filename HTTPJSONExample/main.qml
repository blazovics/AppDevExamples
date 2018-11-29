import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    width: 640
    height: 480
    visible: true

    title: qsTr("Messages");

    ListView{
        anchors.fill: parent
        anchors.margins: 10
        spacing: 5
        model: myModel
        delegate:
            Rectangle{
                color: "lightGray"
                width: 620
                height: 70

                Column{
                    spacing: 5
                    Text{
                        text: "From: " + fromUser
                    }
                    Text{
                        text: "To: " + toUser
                    }
                    Text{
                        text: "Topic: " + topic
                    }
                    Text{
                        text: "Content: " + content
                    }
                }
            }
    }

}
