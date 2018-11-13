import QtQuick 2.0

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

        //If we add this 5th Rectangle to our 2x2 grid, it will overlap the 1st item (the magenta coloured Rectangle)
        //Rectangle{ color: "orange"; width: 50; height: 50; }
    }

}
