import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: chunk
    property int value: 0
    Image {
        id: chunkSource
        width: parent.width
        height: width
        source: "qrc:/img/chunk2.png"
        visible: false
        rotation: value
    }

    Glow {
        id: glowingChunk
        anchors.fill: chunkSource
        radius: 40
        samples: 16
        color: "#17d9d6"
        source: chunkSource
        rotation: value
    }

//    Rectangle { }


    PropertyAnimation {
        id: spinner
        target: glowingChunk;
        property: "rotation"
        from: 0
        to: 360
        duration: 1000
//        loops: Animation.Infinite
        onStopped: tired()
    }
    signal tired()

    function work(){
        spinner.start()
    }


}
