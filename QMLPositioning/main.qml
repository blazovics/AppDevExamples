import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    //Set the visible property of the two GridLayout to see that both "solutions" are identical.

    //Basic solution. All content have been pleced into one Layout
    GridLayout{
        visible: false
        anchors.fill: parent
        columns: 3

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

        Rectangle{

            width: 112;
            //Binding: the 'height' will be equal to the 'width'
            height: width

            color:"pink"

            Grid
            {
                columns: 2
                rows: 2
                anchors.centerIn: parent

                Rectangle{ color: "magenta"; width: 50; height: 50}
                Rectangle{ color: "cyan"; width: 50; height: 50}
                Rectangle{ color: "yellow"; width: 50; height: 50}
                Rectangle{ color: "black"; width: 50; height: 50}

                //Rectangle{ color: "orange"; width: 50; height: 50; }
            }

        }

        Rectangle {

            color: "lightblue"
            width: 420; height: 163

            Flow {

                //width: 300; height: 200
                anchors.fill: parent
                spacing: 10

                Text{text:"Text"; font.pixelSize: 40}
                Text{text:"items"; font.pixelSize: 40}
                Text{text:"flowing"; font.pixelSize: 40}
                Text{text:"inside"; font.pixelSize: 40}

                Text{text:"a"; font.pixelSize: 40}
                Text{text:"Flow"; font.pixelSize: 40}
                Text{text:"item"; font.pixelSize: 40}
            }
        }

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

    }

    //More compact solution. The content of each Item have been placed to separated .qml files
    GridLayout{
        anchors.fill: parent
        columns: 3

        MyColumn{

        }
        MyRow{

        }
        MyGrid{

        }
        MyFlow{

        }
        MyAnchors{

        }
        MyAnchors2{

        }
    }
}
