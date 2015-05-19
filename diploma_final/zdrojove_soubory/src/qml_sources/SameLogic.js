var val = 0
var curNum=0
var curMultipl=0
var isNew=1
var curOp='='

var output=0

function reset()
{
    val = 0
    curNum=0
    curMultipl=0
    isNew=1
    curOp='='
    return getOutput()
}

function comma()
{
    if(curMultipl<1)
        curMultipl=10
    return getOutput()
}

function setNum(num)
{
    isNew=0
    if(curMultipl<1)
    {
        curNum=curNum*10+num
    }
    else
    {
        curNum=curNum+num/(curMultipl)
        curMultipl=curMultipl*10
    }
    return getOutput()
}

function setOp(op){
    //console.log(op)
    if(curOp!='=')
    {
        if(curOp=='+')
        {
            val=val+curNum
        }
        else if(curOp=='-')
        {
            val=val-curNum
        }
        else if(curOp=='*')
        {
            val=val*curNum
        }
        else if(curOp=='/')
        {
            val=val/curNum
        }
    }
    else
    {
        val=curNum
    }

    isNew=1
    curNum=0
    curMultipl=0
    curOp=op
    return getOutput()
}

function getOutput() {
    if(isNew==1)
        return val
    else
        return curNum
}

