import QtQuick
import QtQuick.Controls

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Newclides")

    Connections {
        target: mainController

        onDirPathToQml:{
            storagePathTextedit.text = _dirPath
        }

        onBuildModelStatusMessage:{
            mainWinTextArea.text += buildModelMessage + "\n"
        }
        onIdentifiedNuclideToQml:{
            identifiedNuclideLabel.text = identifiedNuclide_
        }
    }


    Rectangle {
        id: mainWin
        x: 0
        y: 0
        width: 1280
        height: 720
        visible: false
        color: "#000000"

        Image {
            id: mainWinBgImg
            x: 0
            y: 0
            width: 1280
            height: 720
            source: "file:C:/Newclides/images/bg.png"
            fillMode: Image.PreserveAspectFit

            Image {
                id: mainText
                x: 589
                y: 14
                width: 103
                height: 38
                source: "file:C:/Newclides/images/mainText.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: selectDirBtn
                x: 259
                y: 449
                width: 78
                height: 24
                source: "file:C:/Newclides/images/selectDirBtn.png"
                fillMode: Image.PreserveAspectFit

                MouseArea {
                    id: selectDirMouseArea
                    width: 78
                    height: 24
                    onClicked: {
                        mainController.selectDirectory()
                    }
                }
            }

            Text {
                id: text1
                x: 348
                y: 433
                width: 131
                height: 16
                color: "#ffffff"
                text: qsTr("Select Storage Location")
                font.pixelSize: 12
            }

            Image {
                id: startBtn
                x: 348
                y: 539
                width: 78
                height: 24
                source: "file:C:/Newclides/images/startBtn2.png"
                fillMode: Image.PreserveAspectFit

                MouseArea {
                    id: startBtnMouseArea
                    width: 78
                    height: 24
                    onClicked: {
                        mainController.buildModel(storagePathTextedit.text, atomicNumTextEdit.text, numProtonsTxtEdit.text)
                    }
                }
            }
        }

        ComboBox {
            id: selectModel
            x: 260
            y: 665
            width: 661
            height: 21
            editable: false
            visible: false
            model: ["Select Build Mode", "Build single","Build All with Spin Equal to", "Build All"]

            delegate: ItemDelegate {
                width: selectModel.width
                contentItem: Text {
                    text: selectModel.textRole
                          ? (Array.isArray(selectModel.model) ? modelData[selectModel.textRole] : model[selectModel.textRole])
                          : modelData
                    color: "#000000" //Change the text color of the model data in the drop down box.
                    font: selectModel.font
                    elide: Text.ElideRight
                    verticalAlignment: Text.AlignVCenter
                }
                highlighted: selectModel.highlightedIndex === index
            }

            indicator: Canvas {
                id: canvasselectOutputFormat
                x: selectModel.width - width - selectModel.rightPadding
                y: selectModel.topPadding + (selectModel.availableHeight - height) / 2
                width: 12
                height: 8
                contextType: "2d"

                Connections {
                    target: selectModel
                    function onPressedChanged() { canvasselectAlgorithm.requestPaint(); }
                }

                //This will change the color of the triangle indicator.
                onPaint: {
                    context.reset();
                    context.moveTo(0, 0);
                    context.lineTo(width, 0);
                    context.lineTo(width / 2, height);
                    context.closePath();
                    context.fillStyle = selectModel.pressed ? "#FFFFFF" : "#FFFFFF";
                    context.fill();
                }
            }
            //The second color is the main color. The first item is what color the changes to once clicked.
            //This will change the text color of main text in the box.
            contentItem: Text {
                leftPadding: 0
                rightPadding: selectModel.indicator.width + selectModel.spacing

                text: selectModel.displayText
                font: selectModel.font
                color: selectModel.pressed ? "#FFFFFF" : "#FFFFFF"
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            //This will change the main box background color, border color,  and the border color when pressed.
            //The second color is the main color. The first item is what color the changes to once clicked.
            background: Rectangle {
                implicitWidth: 120
                implicitHeight: 40
                color: "#000000"
                border.color: selectModel.pressed ? "#FFFFFF" : "#FFFFFF"
                border.width: selectModel.visualFocus ? 2 : 1
                radius: 2
            }

            popup: Popup {
                y: selectModel.height - 1
                width: selectModel.width
                implicitHeight: contentItem.implicitHeight
                padding: 1

                contentItem: ListView {
                    clip: true
                    implicitHeight: contentHeight
                    model: selectModel.popup.visible ? selectModel.delegateModel : null
                    currentIndex: selectModel.highlightedIndex

                    ScrollIndicator.vertical: ScrollIndicator { }
                }

                //This will change the color of the drop down Rectangle
                background: Rectangle {
                    border.color: "#FFFFFF"
                    color: "#FFFFFF"
                    radius: 5
                }
            }
        }

        Rectangle {
            id: infoTextRect
            x: 260
            y: 97
            width: 750
            height: 332
            color: "#000000"
            border.color: "#ffffff"

            ScrollView {
                id: scrollView
                x: 4
                y: 4
                width: 742
                height: 324

                TextArea {
                    id: mainWinTextArea
                    x: -7
                    y: -3
                    color: "#ffffff"
                    text: ""
                    placeholderText: qsTr("Text Area")
                    background: Rectangle {color: "black"}
                }
            }
        }

        ComboBox {
            id: selectNuclide
            x: 260
            y: 638
            width: 750
            height: 21
            visible: false
            contentItem: Text {
                color: selectNuclide.pressed ? "#FFFFFF" : "#FFFFFF"
                text: selectNuclide.displayText
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
                rightPadding: selectNuclide.indicator.width + selectNuclide.spacing
                leftPadding: 0
                font: selectNuclide.font
            }
            editable: false
            background: Rectangle {
                color: "#000000"
                radius: 2
                border.color: selectNuclide.pressed ? "#FFFFFF" : "#FFFFFF"
                border.width: selectNuclide.visualFocus ? 2 : 1
                implicitHeight: 40
                implicitWidth: 120
            }
            indicator: Canvas {
                x: selectNuclide.width - width - selectNuclide.rightPadding
                y: selectNuclide.topPadding + (selectNuclide.availableHeight - height) / 2
                width: 12
                height: 8
                onPaint: {
                    context.reset();
                    context.moveTo(0, 0);
                    context.lineTo(width, 0);
                    context.lineTo(width / 2, height);
                    context.closePath();
                    context.fillStyle = selectNuclide.pressed ? "#FFFFFF" : "#FFFFFF";
                    context.fill();
                }
                contextType: "2d"
                Connections {
                    target: selectNuclide
                }
            }
            delegate: ItemDelegate {
                width: selectNuclide.width
                contentItem: Text {
                    color: "#000000"
                    text: selectNuclide.textRole
                          ? (Array.isArray(selectNuclide.model) ? modelData[selectNuclide.textRole] : model[selectNuclide.textRole])
                          : modelData
                    elide: Text.ElideRight
                    verticalAlignment: Text.AlignVCenter
                    font: selectNuclide.font
                }
                highlighted: selectNuclide.highlightedIndex === index
            }
            model: ["Select Nuclide", "2H1+","4He0+"]
            popup: Popup {
                y: selectNuclide.height - 1
                width: selectNuclide.width
                contentItem: ListView {
                    implicitHeight: contentHeight
                    model: selectNuclide.popup.visible ? selectNuclide.delegateModel : null
                    ScrollIndicator.vertical: ScrollIndicator {
                    }
                    clip: true
                    currentIndex: selectNuclide.highlightedIndex
                }
                background: Rectangle {
                    color: "#ffffff"
                    radius: 5
                    border.color: "#ffffff"
                }
                implicitHeight: contentItem.implicitHeight
                padding: 1
            }
        }

        Rectangle {
            id: rectangle
            x: 940
            y: 665
            width: 76
            height: 22
            visible: false
            color: "#000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: storagePathRect
            x: 348
            y: 451
            width: 662
            height: 22
            color: "#000000"
            border.color: "#ffffff"

            TextEdit {
                id: storagePathTextedit
                x: 2
                y: 2
                width: 658
                height: 18
                color: "#ffffff"
                text: qsTr("")
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: atomicNumRect
            x: 349
            y: 499
            width: 82
            height: 22
            color: "#000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: numProtonsRect
            x: 442
            y: 499
            width: 101
            height: 22
            color: "#000000"
            border.color: "#ffffff"
        }

        TextEdit {
            id: atomicNumTextEdit
            x: 350
            y: 501
            width: 79
            height: 19
            color: "#ffffff"
            text: qsTr("")
            font.pixelSize: 12
        }

        TextEdit {
            id: numProtonsTxtEdit
            x: 443
            y: 501
            width: 98
            height: 19
            color: "#ffffff"
            text: qsTr("")
            font.pixelSize: 12
        }

        Text {
            id: massNumLabel
            x: 349
            y: 483
            width: 75
            height: 16
            color: "#ffffff"
            text: qsTr("Mass number")
            font.pixelSize: 12
        }

        Text {
            id: atomicMassLabel
            x: 443
            y: 483
            width: 72
            height: 16
            color: "#ffffff"
            text: qsTr("Atomic mass")
            font.pixelSize: 12
        }


    }

    Rectangle {
        id: viewWin
        x: 0
        y: 0
        width: 1280
        height: 720
        visible: true
        color: "#000000"

        Image {
            id: image2
            x: 0
            y: 0
            width: 1280
            height: 720
            source: "file:C:/Newclides/images/bg.png"
            fillMode: Image.PreserveAspectFit

            Text {
                id: text3
                x: 1063
                y: 55
                width: 58
                height: 33
                color: "#ffffff"
                text: qsTr("Step:")
                font.pixelSize: 23
            }
        }







        Image {
            id: upArrow
            x: 616
            y: 326
            width: 49
            height: 49
            visible: false
            source: "file:C:/Newclides/images/up_arrow.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x1
            x: 598
            y: 285
            width: 30
            height: 30
            visible: false
            source: "images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }
        Image {
            id: x2
            x: 653
            y: 285
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }
        Image {
            id: x5
            x: 598
            y: 381
            width: 30
            height: 30
            visible: false
            source: "images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }
        Image {
            id: x4
            x: 653
            y: 381
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }
        Image {
            id: x6
            x: 567
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x9
            x: 726
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x10
            x: 679
            y: 411
            width: 30
            height: 30
            visible: false
            source: "images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x11
            x: 572
            y: 411
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x15
            x: 769
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x16
            x: 705
            y: 441
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x17
            x: 546
            y: 441
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x21
            x: 813
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x23
            x: 520
            y: 471
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x22
            x: 732
            y: 471
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x27
            x: 858
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x33
            x: 903
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x39
            x: 947
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x45
            x: 991
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x51
            x: 1035
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x57
            x: 1080
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x60
            x: 171
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x54
            x: 214
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x48
            x: 258
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x42
            x: 303
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x36
            x: 348
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x30
            x: 392
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x24
            x: 436
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x18
            x: 480
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x12
            x: 525
            y: 333
            width: 30
            height: 30
            visible: false
            source: "images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x28
            x: 758
            y: 501
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }
        Image {
            id: x3
            x: 680
            y: 333
            width: 30
            height: 30
            visible: false
            source: "images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x34
            x: 784
            y: 531
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x40
            x: 810
            y: 561
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x46
            x: 836
            y: 591
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x52
            x: 862
            y: 621
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x58
            x: 888
            y: 651
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x29
            x: 494
            y: 501
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x35
            x: 470
            y: 530
            width: 30
            height: 30
            visible: false
            source: "images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x41
            x: 444
            y: 560
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x47
            x: 418
            y: 590
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x53
            x: 392
            y: 620
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x59
            x: 366
            y: 650
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x55
            x: 358
            y: 14
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x49
            x: 384
            y: 44
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x43
            x: 411
            y: 74
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x37
            x: 437
            y: 104
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x31
            x: 463
            y: 134
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x25
            x: 489
            y: 164
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x19
            x: 515
            y: 194
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x13
            x: 541
            y: 224
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x7
            x: 567
            y: 254
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x56
            x: 890
            y: 15
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x50
            x: 864
            y: 45
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x44
            x: 838
            y: 75
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x38
            x: 812
            y: 105
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x32
            x: 788
            y: 134
            width: 30
            height: 30
            visible: false
            source: "images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x26
            x: 762
            y: 164
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x20
            x: 736
            y: 194
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x14
            x: 710
            y: 224
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x8
            x: 684
            y: 254
            width: 30
            height: 30
            visible: false
            source: "images/neutron.png"
            fillMode: Image.PreserveAspectFit
        }

        Label {
            id: identifiedNuclideLabel
            x: 1062
            y: 15
            width: 185
            height: 44
            color: "#ffffff"
            text: qsTr("")
            font.bold: true
            font.pointSize: 21
        }
    }


    Image {
        id: logo
        x: 1088
        y: 676
        width: 184
        height: 36
        source: "file:C:/Newclides/images/logo2.png"
        //source: "images/logoB.png"
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        id: sideBar
        x: 0
        y: 0
        width: 65
        height: 720
        opacity: 0.112
        color: "#ffffff"
    }

    Image {
        id: homeBtn
        x: 8
        y: 20
        width: 50
        height: 50
        source: "file:C:/Newclides/images/homeBtn.png"
        fillMode: Image.PreserveAspectFit

        MouseArea {
            id: homeBtnMouseArea
            width: 50
            height: 50
            onClicked: {
                mainWin.visible = true
                viewWin.visible = false
            }
        }
    }

    Image {
        id: viewerBtn
        x: 8
        y: 91
        width: 50
        height: 50
        source: "file:C:/Newclides/images/viewerBtn.png"
        fillMode: Image.PreserveAspectFit

        MouseArea {
            id: viewerBtnMouseArea
            width: 50
            height: 50
            onClicked: {
                viewWin.visible = true
                mainWin.visible = false
            }
        }
    }

    Image {
        id: image3
        x: 8
        y: 662
        width: 50
        height: 50
        source:  "file:C:/Newclides/images/GmenuClose.png"
        fillMode: Image.PreserveAspectFit
    }
}
