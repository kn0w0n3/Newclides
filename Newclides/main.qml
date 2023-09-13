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
            idNuclideTxtLabel.text = identifiedNuclide_
        }
        onModelDirPathToQml:{
            modelDirTxtEdit.text = _modelDir
        }
        onLoadModelNuclideId:{
            idNuclideLabel.visible = true
            idNuclideTxtLabel.visible = true
            idNuclideTxtLabel.text = nuclideId
        }
        onModelStepNumber:{
            stepLabel.visible = true
            stepTxtLabel.visible = true
            stepTxtLabel.text = _stepNumber
        }
        onModelStepSpin:{
            if(_spin === "up"){
                upArrow.visible = true
                levelLebelTxtNum.text = "-1"
                levelLebelTxtNum.visible = true
                downArrow.visible = false
            }
            else if(_spin === "down"){
                upArrow.visible = false
                levelLebelTxtNum.text = "+1"
                levelLebelTxtNum.visible = true
                downArrow.visible = true
            }
        }
        onIdNuclideNameToQml:{
            nuclideNameLabel.visible = true
            nuclideNameLabel.text = idNuclideName
        }

        onX1ToQml:{
            if(x1Val === "N"){
                console.log("Recieving new model data x1.........." + x1Val)
                x1.visible = true
                x61.visible = false
            }
            else if(x1Val === "P"){
                console.log("Recieving new model data x1.........." + x1Val)
                x1.visible = false
                x61.visible = true                
            }
        }
        onX2ToQml:{
            if(x2Val === "N"){
                console.log("Recieving new model data x2.........." + x2Val)
                x2.visible = true
                x62.visible = false
            }
            else if(x2Val === "P"){
                console.log("Recieving new model data x2.........." + x2Val)

                x2.visible = false
                x62.visible = true
            }
        }
        onX3ToQml:{
            if(x3Val === "N"){
                console.log("Recieving new model data x3.........." + x3Val)
                x3.visible = true
                x63.visible = false
            }
            else if(x3Val === "P"){
                console.log("Recieving new model data x3.........." + x3Val)
                x63.visible = true
                x3.visible = false
            }
        }
        onX4ToQml:{
            if(x4Val === "N"){
                console.log("Recieving new model data x4.........." + x4Val)
                x4.visible = true
                x64.visible = false
            }
            else if(x4Val === "P"){
                console.log("Recieving new model data x4.........." + x4Val)
                x64.visible = true
                x4.visible = false
            }
        }
        onX5ToQml:{
            if(x5Val === "N"){
                console.log("Recieving new model data x5........" + x5Val)
                x5.visible = true
                x65.visible = false
            }
            else if(x5Val === "P"){
                console.log("Recieving new model data x5........" + x5Val)
                x65.visible = true
                x5.visible = false
            }
        }
        onX6ToQml:{
            if(x6Val === "N"){
                console.log("Recieving new model data x6........" + x6Val)
                x6.visible = true
                x66.visible = false
            }
            else if(x6Val === "P"){
                console.log("Recieving new model data x6........" + x6Val)
                x66.visible = true
                x6.visible = false
            }
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
            width: 87
            height: 16
            color: "#ffffff"
            text: qsTr("Atomic number")
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

            Label {
                id: stepLabel
                x: 599
                y: 498
                width: 49
                height: 33
                visible: false
                color: "#ffffff"
                text: qsTr("Step:")
                font.bold: false
                font.pointSize: 17
            }

            Label {
                id: stepTxtLabel
                x: 658
                y: 500
                width: 82
                height: 33
                visible: false
                color: "#ffffff"
                text: qsTr("")
                font.bold: false
                font.pointSize: 17
            }
        }


        Image {
            id: upArrow
            x: 613
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
            source: "file:C:/Newclides/images/neutron.png"
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
            id: x3
            x: 680
            y: 333
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/neutron.png"
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
            id: x5
            x: 598
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
            id: x8
            x: 684
            y: 254
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
            source: "file:C:/Newclides/images/neutron.png"
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
            id: x12
            x: 525
            y: 333
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
            source: "file:C:/Newclides/images/neutron.png"
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
            source: "file:C:/Newclides/images/neutron.png"
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




        Label {
            id: idNuclideTxtLabel
            x: 1170
            y: 21
            width: 102
            height: 33
            color: "#ffffff"
            text: qsTr("")
            font.bold: true
            font.pointSize: 19
        }

        Image {
            id: x61
            x: 598
            y: 285
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x62
            x: 650
            y: 282
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x63
            x: 677
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x64
            x: 650
            y: 378
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x65
            x: 595
            y: 378
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x66
            x: 564
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x67
            x: 564
            y: 251
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x68
            x: 681
            y: 251
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x69
            x: 723
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x70
            x: 676
            y: 408
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x71
            x: 569
            y: 408
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x72
            x: 522
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x73
            x: 538
            y: 221
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x74
            x: 707
            y: 221
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x75
            x: 766
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x76
            x: 702
            y: 438
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x77
            x: 543
            y: 438
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x78
            x: 477
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x79
            x: 512
            y: 191
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x80
            x: 733
            y: 191
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x81
            x: 810
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x82
            x: 517
            y: 468
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x83
            x: 729
            y: 468
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x84
            x: 855
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x85
            x: 900
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x86
            x: 944
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x87
            x: 988
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x88
            x: 1032
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x89
            x: 1077
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x90
            x: 168
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x91
            x: 211
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x92
            x: 255
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x93
            x: 300
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x94
            x: 345
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x95
            x: 389
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x96
            x: 433
            y: 330
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x97
            x: 755
            y: 498
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x98
            x: 781
            y: 528
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x99
            x: 807
            y: 558
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x100
            x: 833
            y: 588
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x101
            x: 859
            y: 618
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x102
            x: 885
            y: 648
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x103
            x: 491
            y: 498
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x104
            x: 467
            y: 527
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x105
            x: 441
            y: 557
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x106
            x: 415
            y: 587
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x107
            x: 389
            y: 617
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x108
            x: 363
            y: 647
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x109
            x: 355
            y: 11
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x110
            x: 381
            y: 41
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x111
            x: 408
            y: 71
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x112
            x: 434
            y: 101
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x113
            x: 460
            y: 131
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x114
            x: 486
            y: 161
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x115
            x: 887
            y: 12
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x116
            x: 861
            y: 42
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x117
            x: 835
            y: 72
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x118
            x: 809
            y: 102
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x119
            x: 785
            y: 131
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: x120
            x: 759
            y: 161
            width: 30
            height: 30
            visible: false
            source: "file:C:/Newclides/images/proton.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: downArrow
            x: 615
            y: 325
            width: 49
            height: 49
            visible: false
            source: "file:C:/Newclides/images/up_arrow.png"
            rotation: -179.649
            fillMode: Image.PreserveAspectFit
        }

        Label {
            id: idNuclideLabel
            x: 969
            y: 21
            width: 190
            height: 33
            visible: true
            color: "#ffffff"
            text: qsTr("Identified Nuclide:")
            font.pointSize: 17
        }

        Image {
            id: selectModelDirBtn
            x: 231
            y: 588
            width: 78
            height: 24
            source: "file:C:/Newclides/images/selectDirBtn.png"
            MouseArea {
                id: selectModelDirMouseArea
                width: 78
                height: 24
                onClicked: {
                    mainController.selectModelDirectory()
                }
            }
            fillMode: Image.PreserveAspectFit
        }

        Rectangle {
            id: modelDirPathRect
            x: 322
            y: 589
            width: 662
            height: 22
            color: "#000000"
            border.color: "#ffffff"
            TextEdit {
                id: modelDirTxtEdit
                x: 2
                y: 2
                width: 658
                height: 18
                color: "#ffffff"
                text: qsTr("")
                font.pixelSize: 12
            }
        }

        Image {
            id: leftArrowBtn
            x: 415
            y: 504
            width: 78
            height: 24
            source: "file:C:/Newclides/images/leftArrowBtn.png"
            MouseArea {
                id: leftArrowMouseArea
                width: 78
                height: 24
                onClicked: {
                    if(stepTxtLabel.text === "1"){

                    }
                    else{
                        console.log("2The lable text is " + stepTxtLabel.text)

                        console.log("2The lable text is now" + stepTxtLabel.text)
                        mainController.modelViewerStepControl(stepTxtLabel.text, "L")
                        //upArrow.visible = false;
                        //downArrow.visible = false;
                        //x1.visible = false; x2.visible = false; x3.visible = false; x4.visible = false; x5.visible = false; x6.visible = false;
                        //x7.visible = false; x8.visible = false; x9.visible = false; x10.visible = false; x11.visible = false; x12.visible = false;

                        //x61.visible = false; x62.visible = false; x63.visible = false; x64.visible = false; x65.visible = false; x66.visible = false;
                        //x67.visible = false; x68.visible = false; x69.visible = false; x70.visible = false; x71.visible = false; x72.visible = false;
                    }
                }
            }
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: rightArrowBtn
            x: 809
            y: 504
            width: 78
            height: 24
            source: "file:C:/Newclides/images/arrowRightBtn.png"
            MouseArea {
                id: rightArrowMouseArea
                width: 78
                height: 24
                onClicked: {
                    console.log("The lable text is " + stepTxtLabel.text)

                    console.log("The lable text is now " + stepTxtLabel.text)
                    mainController.modelViewerStepControl(stepTxtLabel.text, "R")
                    //change model step
                   // upArrow.visible = false;
                   // downArrow.visible = false;
                    //x1.visible = false; x2.visible = false; x3.visible = false; x4.visible = false; x5.visible = false; x6.visible = false;
                    //x7.visible = false; x8.visible = false; x9.visible = false; x10.visible = false; x11.visible = false; x12.visible = false;

                    //x61.visible = false; x62.visible = false; x63.visible = false; x64.visible = false; x65.visible = false; x66.visible = false;
                    //x67.visible = false; x68.visible = false; x69.visible = false; x70.visible = false; x71.visible = false; x72.visible = false;
                }
            }
            fillMode: Image.PreserveAspectFit
        }

        Label {
            id: levelLabel
            x: 423
            y: 81
            width: 62
            height: 37
            color: "#ffffff"
            text: qsTr("Level")
            font.bold: false
            font.pointSize: 20
        }

        Label {
            id: spinLabel
            x: 821
            y: 81
            width: 55
            height: 37
            color: "#ffffff"
            text: qsTr("Spin")
            font.bold: false
            font.pointSize: 20
        }

        Label {
            id: levelLebelTxtNum
            x: 431
            y: 336
            width: 35
            height: 29
            visible: false
            color: "#ffffff"
            text: qsTr("-1")
            font.pointSize: 20
        }

        Image {
            id: loadModelBtn
            x: 323
            y: 621
            width: 78
            height: 24
            source: "file:C:/Newclides/images/loadBtn.png"
            fillMode: Image.PreserveAspectFit
        }

        MouseArea {
            id: loadModelMouseArea
            x: 323
            y: 621
            width: 78
            height: 24
            onClicked: {
                mainController.loadModelData(modelDirTxtEdit.text)
            }
        }

        Image {
            id: closeModelBtn
            x: 910
            y: 621
            width: 78
            height: 24
            source: "file:C:/Newclides/images/closeBtn.png"
            fillMode: Image.PreserveAspectFit
        }

        MouseArea {
            id: closeModelBtnMouseArea
            x: 910
            y: 621
            width: 78
            height: 24
            onClicked: {
                //close the model
                //x1.visible = false; x2.visible = false; x3.visible = false; x4.visible = false; x5.visible = false; x6.visible = false;
                //x7.visible = false; x8.visible = false; x9.visible = false; x10.visible = false; x11.visible = false; x12.visible = false;

                //x61.visible = false; x62.visible = false; x63.visible = false; x64.visible = false; x65.visible = false; x66.visible = false;
                //x67.visible = false; x68.visible = false; x69.visible = false; x70.visible = false; x71.visible = false; x72.visible = false;
                mainController.clearLoadedModelFileList()
            }
        }

        Label {
            id: nuclideNameLabel
            x: 1170
            y: 66
            width: 168
            height: 35
            visible: false
            color: "#ffffff"
            text: qsTr("")
            font.pointSize: 14
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
