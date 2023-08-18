import QtQuick
import QtQuick3D

Rectangle {
    id: window
    width: 1280
    height: 720
    visible: true

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
    Image {
        z: parent.z + 1
        opacity: 0.3
        anchors.fill: parent
        source: "qrc:/qml/meshes/bg1.png"
        fillMode: Image.PreserveAspectCrop
    }
    View3D {
        id: view
        anchors.fill: parent

        environment: SceneEnvironment {
            clearColor: "#00192e"
            backgroundMode: SceneEnvironment.Color
        }
        Node {
            id: cameraNode
            eulerRotation.x: -17
            eulerRotation.y: 115
            PerspectiveCamera {
                id: camera
                y: 20
                clipNear: 0.1
                fieldOfView: 50
                z: 520
                x: -10
                clipFar: 800
            }
        }

        Model {
            id: laser_source
            position: Qt.vector3d(174.136, 16.2984, -1.59588)
            rotation: Qt.quaternion(0.505685, -0.499261, 0.502703, 0.492251)
            scale: Qt.vector3d(100, 100, 100)
            source: "qrc:/qml/meshes/cube_002.mesh"
            objectName: "Laser"
            pickable: true //可选
            property bool isPicked: false //记录是否选中该零件
            materials: {
                laser_source.isPicked ? material_clicked : laser_body_material
            }
        }
        Model {
            id: cube_001
            position: Qt.vector3d(100.479, 20.461, -108.245)
            rotation: Qt.quaternion(0.947253, 0.0133086, -0.319867, 0.0148305)
            scale: Qt.vector3d(28.8999, 29.6333, 4.34995)
            source: "qrc:/qml/meshes/cube_001.mesh"
            objectName: "Screen"
            pickable: true
            property bool isPicked: false
            materials: {
                cube_001.isPicked ? material_clicked : material_006_material
            }
            //                    receivesShadows: true
        }
        Model {
            id: beam_01
            position: Qt.vector3d(80.6691, 8.91805, -5.74462)
            rotation: Qt.quaternion(0.69381, -0.719738, -0.0235141, -0.00725219)
            scale: Qt.vector3d(103.859, 103.859, 103.859)
            source: "qrc:/qml/meshes/bezierCurve_001.mesh"
            objectName: "Beam_01"
            pickable: true
            property bool isPicked: false

            materials: {
                beam_01.isPicked ? material_clicked : laser_beam_material_material
            }
        }

        Model {
            id: beam_02
            position: Qt.vector3d(59.5347, 9.46301, -57.7307)
            rotation: Qt.quaternion(0.632403, -0.648441, 0.286342, 0.312409)
            scale: Qt.vector3d(103.859, 103.859, 103.859)
            source: "qrc:/qml/meshes/bezierCurve_002.mesh"
            objectName: "Beam_02"
            pickable: true
            property bool isPicked: false
            materials: {
                beam_02.isPicked ? material_clicked : laser_beam_material_material
            }
        }
        Model {
            id: phone
            position: Qt.vector3d(17.0699, 10.2998, -5.08116)
            rotation: Qt.quaternion(0.0445037, 0.144431, 0.00981306, 0.988465)
            scale: Qt.vector3d(29.8427, 29.8427, 29.8427)
            source: "qrc:/qml/meshes/cube.mesh"
            objectName: "Phone"
            pickable: true
            property bool isPicked: false
            materials: {
                phone.isPicked ? [material_clicked, material_clicked, material_clicked, material_clicked] : [material_004_material, material_004_material, material_003_material, material_002_material]
            }
        }

        Model {
            id: plane
            position: Qt.vector3d(70, -19.4925, 10)
            rotation: Qt.quaternion(0.707107, -0.707107, 0, 0)
            scale: Qt.vector3d(315.555, 315.555, 315.555)
            source: "qrc:/qml/meshes/plane.mesh"
            objectName: "Plane"
            materials: material_005_material
        }
        PointLight {
            id: point_light_1
            position: Qt.vector3d(0, 126.276, -18.92799)
            rotation: Qt.quaternion(0.707107, -0.707107, 0, 0)
            scale: Qt.vector3d(100, 100, 100)
            brightness: 10
            quadraticFade: 0.0031999999191612005
            castsShadow: true
            shadowFactor: 180
            shadowMapQuality: Light.ShadowMapQualityVeryHigh
        }
        PointLight {
            id: point_light_2
            position: Qt.vector3d(86.1898, 126.276, -148.92799)
            rotation: Qt.quaternion(0.707107, -0.707107, 0, 0)
            scale: Qt.vector3d(100, 100, 100)
            brightness: 20
            quadraticFade: 0.0031999999191612005
            castsShadow: true
            shadowFactor: 180
            shadowMapQuality: Light.ShadowMapQualityVeryHigh
        }
        Model {
            id: text_
            position: Qt.vector3d(184.949, -19.4951, -39.195)
            rotation: Qt.quaternion(-0.00780069, 0.00780069, 0.707064, 0.707064)
            scale: Qt.vector3d(44.6816, 44.6816, 44.6816)
            source: "qrc:/qml/meshes/text_001.mesh"
            materials: defaultMaterial_material
            //                    materials: material_005_material
        }
        Model {
            id: text_001
            position: Qt.vector3d(0.0935555, -12.6789, -49.8422)
            rotation: Qt.quaternion(-0.00780069, 0.00780069, 0.707064, 0.707064)
            scale: Qt.vector3d(44.6816, 44.6816, 44.6816)
            source: "qrc:/qml/meshes/text_002.mesh"
            materials: defaultMaterial_material
            //                    materials: material_005_material
        }
        Model {
            id: text_002
            position: Qt.vector3d(40.5972, -13.8482, -129.779)
            rotation: Qt.quaternion(-0.00780069, 0.00780069, 0.707064, 0.707064)
            scale: Qt.vector3d(35.4778, 35.4778, 35.4779)
            source: "qrc:/qml/meshes/text_003.mesh"
            materials: defaultMaterial_material
            //                    materials: material_005_material
        }
        MouseArea {
            id: mouse
            anchors.fill: parent
            property int cx: 0
            property int cy: 0
            property string nameText: "globalArea"
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
            onClicked: mouse => {
                           // Get screen coordinates of the click
                           //                    name.text = "萤幕位置: (" + mouse.x + ", " + mouse.y + ")"
                           var result = view.pick(mouse.x, mouse.y)
                           if (result.objectHit) {
                               var pickedObject = result.objectHit
                               pickedObject.isPicked = !pickedObject.isPicked

                               if (pickedObject === beam_01) {
                                   beam_02.isPicked = beam_01.isPicked
                               } else if (pickedObject === beam_02) {
                                   beam_01.isPicked = beam_02.isPicked
                               }
                           }
                       }
        }
    }
    Item {
        id: __materialLibrary__

        PrincipledMaterial {
            id: laser_body_material
            objectName: "laser_body_material"
            baseColor: "#ff09080e"
        }

        PrincipledMaterial {
            id: laser_beam_material_material
            objectName: "laser_beam_material_material"
            baseColor: "#FFA500"
        }

        PrincipledMaterial {
            id: material_004_material
            objectName: "material_004_material"
            baseColor: "#282828"
        }

        PrincipledMaterial {
            id: material_003_material
            objectName: "material_003_material"
            baseColor: "#000080"
        }

        PrincipledMaterial {
            id: material_002_material
            objectName: "material_002_material"
            baseColor: "#282828"
        }

        PrincipledMaterial {
            id: defaultMaterial_material
            objectName: "defaultMaterial_material"
            baseColor: "#483D8B"
        }

        PrincipledMaterial {
            id: material_005_material
            objectName: "material_005_material"
            baseColor: "#ff1a1a1a"
        }

        PrincipledMaterial {
            id: material_006_material
            objectName: "material_006_material"
            baseColor: "#BA55D3"
        }
        PrincipledMaterial {
            //the color when the object is clicked
            id: material_clicked
            objectName: "material_006_material"
            baseColor: "#FF0000"
        }
    }
}
