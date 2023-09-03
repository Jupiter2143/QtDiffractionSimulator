import QtQuick
import QtQuick3D
import QtQuick.Dialogs
import QtQuick.Controls
import QtQuick3D.Particles3D
import QtQuick.Controls.Basic

Rectangle {
    id: window
    width: 720 * 1.618
    height: 720
    visible: true

    property alias thetaValue: theta.sliderValue
    property alias in_l0Value: in_l0.sliderValue
    property alias out_L0Value: out_L0.sliderValue
    property alias lambdaValue: lambda.sliderValue
    property alias beamRadiusValue: beamRadius.sliderValue
    property alias xSpacingValue: xSpacing.sliderValue
    property alias ySpacingValue: ySpacing.sliderValue
    property alias xOffsetValue: xOffset.sliderValue
    property alias yOffsetValue: yOffset.sliderValue
    property alias scaleValue: scale.sliderValue
    property alias xCenterValue: xCenter.sliderValue
    property alias yCenterValue: yCenter.sliderValue

    signal qmlValueChange(double theta, double in_l0, double out_L0, double lambda, double beamRadius, double xSpacing, double ySpacing, double xOffset, double yOffset, double scale, double xCenter, double yCenter)

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
                x: -10
                z: 520
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

                ParticleSystem3D {
                    id: psystemNeedle
                    visible: visOfEf.checked
                    SpriteParticle3D {
                        id: needleParticle
                        sprite: Texture {
                            source: "qrc:/res/sourceDir/dot.png"
                        }
                        maxAmount: 500
                        fadeInDuration: 50
                        fadeOutDuration: 200
                        color: "#40DC143C"
                        colorVariation: Qt.vector4d(0.2, 0.2, 0.0, 0.2)
                        blendMode: SpriteParticle3D.Screen
                    }

                    ParticleEmitter3D {
                        particle: needleParticle
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
            baseColor: "#4E342E"
        }

        PrincipledMaterial {
            id: laser_beam_material_material
            objectName: "laser_beam_material_material"
            baseColor: "#B71C1C"
        }

        PrincipledMaterial {
            id: material_004_material
            objectName: "material_004_material"
            baseColor: "#111111"
        }

        PrincipledMaterial {
            id: material_003_material
            objectName: "material_003_material"
            baseColor: "#8A2BE2"
        }

        PrincipledMaterial {
            id: material_002_material
            objectName: "material_002_material"
            baseColor: "#111111"
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
            baseColor: "#40C4FF"
        }
        PrincipledMaterial {
            //the color when the object is clicked
            id: material_clicked
            objectName: "material_006_material"
            baseColor: "#FFD700"
        }
    }
    Column {
        x: parent.x + 5
        y: parent.y + 43
        spacing: 3
        visible: visOfPF.checked && para_setting_frame.visible
        Rectangle {
            width: 300
            height: 275
            color: {
                (laser_source.isPicked
                 || beam_01.isPicked) ? '#1A237E' : '#004F4F4F'
            }
            radius: 10
        }
        Rectangle {
            width: 300
            height: 205
            color: {
                phone.isPicked ? '#01579B' : '#004F4F4F'
            }
            radius: 10
        }
        Rectangle {
            width: 300
            height: 160
            color: {
                cube_001.isPicked ? '#33691E' : '#004F4F4F'
            }
            radius: 10
        }
    }

    Frame {
        id: para_setting_frame
        width: 300
        height: 600
        visible: visOfPF.checked
        background: Rectangle {
            color: "#20606060"
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
                id: theta
                objectName: "theta"
                unit: "°"
                sliderValue: 58.59
                fromValue: 0
                toValue: 89.999
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_inAngleDistance
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "入射距离： "
            }
            CustomSlider {
                id: in_l0
                objectName: "in_l0"
                unit: "m"
                sliderValue: 0.500
                fromValue: 0
                toValue: 999.999
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_outAngleDistance
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "出射距离： "
            }
            CustomSlider {
                id: out_L0
                objectName: "out_L0"
                sliderValue: 0.870
                fromValue: 0
                toValue: 999.999
                unit: "m"
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_waveLength
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "波长： "
            }
            CustomSlider {
                id: lambda
                objectName: "lambda"
                sliderValue: 635.0
                sliderStepSize: 1
                fromValue: 0
                toValue: 999.999
                unit: "nm"
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_beamRadius
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "光束半径： "
            }
            CustomSlider {
                id: beamRadius
                objectName: "beamRadius"
                sliderValue: 1.00
                fromValue: 0
                toValue: 999.999
                unit: "mm"
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_pixelSpaceX
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "像素间距X： "
            }
            CustomSlider {
                id: xSpacing
                objectName: "xSpacing"
                sliderValue: 63.82
                fromValue: -999.999
                toValue: 999.999
                unit: "um"
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_pixelSpaceY
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "像素间距Y： "
            }
            CustomSlider {
                id: ySpacing
                objectName: "ySpacing"
                sliderValue: 63.82
                fromValue: -999.999
                toValue: 999.999
                unit: "um"
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_horizontalOffset
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "水平偏移： "
            }
            CustomSlider {
                id: xOffset
                objectName: "xOffset"
                sliderValue: 0.000
                fromValue: -999.999
                toValue: 999.999
                unit: "um"
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_vertitalOffset
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "垂直偏移： "
            }
            CustomSlider {
                id: yOffset
                objectName: "yOffset"
                sliderValue: 0.000
                fromValue: -999.999
                toValue: 999.999
                unit: "um"
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_plottingScale
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "比例尺： "
            }
            CustomSlider {
                id: scale
                objectName: "scale"
                sliderValue: 0.2
                fromValue: 0
                toValue: 999.999
                unit: "mm"
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_opticalScreenX
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "光屏中心X： "
            }
            CustomSlider {
                id: xCenter
                objectName: "xCenter"
                sliderValue: 0.000
                fromValue: -999.999
                toValue: 999.999
                unit: "m"
                onSliderValueChanged: emitSignal()
            }
            Text {
                id: text_opticalScreenY
                font.pixelSize: 16
                color: "#FFFFFF"
                text: "光屏中心Y： "
            }
            CustomSlider {
                id: yCenter
                objectName: "yCenter"
                sliderValue: 0.000
                fromValue: -999.999
                toValue: 999.999
                unit: "m"
                onSliderValueChanged: emitSignal()
            }
        }
    }

    Button {
        height: 30
        width: 145
        x: 987
        y: 670
        text: "回到默认视角"
        background: Rectangle {
            color: Qt.rgba(0.8, 0.8, 0.8, 1)
            radius: 5
        }
        onClicked: resetCamPo()
    }
    CustomCheckBox {
        id: visOfPF
        text: "显示参数设置面板"
        checked: true
        x: 980
        y: 605
    }

    CustomCheckBox {
        id: visOfEf
        text: "显示入射光线效果"
        checked: false
        x: 980
        y: 635
    }
    function emitSignal() {
        qmlValueChange(thetaValue, in_l0Value, out_L0Value, lambdaValue,
                       beamRadiusValue, xSpacingValue, ySpacingValue,
                       xOffsetValue, yOffsetValue, scaleValue, xCenterValue,
                       yCenterValue)
    }
    function resetCamPo() {
        cameraNode.eulerRotation.x = -17
        cameraNode.eulerRotation.y = 115
        camera.x = -10
        camera.y = 20
        camera.z = 520
    }
}
