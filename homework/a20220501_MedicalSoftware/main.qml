import QtQuick 2.0
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 600
    title: qsTr("MedicalSoftware")
    property int i :0

    StackView {
        id: stack
        initialItem: mainView
        anchors.fill: parent
    }


    function showMsg(title, text) {
        messageDialog.title = title;
        messageDialog.text = text;
        messageDialog.visible = true;
    }
    function handleStartProgressBar() {
        progressBar.visible = true;
        progressBar.start();
    }
    function handleSignalLoginResult(result)
    {
        progressBar.setProgressValue(100);
        if (result)
        {
            loginpage.visible = false;
            mainwld.windowTitle = 'QML演示系统';
        }
        else
        {
            showMsg('提示', '账号或密码不正确！');
        }
    }
    function handleSignalMeaasge(msg)
    {
        progressBar.setProgressValue(100);
        showMsg('提示', msg);
    }
    Connections
    {
        target: datacls
        onSignalLoginResult: handleSignalLoginResult(result)
        onSignalMeaasge: handleSignalMeaasge(msg)
    }
    Timer {
        id: timeUpdate
        interval: 1000; running: true; repeat: true
        onTriggered: {
            //console.log(Qt.formatDateTime(new Date(), "dddd hh:mm:ss"), new Date().getDay());
            labelTime.text = Qt.formatDateTime(new Date(), "dddd hh:mm:ss");
        }
    }

    Page {
        id: mainView

        Button {
            id: search_button
            x: 295
            y: 31
            width: 75
            height: 25
            text: qsTr("搜索")
            topPadding: 2

        }

        TextField {
            id: textField
            x: 134
            y: 31
            height: 25
            placeholderText: qsTr("请输入关键词")
            onEditingFinished: {
                if (textInput.focus) {
                    tablemodelid.getData(['search'], [textInput.text]);
                    progressBar.visible = true;
                    progressBar.start();
                }
                textInput.focus = false;
            }
        }

        ComboBox {
            id: comboBox
            x: 28
            y: 31
            width: 75
            height: 25
            model: ListModel{
                id: combo
                ListElement {
                    text: "姓名"
                }
                ListElement {
                    text: "性别"
                }
                ListElement {
                    text: "出生日期"
                }
                ListElement {
                    text: "居住地址"
                }
                ListElement {
                    text: "联系电话"
                }
            }
        }

        Button {
            id: add_button
            x: 549
            y: 31
            width: 75
            height: 25
            text: qsTr("添加记录")
            topPadding: 2
            onClicked: {
                pass(id.selected());
                page_add.visible =true;
                page_add.stack = stack;
                stack.push(page_add)
            }
        }

        Button {
            id: edit_button
            x: 549
            y: 68
            width: 75
            height: 25
            text: qsTr("修改记录")
            topPadding: 2
            onClicked: {
                page_edit.visible =true;
                page_edit.stack = stack;
                stack.push(page_edit)
            }
        }

        Button {
            id: rx_button
            x: 549
            y: 105
            width: 75
            height: 25
            text: qsTr("处方")
            topPadding: 2
            onClicked: {
                page_rx.visible =true;
                page_rx.stack = stack;
                stack.push(page_rx)
            }
        }

        Button {
            id: delete_button
            x: 549
            y: 142
            width: 75
            height: 25
            text: qsTr("删除记录")
        }

        Button {
            id: undo_button
            x: 549
            y: 179
            width: 75
            height: 25
            text: qsTr("撤销操作")
        }

        Rectangle {
            x: 28
            y: 68
            width: 492; height: 475

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

                model: UserTableModel {
                    id: tablemodelid

                    onSignalRecvhandleResult: {
                        progressBar.setProgressValue(100);
                    }
                }

                Component.onCompleted: {
                    tablemodelid.getData(all);
                }
            }
        }

    }
    Add{
        id:page_add
        visible: false
    }

    Edit{
        id:page_edit
        visible: false
    }

    Rx{
        id:page_rx
        visible: false
    }

}
