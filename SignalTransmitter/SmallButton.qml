import QtQuick 2.0

Rectangle {
    property string _text
    signal kepencet

    width: Qt.platform.os==="android"?100:40
    height: Qt.platform.os==="android"?100:40
    color: "#312d2d"
    border.color: "white"
    border.width: Qt.platform.os==="android"?6:3
    radius: Qt.platform.os==="android"?20:10

    Text {
        color: "white"
        anchors.centerIn: parent
        text: _text;
        font.family: "Ubuntu"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: Qt.platform.os==="android"?20:14

        onTextChanged: {
            if (text.length > 3){
                parent.width =  text.length*font.pointSize + 5
            }
        }
    }

    MouseArea {
        id: ma
        anchors.fill: parent
        onClicked: {
            kepencet()
            pencet.start()
        }


    }

    id: _rect
    SequentialAnimation{
        id: pencet
        NumberAnimation {

            target: _rect
            property: "scale"
            duration: 200
            to: .75
        }
        NumberAnimation {
            target: _rect
            property: "scale"
            duration: 100
            to: 1
        }
    }



}

