import QtQuick
import QtQuick3D

Rectangle {
    id: window
    width: 1280
    height: 720
    visible: true

    property point lastMousePos: Qt.point(0, 0)
    property real rotateX: 0
    property real rotateY: 0
    Item {
        id: none
        anchors.fill: parent
        focus: true
        Keys.onPressed: event => {
                            if (event.key === Qt.Key_A)
                            cameraNode.position.x -= 10
                            else if (event.key === Qt.Key_D)
                            cameraNode.position.x += 10
                            else if (event.key === Qt.Key_W)
                            cameraNode.position.y += 10
                            else if (event.key === Qt.Key_S)
                            cameraNode.position.y -= 10
                            else if (event.key === Qt.Key_Q)
                            cameraNode.position.z += 10
                            else if (event.key === Qt.Key_E)
                            cameraNode.position.z -= 10
                        }
    }
    View3D {
        id: view
        anchors.fill: parent

        environment: SceneEnvironment {
            clearColor: "skyblue"
            backgroundMode: SceneEnvironment.Color
        }
        Node {
            id: cameraNode
            PerspectiveCamera {
                id: camera
                position: Qt.vector3d(0, 200, 300)
                eulerRotation.x: -30
            }
        }

        DirectionalLight {
            eulerRotation.x: -30
            eulerRotation.y: -70
        }
        DirectionalLight {
            eulerRotation.x: 30
            eulerRotation.y: 70
        }

        Mymodel {}
        MouseArea {
            id: mouse
            anchors.fill: parent
            property int cx: 0
            property int cy: 0
            onWheel: wheel => {
                         if (wheel.angleDelta.y > 0)
                         camera.z = camera.z - 5
                         else
                         camera.z = camera.z + 5
                     }
            onPressed: mouse => {
                           cx = mouse.x
                           cy = mouse.y
                       }

            onPositionChanged: mouse => {
                                   var intervalX = mouse.x - cx
                                   var intervalY = mouse.y - cy
                                   cameraNode.eulerRotation.y = intervalX
                                   + cameraNode.eulerRotation.y
                                   cameraNode.eulerRotation.x
                                   = cameraNode.eulerRotation.x - intervalY
                                   cx = mouse.x
                                   cy = mouse.y
                               }
        }
    }
}
