#pragma once


#include "dll_export.h"

#define CQML_KEY_EVENT			(0)
#define CQML_MOUSE_EVENT			(1)
#define CQML_INVALID_EVENT		(-1)
//#define QUIT_EVENT  		(2)


#define KEY_PRESSED				(0)
#define KEY_RELEASED			(1)

#define MOUSE_BUTTON_PRESSED	(0)
#define MOUSE_BUTTON_RELEASED	(1)
#define MOUSE_WHEEL_SCROLLED	(2)
#define MOUSE_MOVEMENT			(3)

namespace CQMLGUI
{

struct CQMLMouseEvent
{
	int action;
	int button;
	int x;
	int y;
	int relativeX;
	int relativeY;
};

struct CQMLKeyboardEvent
{
	int action;
	int key;
};

struct CQMLEvent
{
	int EventType;

	union
	{
		CQMLMouseEvent mouseEvent;
		CQMLKeyboardEvent keyEvent;
	};
};

struct CQMLEventQueueNode
{
	CQMLEvent nodeEvent;
	CQMLEventQueueNode * nextNode;
};

struct CQMLEventQueue
{
	CQMLEventQueueNode * headNode;
	CQMLEventQueueNode * tailNode;
	CQMLEventQueueNode * headNode2;
};

//extern CQMLEventQueue * eventQueue;
CQML_API void SetRoot(void*);
CQML_API CQMLEventQueue* MakeQueue();
CQML_API int PushEvent(CQMLEvent);
CQML_API CQMLEvent PopEvent();
CQML_API void SwapActiveQueue();
CQML_API void InitQueueThreadsafe();
CQML_API void processEvents();
CQML_API void CQMLInitInput();
CQML_API CQMLEvent MakeEvent();

};

