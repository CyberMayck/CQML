import QtQuick 2.0
import "SameLogic.js" as CalcLogic

Rectangle {
    width : 1024
    height: 768
    color : "white"
    BorderImage
    {
        source: "pics/button_square.png"
        x:parent.width/5-75
        y:0
        border.top: 60
        border.left: 60
        border.right: 60
        border.bottom: 60
        width:3*parent.width/5+150
        height:150
        Text
        {
            id: outputLine
            //anchors.fill : parent
            x:40
            width: parent.width
            height : parent.height
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            color : "black"
            font.family: "Arial"
            font.pixelSize: parent.height/2
            text : {return CalcLogic.getOutput()}
        }
    }

    CalculatorButton{
        x:parent.width - 120
        y:25
        width:100
        height:100
        text: "C"
        onClicked : { outputLine.text=CalcLogic.reset() }
    }

    CalculatorButton{
        x:4*parent.width/5 - width/2
        y:150
        text: "+"
        onClicked : { outputLine.text=CalcLogic.setOp('+') }
    }
    CalculatorButton{
        x:4*parent.width/5 - width/2
        y:300
        text: "-"
        onClicked : { outputLine.text=CalcLogic.setOp('-') }
    }
    CalculatorButton{
        x:4*parent.width/5 - width/2
        y:450
        text: "*"
        onClicked : { outputLine.text=CalcLogic.setOp('*') }
    }
    CalculatorButton{
        x:4*parent.width/5 - width/2
        y:600
        text: "/"
        onClicked : { outputLine.text=CalcLogic.setOp('/') }
    }

    CalculatorButton{
        x:1*parent.width/5 - width/2
        y:150
        text: "7"
        onClicked : { outputLine.text=CalcLogic.setNum(7) }
    }
    CalculatorButton{
        x:2*parent.width/5 - width/2
        y:150
        text: "8"
        onClicked : { outputLine.text=CalcLogic.setNum(8) }
    }
    CalculatorButton{
        x:3*parent.width/5 - width/2
        y:150
        text: "9"
        onClicked : { outputLine.text=CalcLogic.setNum(9) }
    }
    CalculatorButton{
        x:1*parent.width/5 - width/2
        y:300
        text: "4"
        onClicked : { outputLine.text=CalcLogic.setNum(4) }
    }
    CalculatorButton{
        x:2*parent.width/5 - width/2
        y:300
        text: "5"
        onClicked : { outputLine.text=CalcLogic.setNum(5) }
    }
    CalculatorButton{
        x:3*parent.width/5 - width/2
        y:300
        text: "6"
        onClicked : { outputLine.text=CalcLogic.setNum(6) }
    }
    CalculatorButton{
        x:1*parent.width/5 - width/2
        y:450
        text: "1"
        onClicked : { outputLine.text=CalcLogic.setNum(1) }
    }
    CalculatorButton{
        x:2*parent.width/5 - width/2
        y:450
        text: "2"
        onClicked : { outputLine.text=CalcLogic.setNum(2) }
    }
    CalculatorButton{
        x:3*parent.width/5 - width/2
        y:450
        text: "3"
        onClicked : { outputLine.text=CalcLogic.setNum(3) }
    }
    CalculatorButton{
        x:parent.width/5 - width/2
        y:600
        text: "0"
        onClicked : { outputLine.text=CalcLogic.setNum(0) }
    }
    CalculatorButton{
        x:2*parent.width/5 - width/2
        y:600
        text: ","
        onClicked : { outputLine.text=CalcLogic.comma() }
    }
    CalculatorButton{
        x:3*parent.width/5 - width/2
        y:600
        text: "="
        onClicked : { outputLine.text=CalcLogic.setOp('=') }
    }
}

