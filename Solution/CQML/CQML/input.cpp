#include "input.h"
#include "gui.h"

#define WIN32

#include <stdlib.h>
#ifdef WIN32
#include<windows.h>
 #include <stdio.h>
HANDLE queueMutex;

void InitQueueThreadsafe()
{
	queueMutex=CreateMutex(NULL,FALSE,"queueMutex");
}

void lock()
{
	WaitForSingleObject(queueMutex, INFINITE);
}

void unlock()
{
	ReleaseMutex(queueMutex);
}

//CreateMutex(NULL, FALSE, MName);
#else
#include <pthread>;
pthread_mutex_t queueMutex;
void InitQueueThreadsafe()
{
	queueMutex = PTHREAD_MUTEX_INITIALIZER;
}
void lock()
{
	pthread_mutex_lock( &queueMutex );
}
void unlock()
{
	pthread_mutex_unlock( &queueMutex );
}

#endif

#include "gui.h"

extern GUI_Element* root;
QMLEventQueue * eventQueue;

QMLEventQueue * MakeQueue()
{
	QMLEventQueue * queue = (QMLEventQueue*)malloc(sizeof(QMLEventQueue));
	queue->headNode=0;
	queue->headNode2=0;
	queue->tailNode=0;
	return queue;
}

void SwapActiveQueue()
{
	//QMLEventQueueNode * tmp=0;
	lock();
	//tmp=queue->headNode2;
	//queue->headNode2=queue->headNode;
	//queue->headNode=tmp;
	eventQueue->headNode2=eventQueue->headNode;
	eventQueue->headNode=0;
	eventQueue->tailNode=0;
	unlock();
}

int PushEvent(QMLEvent inputEvent)
{

	QMLEventQueueNode * newNode;
	newNode=(QMLEventQueueNode*)malloc(sizeof(QMLEventQueueNode));
	newNode->nextNode=0;
	newNode->nodeEvent=inputEvent;

	lock();
	if(eventQueue->tailNode!=0)
	{
		eventQueue->tailNode->nextNode=newNode;
	}
	else
	{
		eventQueue->headNode=newNode;
	}
	eventQueue->tailNode=newNode;
	unlock();
	return 1;
}

QMLEvent PopEvent()
{
	QMLEventQueueNode * firstNode;
	QMLEvent nodeEvent;
	//lock();
	firstNode=eventQueue->headNode2;
	if(firstNode==0)
	{
		//unlock();
		nodeEvent.EventType=QML_INVALID_EVENT;
		return nodeEvent;
	}

	nodeEvent=firstNode->nodeEvent;
	eventQueue->headNode2=firstNode->nextNode;

	free(firstNode);
	//unlock();
	return nodeEvent;
}


extern GUI_Element * lastPressed;

void ProcessMouseEvent(QMLMouseEvent * mouseEvent)
{
	switch(mouseEvent->action)
	{
	case MOUSE_BUTTON_PRESSED:
		root->MousePressed(root,mouseEvent->x,mouseEvent->y,mouseEvent->button);
		break;
	case MOUSE_BUTTON_RELEASED:
		root->MouseReleased(root,mouseEvent->x,mouseEvent->y,mouseEvent->button);
		lastPressed=0;
		break;
	case MOUSE_WHEEL_SCROLLED:
		root->MouseScrolled(root,mouseEvent->x,mouseEvent->y,mouseEvent->relativeX,mouseEvent->relativeX);
		break;
	case MOUSE_MOVEMENT:
		root->MouseMoved(root,mouseEvent->x,mouseEvent->y,mouseEvent->relativeX,mouseEvent->relativeX);
		break;
	default:
		break;
	}
}

void ProcessKeyboardEvent(QMLKeyboardEvent * keyEvent)
{
	switch(keyEvent->action)
	{
	case KEY_PRESSED:
		//root->KeyPressed(root,keyEvent->key);
	case KEY_RELEASED:
		//root->KeyReleased(root,keyEvent->key);
	default:
		break;
	}
}

void ProcessEvent(QMLEvent * processedEvent)
{
	if(processedEvent->EventType==QML_KEY_EVENT)
	{
		ProcessMouseEvent(&processedEvent->mouseEvent);
	}
	else if(processedEvent->EventType==QML_MOUSE_EVENT)
	{
		ProcessKeyboardEvent(&processedEvent->keyEvent);
	}
}


void processEvents()
{
	QMLEvent node;
	SwapActiveQueue();
	while(1)
	{
		node=PopEvent();
		if(node.EventType!=QML_INVALID_EVENT)
		{
			ProcessEvent(&node);
		}
		else break;
	}
}

void QMLInitInput()
{
	eventQueue=MakeQueue();
	InitQueueThreadsafe();
}

QMLEvent MakeEvent()
{
	QMLEvent Event;
	Event.EventType=-1;
	Event.mouseEvent.action=0;
	Event.mouseEvent.button=0;
	Event.mouseEvent.x=0;
	Event.mouseEvent.y=0;
	Event.mouseEvent.relativeX=0;
	Event.mouseEvent.relativeY=0;
	return Event;
}