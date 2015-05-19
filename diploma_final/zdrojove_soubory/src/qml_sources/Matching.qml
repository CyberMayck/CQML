import QtQuick 2.0

Rectangle {
    width : 1024
    height: 768
    color : "white"



    Rectangle{
        id: match
        x:parent.width/2-200
        y:150
        width:400
        height:400
        property RedCircle first
        property int firstValue
        property int score : 0
        property int status : 0
        property Text winMsg: win
        Text
        {
            id:win
            visible:false
            width: parent.width
            height : parent.height
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color : "black"
            font.family: "Arial"
            font.pixelSize: parent.height/2
            text : "You Win!!!"
        }
        Grid {
            rows:4
            columns:4
            RedCircle{matcher:match;value:0}
            RedCircle{matcher:match;value:2}
            RedCircle{matcher:match;value:1}
            RedCircle{matcher:match;value:3}

            RedCircle{matcher:match;value:3}
            RedCircle{matcher:match;value:1}
            RedCircle{matcher:match;value:2}
            RedCircle{matcher:match;value:0}

            RedCircle{matcher:match;value:0}
            RedCircle{matcher:match;value:2}
            RedCircle{matcher:match;value:2}
            RedCircle{matcher:match;value:0}

            RedCircle{matcher:match;value:0}
            RedCircle{matcher:match;value:1}
            RedCircle{matcher:match;value:0}
            RedCircle{matcher:match;value:1}
        }

        /*Column {
            Row{
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
            }
            Row{
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
            }
            Row{
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
            }
            Row{
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
                RedCircle{matcher:match;value:0}
            }
        }*/
    }
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
            //anchors.fill : parent
            x:40
            width: parent.width
            height : parent.height
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            color : "black"
            font.family: "Arial"
            font.pixelSize: parent.height/2
            text :
            {
                return match.score
            }
        }
    }
}

