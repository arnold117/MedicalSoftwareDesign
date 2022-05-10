import QtQuick 2.0
import QtQuick.Controls 2.15

Page {

    id: editWindow
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

    Text {
        id: text1
        x: 230
        y: 37
        text: qsTr("你将修改以下记录：")
        font.pixelSize: 20
    }

    Text {
        id: text2
        x: 190
        y: 147
        text: qsTr("姓名：")
        font.pixelSize: 20
    }

    Text {
        id: text3
        x: 190
        y: 187
        text: qsTr("性别：")
        font.pixelSize: 20
    }

    Text {
        id: text4
        x: 150
        y: 227
        text: qsTr("出生日期：")
        font.pixelSize: 20
    }

    Text {
        id: text5
        x: 150
        y: 267
        text: qsTr("居住地址：")
        font.pixelSize: 20
    }

    Text {
        id: text6
        x: 150
        y: 307
        text: qsTr("联系电话：")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 276
        y: 420
        text: qsTr("确认修改")
        font.pixelSize: 20
        onClicked: stack.pop()
    }

    TextField {
        id: name_field
        x: 256
        y: 147
        width: 200
        placeholderText: qsTr("张三")
        font.pixelSize: 20
    }

    TextField {
        id: gender_field
        x: 256
        y: 187
        width: 200
        placeholderText: qsTr("男")
        font.pixelSize: 20
    }

    TextField {
        id: birth_field
        x: 256
        y: 227
        width: 200
        placeholderText: qsTr("1957/3/23")
        font.pixelSize: 20
    }

    TextField {
        id: address_field
        x: 256
        y: 267
        width: 200
        placeholderText: qsTr("南昌")
        font.pixelSize: 20
    }

    TextField {
        id: phone_field
        x: 256
        y: 307
        width: 200
        placeholderText: qsTr("555 3264")
        font.pixelSize: 20
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
