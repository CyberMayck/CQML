#pragma once


#include "dll_export.h"

#define QML_KEY_EVENT			(0)
#define QML_MOUSE_EVENT			(1)
#define QML_INVALID_EVENT		(-1)
//#define QUIT_EVENT  		(2)


#define KEY_PRESSED				(0)
#define KEY_RELEASED			(1)

#define MOUSE_BUTTON_PRESSED	(0)
#define MOUSE_BUTTON_RELEASED	(1)
#define MOUSE_WHEEL_SCROLLED	(2)
#define MOUSE_MOVEMENT			(3)

namespace CQMLGUI
{

struct QMLMouseEvent
{
	int action;
	int button;
	int x;
	int y;
	int relativeX;
	int relativeY;
};

struct QMLKeyboardEvent
{
	int action;
	int key;
};

struct QMLEvent
{
	int EventType;

	union
	{
		QMLMouseEvent mouseEvent;
		QMLKeyboardEvent keyEvent;
	};
};

struct QMLEventQueueNode
{
	QMLEvent nodeEvent;
	QMLEventQueueNode * nextNode;
};

struct QMLEventQueue
{
	QMLEventQueueNode * headNode;
	QMLEventQueueNode * tailNode;
	QMLEventQueueNode * headNode2;
};

//extern QMLEventQueue * eventQueue;
CQML_API void SetRoot(void*);
CQML_API QMLEventQueue* MakeQueue();
CQML_API int PushEvent(QMLEvent);
CQML_API QMLEvent PopEvent();
CQML_API void SwapActiveQueue();
CQML_API void InitQueueThreadsafe();
CQML_API void processEvents();
CQML_API void QMLInitInput();
CQML_API QMLEvent MakeEvent();

};

