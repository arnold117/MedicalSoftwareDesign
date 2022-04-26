import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import an.qt.mySerialPort 1.0

Window {
    MySerialPort{
        id:serialport;
    }

    width: 640
    height: 480
    visible: true
    title: qsTr("Arnold‘s qml Serial Assistant")

    GridLayout{
       id:grid
       anchors.verticalCenter: parent.verticalCenter;
       anchors.left: parent.left;
       anchors.leftMargin: 10;

       rows:6;
       rowSpacing: 5;
       columns: 2;
       columnSpacing: 5

       Label{
           text:qsTr("串口")
       }
       ComboBox{
           id:port;
           model: ["COM1","COM2","COM3"];
       }

       Label{
           text:qsTr("波特率")
       }
       ComboBox{
           id:baudrate;
           model: ["4800","9600","115200"];
       }

       Label{
           text:qsTr("数据位")
       }
       ComboBox{
           id:databits
           model: ["6","7","8"];
       }

       Label{
           text:qsTr("校验位")
       }
       ComboBox{
           id:parity
           model: ["0","2","3"];
       }

       Label{
           text:qsTr("停止位")
       }
       ComboBox{
           id:stopbits
           model: ["1","2","3"];
       }

       Button{
           text: qsTr("打开串口")
           highlighted: true
           Layout.columnSpan: 2;
           onClicked: {
               serialport.serialConnect(port.currentText,baudrate.currentText,
                  databits.currentText,parity.currentText,stopbits.currentText);
           }
       }
    }

    ColumnLayout{
        anchors.left: grid.right
        anchors.leftMargin: 60;
        anchors.verticalCenter: parent.verticalCenter
        spacing: 5
        TextArea{
            id:receive;
            Layout.preferredWidth: 200;
            Layout.preferredHeight: 200;
            text: qsTr("Receive:")
            readOnly: true;
            background: Rectangle{
                color: "gray"
            }
        }
        Button{
            text: qsTr("接收数据")
            highlighted: true;
            onClicked: {
                receive.append(serialport.serialRead());
            }
        }

        TextField{
            id:send;
            Layout.preferredWidth: 200
        }

        Button{
            text:qsTr("发送数据")
            highlighted: true
            onClicked: {
                serialport.serialWrite(send.text)
            }
        }
    }
}
