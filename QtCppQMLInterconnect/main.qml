import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        anchors.centerIn: parent
        Text{
            //id is used for visual hierarchy
            id:textId
            //This is used by the findChild function
            objectName: "myText"
            text: qsTr("Hello There!")
        }
        Text {
            objectName: "secondaryText"
            text: qsTr("This will change by function")

            function setSecondaryText(newText)
            {
                text = newText
            }
        }
        Button{
            objectName: "myButton"
            text: "Click Me!"
            id: btn1
            function updateButtonTitle(variant)
            {
                text = variant
            }
        }
        Text{
            text: "No Demo?"
            id: demoText
        }
        Text{
            text: myCntxMember.title
        }
        Row{
            TextInput{
                id: titleText
                width: 100
            }
            Button{
                text: "Overwrite Title"
                onClicked: {
                    myCntxMember.setTitle(titleText.text)
                }
            }
        }
    }

    /*
     * Special object used for handling signals of the objects
     * located in the current context
     */
    Connections{
        target: myCntxMember
        onDemoSignal:{
            demoText.text = "Demo handled"
        }
    }
}
