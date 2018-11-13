import QtQuick 2.0

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
