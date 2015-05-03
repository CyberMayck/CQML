#include "dll_export.h"


#include "input.h"
#include "gui.h"

#ifndef WIN32
#define WIN32
#endif
#include <stdlib.h>

#ifdef WIN32
#include<windows.h>
 #include <stdio.h>
HANDLE queueMutex;

namespace CQMLGUI{
void InitQueueThreadsafe()
{
	queueMutex=CreateMutex(NULL,FALSE,L"queueMutex");
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
};

#include "gui.h"
extern CQMLGUI::Element * lastPressed;
namespace CQMLGUI
{

CQMLGUI::Element* root;
void SetRoot(void* p)
{
	root=(Element*)p;
}
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
	lock();

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


void ProcessMouseEvent(QMLMouseEvent * mouseEvent)
{
//	int a;
	switch(mouseEvent->action)
	{
	case MOUSE_BUTTON_PRESSED:
		root->MousePressed(mouseEvent->x,mouseEvent->y,mouseEvent->button);
		break;
	case MOUSE_BUTTON_RELEASED:
		root->MouseReleased(mouseEvent->x,mouseEvent->y,mouseEvent->button);
		lastPressed=0;
		break;
	case MOUSE_WHEEL_SCROLLED:
		root->MouseScrolled(mouseEvent->x,mouseEvent->y,mouseEvent->relativeX,mouseEvent->relativeX);
		break;
	case MOUSE_MOVEMENT:
		root->MouseMoved(mouseEvent->x,mouseEvent->y,mouseEvent->relativeX,mouseEvent->relativeX);
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
		root->KeyPressed(keyEvent->key);
	case KEY_RELEASED:
		root->KeyReleased(keyEvent->key);
	default:
		break;
	}
}

void ProcessEvent(QMLEvent * processedEvent)
{
	if(processedEvent->EventType==QML_KEY_EVENT)
	{
		ProcessKeyboardEvent(&processedEvent->keyEvent);
	}
	else if(processedEvent->EventType==QML_MOUSE_EVENT)
	{
		ProcessMouseEvent(&processedEvent->mouseEvent);
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

void SetRoot(CQMLGUI::Element* r)
{
	root=r;
}

};