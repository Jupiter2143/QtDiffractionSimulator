import QtQuick
import QtQuick3D
import QtQuick.Dialogs
import QtQuick.Controls
import QtQuick3D.Particles3D

//Window
Rectangle {
    id: window
    width: 720 * 1.618
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
            id: beam_01
            position: Qt.vector3d(80.6691, 8.91805, -5.74462)
            rotation: Qt.quaternion(0.69381, -0.719738, -0.0235141, -0.00725219)
            scale: Qt.vector3d(100, 100, 100) //origin 103.859
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
            position: Qt.vector3d(55.5347, 9.46301, -53.7307)
            rotation: Qt.quaternion(0.632403, -0.648441, 0.286342, 0.312409)
            scale: Qt.vector3d(103, 103, 103)
            source: "qrc:/qml/meshes/bezierCurve_002.mesh"
            objectName: "Beam_02"
            pickable: true
            property bool isPicked: false
            materials: {
                beam_02.isPicked ? material_clicked : laser_beam_material_material
            }
        }
        Model {
            id: cube_001
            position: Qt.vector3d(100.479, 20.461, -108.245)
            rotation: Qt.quaternion(0.946928, -0.00546786, -0.321297,
                                    0.00809321)
            scale: Qt.vector3d(28.8999, 29.6333, 4.34995)
            source: "qrc:/qml/meshes/cube_001.mesh"
            objectName: "Screen"
            pickable: true
            property bool isPicked: false
            materials: {
                cube_001.isPicked ? material_clicked : material_006_material
            }
        }

        Model {
            id: phone
            position: Qt.vector3d(17.0699, 10.2998, -5.08116)
            rotation: Qt.quaternion(0.004537, 0.144431, 0.00981306, 0.988465)
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
            scale: Qt.vector3d(450, 450, 450)
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
            scale: Qt.vector3d(30, 30, 30)
            source: "qrc:/qml/meshes/text_001.mesh"
            materials: defaultMaterial_material
        }
        Model {
            id: text_001
            position: Qt.vector3d(0.0935555, -12.6789, -49.8422)
            rotation: Qt.quaternion(-0.00780069, 0.00780069, 0.707064, 0.707064)
            scale: Qt.vector3d(30, 30, 30)
            source: "qrc:/qml/meshes/text_002.mesh"
            materials: defaultMaterial_material
        }
        Model {
            id: text_002
            position: Qt.vector3d(40.5972, -13.8482, -129.779)
            rotation: Qt.quaternion(-0.00780069, 0.00780069, 0.707064, 0.707064)
            scale: Qt.vector3d(30, 30, 30)
            source: "qrc:/qml/meshes/text_003.mesh"
            materials: defaultMaterial_material
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
                           var result = view.pick(mouse.x, mouse.y)
                           if (result.objectHit) {
                               var pickedObject = result.objectHit
                               pickedObject.isPicked = !pickedObject.isPicked

                               if (pickedObject === beam_01) {
                                   laser_source.isPicked = beam_02.isPicked = beam_01.isPicked
                               } else if (pickedObject === beam_02) {
                                   laser_source.isPicked = beam_01.isPicked = beam_02.isPicked
                               } else if (pickedObject === laser_source) {
                                   beam_01.isPicked = beam_02.isPicked = laser_source.isPicked
                               }
                           }
                       }
        }
        Node {
            id: gaugeItem

            property real value: 0
            property real needleSize: 150

            SequentialAnimation on value {
                running: true
                loops: Animation.Infinite
                NumberAnimation {
                    duration: 8000
                    to: 1
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    duration: 8000
                    to: 0
                    easing.type: Easing.InOutQuad
                }
            }
            y: 0
            eulerRotation.z: 90
            eulerRotation.y: -5

            Model {
                position.x: 8
                position.z: -13
                position.y: 105
                scale: Qt.vector3d(0.05 / 2,
                                   gaugeItem.needleSize * 0.01 / 2, 0.2 / 2)
                materials: PrincipledMaterial {
                    baseColor: "#FF6060"
                }

                ParticleEmitter3D {
                    y: 10
                    scale: Qt.vector3d(0.1, 0.8, 0.1)
                    shape: ParticleShape3D {
                        type: ParticleShape3D.Cube
                    }
                    particleScale: 2.0
                    particleScaleVariation: 1.0
                    particleRotationVariation: Qt.vector3d(0, 0, 180)
                    particleRotationVelocityVariation: Qt.vector3d(20, 20, 200)
                    emitRate: 500
                    lifeSpan: 2000
                    lifeSpanVariation: 1000
                }

                // Needle particle system
                // This system rotates together with the needle
                ParticleSystem3D {
                    id: psystemNeedle
                    running: true
                    visible: running
                    SpriteParticle3D {
                        id: needleParticle
                        sprite: Texture {
                            source: "qrc:/res/sourceDir/dot.png"
                        }
                        maxAmount: 500
                        fadeInDuration: 50
                        fadeOutDuration: 200
                        //                        color: "#40808020"
                        color: "#40DC143C"
                        colorVariation: Qt.vector4d(0.2, 0.2, 0.0, 0.2)
                        blendMode: SpriteParticle3D.Screen
                    }

                    ParticleEmitter3D {
                        particle: needleParticle
                        //                        x: -1000
                        y: -300

                        scale: Qt.vector3d(
                                   0.8, 0.8,
                                   0.2) //origin: scale: Qt.vector3d(0.2, 0.0, 0.2)
                        shape: ParticleShape3D {
                            type: ParticleShape3D.Cube
                        }

                        particleScale: 1.0 //origin particleScale: 4.0
                        particleScaleVariation: 2.0
                        particleEndScale: 1.0
                        particleEndScaleVariation: 0.5
                        velocity: VectorDirection3D {
                            direction: Qt.vector3d(0, 110, 0)
                            directionVariation: Qt.vector3d(10, 10, 10)
                        }
                        emitRate: 200
                        lifeSpan: 1000
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
    Column {
        x: parent.x + 5
        y: parent.y + 43
        spacing: 3
        Rectangle {
            width: 300
            height: 275
            color: {
                (laser_source.isPicked
                 || beam_01.isPicked) ? '#E04F4F4F' : '#004F4F4F'
            }
        }
        Rectangle {
            width: 300
            height: 205
            color: {
                phone.isPicked ? '#E04F4F4F' : '#004F4F4F'
            }
        }
        Rectangle {
            width: 300
            height: 160
            color: {
                cube_001.isPicked ? '#E04F4F4F' : '#004F4F4F'
            }
        }
    }
    Frame {
        id: para_setting_frame
        width: 300 // 设置宽度为 300
        height: 600
        visible: true
        background: Rectangle {
            color: "#20606060" // 将透明度部分设置为完全半透明
        }
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 5
        Column {
            id: para_setting_area
            spacing: 9
            Text {
                id: text_Hint
                font.pixelSize: 25
                color: "#FFFFFF"
                text: "参数调节： "
            }
            Text {
                id: text_angle
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "入射角： "
            }
            CustomSlider {
                id: para_angle
                unit: "°"
                sliderValue: 68.590
                fromValue: 0
                toValue: 99.990
                onSliderValueChanged: {
                    inAngleChangedSignal(para_angle.sliderValue)
                }
            }
            Text {
                id: text_inAngleDistance
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "入射距离： "
            }
            CustomSlider {
                id: para_inAngleDistance
                sliderValue: 0.500
                fromValue: 0
                toValue: 999
                unit: "m"
            }
            Text {
                id: text_outAngleDistance
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "出射距离： "
            }
            CustomSlider {
                id: para_outAngleDistance
                sliderValue: 0.870
                fromValue: 0
                toValue: 999
                unit: "m"
            }
            //感觉没必要了
            //            Text {
            //                id: text_lightSourceType
            //                font.pixelSize: 16
            //                color: "#FFFFFF"
            //                text: "光源类型： "
            //            }
            //            Row {
            //                spacing: 10
            //                CustomCheckBox {
            //                    id: lightSource_circle
            //                    text: "圆"
            //                    checked: true
            //                    onCheckedChanged: {
            //                        if (checked) {
            //                            lightSource_rectangle.checked = false
            //                            lightSource_point.checked = false
            //                        }
            //                    }
            //                }
            //                CustomCheckBox {
            //                    id: lightSource_rectangle
            //                    text: "矩形"
            //                    checked: false
            //                    onCheckedChanged: {
            //                        if (checked) {
            //                            lightSource_circle.checked = false
            //                            lightSource_point.checked = false
            //                        }
            //                    }
            //                }
            //                CustomCheckBox {
            //                    id: lightSource_point
            //                    text: "点"
            //                    checked: false
            //                    onCheckedChanged: {
            //                        if (checked) {
            //                            lightSource_circle.checked = false
            //                            lightSource_rectangle.checked = false
            //                        }
            //                    }
            //                }
            //            }
            Text {
                id: text_waveLength
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "波长： "
            }
            CustomSlider {
                id: para_waveLength
                sliderValue: 635
                fromValue: 0
                toValue: 1000
                unit: "nm"
            }
            Text {
                id: text_beamRadius
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "光束半径： "
            }
            CustomSlider {
                id: para_beamRadius
                sliderValue: 1.00
                fromValue: 0
                toValue: 999
                unit: "mm"
            }
            Text {
                id: text_pixelSpaceX
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "像素间距X： "
            }
            CustomSlider {
                id: para_pixelSpaceX
                sliderValue: 63.82
                fromValue: 0
                toValue: 999.00
                unit: "um"
            }
            Text {
                id: text_pixelSpaceY
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "像素间距Y： "
            }
            CustomSlider {
                id: para_pixelSpaceY
                sliderValue: 63.82
                fromValue: 0
                toValue: 999.00
                unit: "um"
            }
            Text {
                id: text_horizontalOffset
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "水平偏移： "
            }
            CustomSlider {
                id: para_horizontalOffset
                sliderValue: 0.000
                fromValue: 0
                toValue: 999
                unit: "um"
            }
            Text {
                id: text_vertitalOffset
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "垂直偏移： "
            }
            CustomSlider {
                id: para_verticalOffset
                sliderValue: 0.000
                fromValue: 0
                toValue: 999
                unit: "um"
            }
            Text {
                id: text_plottingScale
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "比例尺： "
            }
            CustomSlider {
                id: para_plottingScale
                sliderValue: 0.2
                fromValue: 0
                toValue: 360
                unit: "mm"
            }
            Text {
                id: text_opticalScreenX
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "光屏中心X： "
            }
            CustomSlider {
                id: para_opticalScreenX
                sliderValue: 0.000
                fromValue: 0
                toValue: 999
                unit: "m"
            }
            Text {
                id: text_opticalScreenY
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "光屏中心Y： "
            }
            CustomSlider {
                id: para_opticalScreenY
                sliderValue: 0.000
                fromValue: 0
                toValue: 999
                unit: "m"
            }
        }
    }
    signal inAngleChangedSignal(double value)
    //definition
}
