import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtCharts 6.2

import FileIO 1.0

Window {
    width: 740
    height: 480
    visible: true
    title: qsTr("Arnold's Wave Drawer")

    property int timer: 0

    FileIO {
           id: myFile
           source: "心电演示数据.csv"
       }

    Button {
        id: loadButton
        x: 627
        y: 430
        text: qsTr("加载数据")
        onClicked: {
            for (var sig in myFile.read())
            {
                waveTextArea.append(sig)
            }
        }
    }

    Button {
        id: saveButton
        x: 627
        y: 377
        text: qsTr("存储数据")
        onClicked: {
            myFile.write(waveTextArea.getText(0, 2047))
        }
    }

    RadioButton {
        id: radioButton
        x: 627
        y: 71
        text: "静态显示"
        checkable: false
    }

    RadioButton {
        id: radioButton1
        x: 627
        y: 100
        text: qsTr("动态显示")
        checked: true
    }

    TextArea {
        id: waveTextArea
        x: 22
        y: 305
        width: 591
        height: 165
        placeholderText: qsTr("Wave Data")
        background: Rectangle{
            color: "gray"
        }
    }

    ChartView {
        id: waveChartView
        x: 22
        y: 36
        width: 591
        height: 264
        antialiasing: true
        backgroundColor: "#9917719b"
        animationOptions: ChartView.SeriesAnimations
        legend.visible:false

        ValueAxis {
                 id: myAxisX
                 min: 0
                 max: 100
                 tickCount: 11
                 labelsColor: "#ffffff"
                 labelsFont.pointSize: 13
                 labelsFont.bold: true
                 labelFormat: '%d'
             }
        ValueAxis{
            id:myAxisY
            min:0
            max:50
            tickCount: 6
            labelsColor: "#ffffff"
            labelsFont.pointSize: 13
            labelsFont.bold: true
            labelFormat: '%d'
        }

        LineSeries {
            id:lineSeries
            name: "LineSeries"
            axisX: myAxisX
            axisY:myAxisY
            color: "#00ffff"
            width: 3
        }


    }

    Timer{
        interval: 10
        running: true
        repeat: true
        onTriggered: {
            lineSeries.append(timer,Math.random()*50)
            if (timer > 100)
            {
                timer = 0
                lineSeries.clear()
            }
            else
            {
                timer += 1
            }
        }
    }

}
