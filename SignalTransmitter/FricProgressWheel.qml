import QtQuick 2.0

Item {
    id: baseItem
    width: 100 // default
    height: width

    property string aura: "white"

    Image {
        id: grid
        width: parent.width
        height: width
        source: "qrc:/img/grid.png"
    }


    Component.onCompleted: {
        createChunks()
    }

    property var chunks: []
    function createChunks(){
        var chunkComponent = Qt.createComponent("FricProgressChunk.qml")

//        for (var c=0; c<24; c++){
            var chunk = chunkComponent.createObject(baseItem);
//            chunk.width = baseItem.width
//            chunk.value = c*15;
            chunk.visible = true //false
//            chunks.push(chunk)

//        }
//        chunks[0].visible = true
    }

    function work(){
//        chunks[0].work()
//        chunks[0].tired.connect(showAllChunks)
        timer.start()
    }

    function showAllChunks(){
        for (var c=0; c<24; c++){
            chunks[c].visible=true
        }
    }

    property int value: 0
    function increase(){
        if (value<24){
            chunks[value].visible = true
            value++;
        } else { timer.stop() }
    }

    function decrease(){
        if (value<0){
            chunks[value].visible = false
            value--;
        }
    }

    Timer {
        id: timer
        interval: 200
        onTriggered: increase()
        repeat: true
        running: false

    }
}

