import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1024
    height: 768

    Calculator{
        id: calc
        x:0
        y:0
        visible: false
        enabled: false

    }
    Matching{
        id: match
        x:0
        y:0
        visible: false
        enabled: false
    }

    TextButton{
        id : but1
        text : "Calculator"
        x: parent.width/2 - width/2
        y: 1*parent.height/4 - height/2
        onClicked:
        {
            but1.visible=false
            but1.enabled=false
            but2.visible=false
            but2.enabled=false
            but3.visible=false
            but3.enabled=false
            calc.visible=true
            calc.enabled=true
        }
    }
    TextButton{
        id : but2
        text : "Match 2"
        x: parent.width/2 - width/2
        y: 2*parent.height/4 - height/2
        onClicked:
        {
            but1.visible=false
            but1.enabled=false
            but2.visible=false
            but2.enabled=false
            but3.visible=false
            but3.enabled=false
            match.visible=true
            match.enabled=true
        }
    }
    TextButton{
        id : but3
        text : "Quit"
        x: parent.width/2 - width/2
        y: 3*parent.height/4 - height/2
        onClicked:
        {
            Qt.quit()
        }
    }


   /* Rectangle
    {
        width: parent.width
        height: parent.height
        Text {
            text: qsTr("Hello World")
            anchors.centerIn: parent
        }
    }*/

}
