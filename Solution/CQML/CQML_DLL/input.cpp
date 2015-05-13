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
CQMLEventQueue * eventQueue;

CQMLEventQueue * MakeQueue()
{
	CQMLEventQueue * queue = (CQMLEventQueue*)malloc(sizeof(CQMLEventQueue));
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

int PushEvent(CQMLEvent inputEvent)
{

	CQMLEventQueueNode * newNode;
	newNode=(CQMLEventQueueNode*)malloc(sizeof(CQMLEventQueueNode));
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

CQMLEvent PopEvent()
{
	CQMLEventQueueNode * firstNode;
	CQMLEvent nodeEvent;
	//lock();
	firstNode=eventQueue->headNode2;
	if(firstNode==0)
	{
		//unlock();
		nodeEvent.EventType=CQML_INVALID_EVENT;
		return nodeEvent;
	}

	nodeEvent=firstNode->nodeEvent;
	eventQueue->headNode2=firstNode->nextNode;

	free(firstNode);
	//unlock();
	return nodeEvent;
}


void ProcessMouseEvent(CQMLMouseEvent * mouseEvent)
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

void ProcessKeyboardEvent(CQMLKeyboardEvent * keyEvent)
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

void ProcessEvent(CQMLEvent * processedEvent)
{
	if(processedEvent->EventType==CQML_KEY_EVENT)
	{
		ProcessKeyboardEvent(&processedEvent->keyEvent);
	}
	else if(processedEvent->EventType==CQML_MOUSE_EVENT)
	{
		ProcessMouseEvent(&processedEvent->mouseEvent);
	}
}


void processEvents()
{
	CQMLEvent node;
	SwapActiveQueue();
	while(1)
	{
		node=PopEvent();
		if(node.EventType!=CQML_INVALID_EVENT)
		{
			ProcessEvent(&node);
		}
		else break;
	}
}

void CQMLInitInput()
{
	eventQueue=MakeQueue();
	InitQueueThreadsafe();
}

CQMLEvent MakeEvent()
{
	CQMLEvent Event;
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