import QtQuick 2.4
import QtQuick.Controls 1.3
//import QtQuick.Particles 2.0

Rectangle {
    id: setupRect
    anchors.fill: parent


    color: "black"
    opacity: 0.85

    // press connect
    // search for host
    // list found hosts
    // choose
    // connect to host
    // connected?
    // y -> hide this setup
    // n -> search again?
    //          y -> go to step 2
    //          n -> don't do anything stay like this


    signal connected(var tgt)

    MouseArea{
        anchors.fill: parent
    }

    Column{
        anchors.centerIn: parent

        spacing: 15

        FricButton{
            id: btConnect

            logoSource: "qrc:/img/search.png"

            width: setupRect.width * 0.25
            height: width

            z: 2

//            anchors.centerIn: setupRect
            anchors.horizontalCenter: parent.horizontalCenter

            onKepencet: {
                emitter.enabled = !emitter.enabled

                Transmitter.discover()
                reset()

                // simulation
//                hostFoundTimer.start()
            }




        }

        Text{
            id: instructionText
            z: 2
            width: setupRect.width * 0.8

            font.pointSize: 14

            text: emitter.enabled?"Searching for Digiten host..\n\nTap again to stop the search"
                                 :"Tap to search for Digiten host"
            color: "white"

            anchors.horizontalCenter: parent.horizontalCenter

            horizontalAlignment: Text.AlignHCenter
        }

        BusyIndicator{
            z: 0
            running: emitter.enabled
            visible: running

            width: btConnect.width //* 0.5
            height: width

            anchors.horizontalCenter: parent.horizontalCenter

        }

        ListView{
            width: setupRect.width * 0.8
            height: setupRect.height * 0.6

            visible: model.count

            model: hostModel
            delegate: Rectangle{
                id: hostTarget
                width: setupRect.width * 0.8
                height: setupRect.height * 0.15

                color: Qt.darker("grey")
                opacity: 0.88

                Text{
                    id: hostNameText
                    color: "white"
                    anchors.centerIn: hostTarget
                    text: hostName
                }

                MouseArea{
                    anchors.fill: hostTarget
                    onClicked: {
//                        connected(hostNameText.text)
//                        console.log("connect to..")
                        Transmitter.tryConnectingToDigitenServer(hostNameText.text)
                        hostTarget.color = Qt.lighter(hostTarget.color)
                    }

//                    onPressed: {
//                        hostTarget.color = Qt.lighter(hostTarget.color)
//                    }

//                    onReleased: {
//                        hostTarget.color = Qt.darker("grey")
//                    }


                }
            }

            spacing: 10


        }

    }
    ListModel{
        id: hostModel
//        ListElement{
//            hostName: "abc"
//        }
//        ListElement{
//            hostName: "abd,"
//        }
    }

    Timer{
        id: hostFoundTimer
        interval: 2000
        onTriggered: {
            emitter.enabled = false
            addNewHostFound("Slackfi-1")
        }
        running: false
        repeat: true
    }


    function close(){
        if (emitter.enabled)
            emitter.enabled = false
        visible = false
    }


    function reset(){
        hostModel.clear()
    }

    function addNewHostFound(HN){
//        foundHostList.model = undefined
        hostModel.append({"hostName":HN})
//        hostModel.insert(0, {"hostName":HN} )
//        console.log(HN)
//        foundHostList.model = hostModel
//        foundHostList.model.append({"hostName":HN});
//        console.log(hostModel.count)
    }


}

