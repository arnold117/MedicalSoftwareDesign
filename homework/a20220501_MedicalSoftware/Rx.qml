import QtQuick 2.0
import QtQuick.Controls 2.15

Page {

    id: rxWindow
    visible: true

    property StackView stack: null

    Button {

        height: 25
        width: 75
        text: "<-"
        anchors.left: parent.left
        anchors.top: parent.top
        flat: false
        onClicked: stack.pop()

    }

    Rectangle {
        x: 24
        y: 39
        width: 492; height: 50

        Component {
            id: contactDelegate
            Item {
                width: 492; height: 21
                Row {
                    spacing: 1
                    Rectangle {
                        width: 20
                        height: 20
                        color: "lightsteelblue"
                        border.width: 1
                        Text { text: num ;font.pointSize: 12 }
                    }

                    Rectangle{
                        width: 80
                        height: 20
                        color: "#00ffffff"
                        border.width: 1
                        Text { text: name ;font.pointSize: 12 }
                    }

                    Rectangle{
                        width: 100
                        height: 20
                        color: "lightsteelblue"
                        border.width: 1
                        Text { text: birth ;font.pointSize: 12 }
                    }

                    Rectangle{
                        width: 120
                        height: 20
                        color: "#00ffffff"
                        border.width: 1
                        Text { text: address ;font.pointSize: 12 }
                    }

                    Rectangle{
                        width: 100
                        height: 20
                        color: "lightsteelblue"
                        border.width: 1
                        Text { text: number ;font.pointSize: 12 }
                    }
                }
            }
        }

        Row {
            anchors.fill: parent
            anchors.bottomMargin: 450

            spacing: 1
            Rectangle {
                width: 20
                height: 20
                color: "lightsteelblue"
                border.width: 0
                Text { text: "#" ;font.pointSize: 12 }
            }

            Rectangle{
                width: 80
                height: 20
                color: "#00ffffff"
                border.width: 0
                Text { text: "姓名" ;font.pointSize: 12 }
            }

            Rectangle{
                width: 100
                height: 20
                color: "lightsteelblue"
                border.width: 0
                Text { text: "出生日期" ;font.pointSize: 12 }
            }

            Rectangle{
                width: 120
                height: 20
                color: "#00ffffff"
                border.width: 0
                Text { text: "居住地址" ;font.pointSize: 12 }
            }

            Rectangle{
                width: 100
                height: 20
                color: "lightsteelblue"
                border.width: 0
                Text { text: "联系电话" ; font.pointSize: 12 }
            }
        }

        ListView {
            anchors.fill: parent
            anchors.topMargin: 26
            delegate: contactDelegate
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
            model:UserTableModel {
                id: tablemodelid

                onSignalRecvhandleResult: {
                    progressBar.setProgressValue(100);
                }
            }

            Component.onCompleted: {
                tablemodelid.getData(passed.get_id());
            }
        }
    }

    Rectangle {
        x: 24
        y: 95
        width: 492
        height: 183
        ListView {
            id: listView
            anchors.fill: parent
            delegate: Item {
                x: 5
                width: 80
                height: 40

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 12
                }
            }
            model:UserTableModel {
                id: med

                onSignalRecvhandleResult: {
                    progressBar.setProgressValue(100);
                }
            }

            Component.onCompleted: {
                med.getData(obdc='medic', passed.get_id());
            }
        }
    }



    TextArea {
        id: textArea
        x: 24
        y: 293
        width: 492
        height: 157
        placeholderText: qsTr("在此处添加处方")
    }

    Button {
        id: edit_rx_button
        x: 534
        y: 95
        width: 75
        height: 25
        text: qsTr("修改处方")
        onClicked: {
            med.drop(id.selected())
            med.append(['rx'], [textArea.getFormattedText()])
        }
    }

    Button {
        id: del_rx_button
        x: 534
        y: 132
        width: 75
        height: 25
        text: qsTr("删除处方")
        onClicked: med.drop(id.selected())
    }

    Button {
        id: add_rx_button
        x: 534
        y: 293
        width: 75
        height: 25
        text: qsTr("添加处方")
        onClicked: med.append(['rx'], [textArea.getFormattedText()])
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:42}D{i:43}
}
##^##*/
