import QtQuick 2.9
import QtQuick.Window 2.2

import QtCharts 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Connections{
        target:sinSource
        onNewSinData:{
            generatedSeries.append(x,y);

            if(x > xAxis.max)
            {
                xAxis.max = x;
            }
        }
    }

    Connections{
        target: burstData
        onDataReady: {
            burstData.dataItems.forEach(function(element){
                burstSeries.append(element.x, element.y);
                if(element.x > xAxis.max)
                {
                    xAxis.max = element.x;
                }
            });
        }
    }

    ChartView{
        anchors.fill: parent

        /*
        LineSeries{
            visible: true
            axisX: xAxis

            color: "red"

            name: "Static Series"
            XYPoint{
                x: 0
                y: 0
            }
            XYPoint{
                x: 1.0
                y: 1.0
            }
            XYPoint{
                x: 2.0
                y: 0.5
            }
            XYPoint{
                x: 3.0
                y: 1.1
            }
        }*/

        LineSeries{
            name: "Generated Sine"
            id: generatedSeries
            axisX: xAxis
            axisY: yAxis
        }

        LineSeries{
            name: "Burst Generated Cosine"
            id: burstSeries
            axisX: xAxis
            axisY: yAxis
        }
    }

    ValueAxis{
        id: xAxis
        min: 0.0
        max: 1.0
    }

    ValueAxis{
        id: yAxis
        min: -1.1
        max: 1.1
    }
}
