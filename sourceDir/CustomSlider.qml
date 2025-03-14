// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: rootItem
    property alias sliderValue: slider.value
    property alias fromValue: slider.from
    property alias toValue: slider.to
    property alias sliderEnabled: slider.enabled
    property alias sliderStepSize: slider.stepSize
    property string unit
    readonly property bool highlight: slider.hovered || slider.pressed

    width: 260
    height: rowLayout.height

    MouseArea {
        anchors.fill: parent
        onPressed: {

        }
    }

    RowLayout {
        id: rowLayout
        width: parent.width
        Slider {
            id: slider
            from: fromValue
            to: toValue
            onValueChanged: {
                rootItem.sliderValue = slider.value
            }
            stepSize: 0.001
            Layout.minimumWidth: 200
            Layout.fillWidth: true
            background: Rectangle {
                x: slider.leftPadding
                y: slider.topPadding + slider.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 2
                width: slider.availableWidth
                height: implicitHeight
                color: "#606060"
                Rectangle {
                    width: slider.visualPosition * parent.width
                    height: parent.height
                    color: "#41cd52"
                }
            }
            handle: Rectangle {
                x: slider.leftPadding + slider.visualPosition * (slider.availableWidth - width)
                y: slider.topPadding + slider.availableHeight / 2 - height / 2
                implicitWidth: 14
                implicitHeight: 14
                radius: width / 2
                color: slider.pressed ? "#ffffff" : "#d0d0d0"
                border.color: "#d0d0d0"
            }
        }
        Label {
            id: valueText
            text: slider.value.toFixed(3) + " " + unit
            color: "#f0f0f0"
            font.bold: true
            Layout.minimumWidth: 60
        }
    }
}
