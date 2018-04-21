import QtQuick 2.4
import QtGraphicalEffects 1.0

Item {
    property string aura: "#15b8c6"

    property string logoSource: "/img/arrow-up.png"

    RectangularGlow {
        id: effect
        anchors.fill: trueButton
        glowRadius: 5
        spread: 0.25
        color: parent.aura
        cornerRadius: trueButton.radius
        visible: true


    }

    Rectangle {
        id: trueButton
        // position
        anchors { centerIn:  parent }

        // size
        width: parent.width / 1.5
        height: width
        radius: width/5.0

        // color
        color: "grey"

        Image {
            id: logo
            anchors.centerIn: parent
            width: parent.width
            height: width
            source: logoSource
            visible: false
        }

        Glow {
            id: logoGlower
            spread: 0.5
            radius: effect.glowRadius * 4
            samples: 20
            color: "#15b8c6"
            source: logo
            anchors.fill: source
        }

    }

    signal kepencet()
    MouseArea {
        anchors.fill: trueButton
        onPressed: {
            //                effect.visible = true
            effect.glowRadius = 10 //5
            trueButton.scale = 0.95
            kepencet()
        }
        onReleased: {
            //                effect.visible = false
            effect.glowRadius = 5 //2.5
            trueButton.scale = 1
        }
    }

}


