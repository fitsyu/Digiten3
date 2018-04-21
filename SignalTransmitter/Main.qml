import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.3

Window {
    id: rootWindow
    visible: true
    visibility: "AutomaticVisibility"
    width: Qt.platform.os==="android"?Screen.width:540
    height: Qt.platform.os==="android"?Screen.height:960

    color: Qt.darker("#000000") // what is darker than black? my lost soul

    function readMsg(msg){
        status_text.text = msg
    }

    Image {
        source: "qrc:/img/DigitenLogo.png"

//        anchors.fill: parent

        width: parent.width //* 0.75
        height: parent.height * 0.1

        anchors{
            bottom: parent.bottom
        }
    }

//    Image {
//        id: pbar
//        anchors.top: parent.top
//        anchors.right: parent.right
//        source: "/img/fan.png"
//        visible: false
//        smooth: true
//        scale: 1/2.0
//    }

//    RotationAnimation {
//        id: spin
//        target: pbar
//        from: 0
//        to: 360
//        duration: 1000
//        loops: Animation.Infinite
//        running: false
//        onStarted: pbar.visible = true
//        onStopped: pbar.visible = false
//    }



    Column {
//        anchors.centerIn: parent
        anchors.horizontalCenter: parent.horizontalCenter

        spacing: 10
//        FricButton {
//            id: btConnect
//            anchors.horizontalCenter: parent.horizontalCenter
////            _text: "connect"
//            opacity: 0.6
//            width: 150
//            height: width
//            onKepencet: {
//                Transmitter.discover()
//                spin.start()
//            }
//        }


        Row{
            spacing: 10

            anchors.right: parent.right

            Button{
                id: accTogle

                width: rootWindow.width * 0.15

                checkable: true

                onCheckedChanged: {
                    if (checked){
//                        Transmitter.startService()
//                        text: "aclmtr: ON"
                        Transmitter.startSendcompassData()
                        text: "compss: ON"

                    } else {
//                        Transmitter.stopService()
//                        text: "aclmtr: OFF"
                        Transmitter.stopSendcompassData()
                        text: "compss: OFF"
                    }
                }
            }

            Text{
                id: hostNameText
                text: "Connected to: "
                color: "white"

                font.pointSize: 12

                anchors.verticalCenter: parent.verticalCenter
            }

            Button{
                id: btDisconnect
                text: "disconnect"

                onClicked: {
                    hostNameText.text = "disconnected"

//                    Transmitter.disconnectFromServer() // bluetooth
//                    wizard.visible = true
//                    wizard.reset()
                    Transmitter.disconnectFromWifiServer() // WiFi
                }
            }
        }

        Text {
            id: status_text
            color: "#2267b5"
            objectName: "connection_status"
            text: "process status "

            font.pointSize: 12

//            onTextChanged: {
//                spin.stop()
//    //            y = -10
//            }


            property int staticY
            Component.onCompleted: {
                staticY = y
            }

            Behavior on text {
                NumberAnimation {
                    target: status_text
                    property: "y"
                    from: -5
                    to: status_text.staticY
                    duration: 2000
                    easing.type: "OutElastic"
                }
            }

        }

        Rectangle {
            id: buttonsGroup1
            width: rootWindow.width * 0.9
            height: rootWindow.height * 0.25
            color: "black" //"lightblue"
            border.color : "#149bc4"
            border.width: 4
            radius: 15
            opacity: 0.6

            Row {
                anchors.centerIn: parent
                spacing: 10
                FricButton {
                    width: buttonsGroup1.width / 5
                    height: width
                    aura: "red"
                    logoSource: "qrc:/img/bt_A.png"

                    onKepencet: { Transmitter.clickButton(0); }
                }
                FricButton {
                    width: buttonsGroup1.width / 5
                    height: width

                    aura: "orange"
                    logoSource: "qrc:/img/bt_B.png"

                    onKepencet: Transmitter.clickButton(1)
                }
                FricButton {
                    width: buttonsGroup1.width / 5
                    height: width

                    aura: "blue"
                    logoSource: "qrc:/img/bt_C.png"

                    onKepencet: Transmitter.clickButton(2)
                }
                FricButton {
                    width: buttonsGroup1.width / 5
                    height: width

                    aura: "darkgreen"
                    logoSource: "qrc:/img/bt_D.png"


                    onKepencet: Transmitter.clickButton(3)

                }
            }
        }

        Rectangle {
            id: buttonsGroup2
            width: rootWindow.width * 0.9
            height: rootWindow.height * 0.60
            color: "black"//"lightblue"
            border.color : "#149bc4"
            border.width: 4
            radius: 15
            opacity: 0.6

            NavigationButtons{
                anchors.centerIn: parent
                width  : parent.width * 0.75
                height : width

                onGoUp   : Transmitter.clickButton(4)
                onGoDown : Transmitter.clickButton(5)
                onGoLeft : Transmitter.clickButton(6)
                onGoRight: Transmitter.clickButton(7)
            }
        }

//        Row {
//            anchors.horizontalCenter: parent.horizontalCenter
//            spacing: 20
//            Text {
//                color: "white"
//                text : "accelerometer"
//                font.pointSize: Qt.platform.os==="android"?20:12
//                font.family: "Ubuntu"
//            }
//            Switch {
//                onCheckedChanged: {
//                    if (checked) Transmitter.toggleAccelerometer()
//                }
//            }
//        }
    }

//    onClosing: {
//        closeConfirmDialog.visible = true
//        close.accepted = false
//    }
//    MessageDialog {
//        id: closeConfirmDialog
//        text: "Wait!\nAre you sure?"
//        standardButtons:  StandardButton.Ok | StandardButton.Cancel
//        onAccepted: Qt.quit()

//    }

    function addNewHostFound( address ){
        wizard.addNewHostFound(address)
    }

    // called from cpp after successfull connection to server
    function setConnectedDeviceName( btDeviceName ){
        hostNameText.text = "Connected to: "+btDeviceName
        // stop search

        wizard.close()

    }


    WifiConnectionSetup{
        id: wizard
    }

    function setSocketState(s){
        wizard.setSocketState(s)
    }

    function showWifiConnectionSetup(){
        wizard.visible = true
    }

    function hideWifiConnectionSetup(){
        wizard.visible = false
    }

//    ConnectionSetup{
//        id: wizard


//        onConnected: {
//            visible = false
//            hostNameText.text = "Connected to: "+tgt
//        }
//    }

}
