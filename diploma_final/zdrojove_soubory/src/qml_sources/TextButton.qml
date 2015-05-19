import QtQuick 2.0

MouseArea {
    width: 600
    height: 140
    hoverEnabled: true
    property int pressed : 0
    property int entered : 0
    property string pressedImg : "pics/button_long_down.png"
    property string overImg: "pics/button_long_over.png"
    property string defImg: "pics/button_long.png"
    property alias text : txt.text

    onPressed:
    {
        pressed=1
        im.source= pressedImg
    }
    onReleased:
    {
        pressed=0
        if(entered==1) im.source= overImg
        else im.source= defImg
    }
    onEntered:
    {
        entered = 1
        if(pressed==1) im.source= pressedImg
        else im.source= overImg
    }
    onExited:
    {
        entered = 0
        im.source= defImg
    }

    Image {
        id : im;
        anchors.fill : parent
        source: defImg
    }

    Text{
        id: txt;
        anchors.fill : parent
        text : "Button"
        font.family: "Arial"
        font.pixelSize: parent.height/4
        color : "white"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

    }
}

