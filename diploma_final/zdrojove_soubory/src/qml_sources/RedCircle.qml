import QtQuick 2.0

NormalButton
{
    id:thisButton
    width: 100
    height: 100
    property int value : 0
    property Rectangle matcher;

    onClicked:{
        if(matcher.status==0)
        {
            matcher.first=thisButton
            matcher.firstValue=value;
            matcher.status=1;
            thisButton.enabled=false;
        }
        else if(matcher.status==1)
        {
            matcher.status=0;
            if(matcher.firstValue==value)
            {
                matcher.score=matcher.score+value+1
                matcher.first.destroy()
                thisButton.destroy()
                if(17==matcher.score)
                {
                    matcher.winMsg.visible=true
                }
            }
            else
            {
                matcher.first.enabled=true;
            }

        }
    }

    pressedImg :
    {
        if(value==0)
        {
            return "pics/red_round_down.png"
        }
        else if(value==1)
        {
            return "pics/green_round_down.png"
        }
        else if(value==2)
        {
            return "pics/blue_round_down.png"
        }
        else
        {
            return "pics/yellow_round_down.png"
        }

    }
    overImg:
    {
        if(value==0)
        {
            return "pics/red_round_over.png"
        }
        else if(value==1)
        {
            return "pics/green_round_over.png"
        }
        else if(value==2)
        {
            return "pics/blue_round_over.png"
        }
        else
        {
            return "pics/yellow_round_over.png"
        }
    }
    defImg:
    {
        if(value==0)
        {
            return "pics/red_round.png"
        }
        else if(value==1)
        {
            return "pics/green_round.png"
        }
        else if(value==2)
        {
            return "pics/blue_round.png"
        }
        else
        {
            return "pics/yellow_round.png"
        }
    }
}

