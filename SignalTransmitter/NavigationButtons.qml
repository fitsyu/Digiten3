import QtQuick 2.0

Item {
    width: 200
    height: 200

    signal goUp()
    signal goDown()
    signal goLeft()
    signal goRight()

    Image {
        id: navButton

        anchors.fill: parent

        source: "qrc:/img/NavButton.png"

        transform: Rotation {
            id: transrotation

            origin{
                x: width /2
                y: height /2
            }
            angle: 0

            Behavior on angle{
                NumberAnimation{}
            }

        }


        // (M)ouse (A)rea (W)idth and (H)eight
        property int maw: navButton.width * 0.20
        property int mah: navButton.height * 0.40

        MouseArea {
            id: m_Up

            width: navButton.maw
            height: navButton.mah

            anchors{
                top: parent.top
                horizontalCenter: parent.horizontalCenter
            }

            onClicked: goUp()

            onPressed: {
                transrotation.axis.x = 1
                transrotation.axis.y = 0
                transrotation.axis.z = 0
                transrotation.angle = 20
            }

            onReleased: {
                transrotation.axis.x = 0
                transrotation.axis.y = 0
                transrotation.axis.z = 0
                transrotation.angle = 0
            }
        }

        MouseArea {
            id: m_Down

            width: navButton.maw
            height: navButton.mah

            anchors{
                bottom: parent.bottom
                horizontalCenter: parent.horizontalCenter
            }

            onClicked: goDown()

            onPressed: {
                transrotation.axis.x = 1
                transrotation.axis.y = 0
                transrotation.axis.z = 0
                transrotation.angle = -20
            }

            onReleased: {
                transrotation.axis.x = 0
                transrotation.axis.y = 0
                transrotation.axis.z = 0
                transrotation.angle = 0
            }
        }

        MouseArea {
            id: m_Left

            width: navButton.mah
            height: navButton.maw

            anchors{
                left: parent.left
                verticalCenter: parent.verticalCenter
            }

            onClicked: goLeft()

            onPressed: {
                transrotation.axis.x = 0
                transrotation.axis.y = 1
                transrotation.axis.z = 0
                transrotation.angle = -20
            }

            onReleased: {
                transrotation.axis.x = 0
                transrotation.axis.y = 0
                transrotation.axis.z = 0
                transrotation.angle = 0
            }
        }

        MouseArea {
            id: m_Right

            width: navButton.mah
            height: navButton.maw

            anchors{
                right: parent.right
                verticalCenter: parent.verticalCenter
            }

            onClicked: goRight()

            onPressed: {
                transrotation.axis.x = 0
                transrotation.axis.y = 1
                transrotation.axis.z = 0
                transrotation.angle = 20
            }

            onReleased: {
                transrotation.axis.x = 0
                transrotation.axis.y = 0
                transrotation.axis.z = 0
                transrotation.angle = 0
            }
        }
    }
}

