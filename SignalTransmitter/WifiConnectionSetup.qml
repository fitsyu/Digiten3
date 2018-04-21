import QtQuick 2.4
import QtQuick.Controls 1.3

Rectangle {
    id: baseRect
    anchors.fill: parent
    color: "black"
    opacity: 0.75

    function setSocketState(state){
        txSocketState.text = state
    }

    MouseArea{
        id: blocker
        anchors.fill: parent
    }

    Column{
        anchors.centerIn: parent
        spacing: 15


        TextField{
            id: txServerAddress
            placeholderText: "server ip address"

            inputMethodHints: Qt.ImhDigitsOnly

            text: "10.42.0.1"
            textColor: "white"

            font.pointSize: 16

            width: baseRect.width * 0.6
            height: baseRect.height * 0.08

            anchors.horizontalCenter: parent.horizontalCenter
        }

        TextField{
            id: txServerPort
            placeholderText: "port number"

            inputMethodHints: Qt.ImhDigitsOnly

            text: "2015"
            textColor: "white"

            font.pointSize: 16

            width: baseRect.width * 0.6
            height: baseRect.height * 0.08

            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button{
            id: btConnect

            text: "connect"

            width: baseRect.width * 0.5
            height: baseRect.height * 0.18

            onClicked: {
                Transmitter.connectTo(txServerAddress.text, +txServerPort.text)
            }

            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row{
            spacing: 8
            Text{
                id: txSocketState
                color: "white"

                text: "disconnected"
                font.pointSize: 12

                anchors.verticalCenter: parent.verticalCenter

            }

            BusyIndicator{
                id: loadingIcon

                visible: txSocketState.text == "connecting.."

                anchors.verticalCenter: parent.verticalCenter
            }

            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

}

