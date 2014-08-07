#ifndef QML_INPUT_H
#define QML_INPUT_H

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

typedef struct QMLEvent QMLEvent;
typedef struct QMLKeyboardEvent QMLKeyboardEvent;
typedef struct QMLMouseEvent QMLMouseEvent;
typedef struct QMLEventQueue QMLEventQueue;
typedef struct QMLEventQueueNode QMLEventQueueNode;

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

extern QMLEventQueue * eventQueue;

QMLEventQueue* MakeQueue();
int PushEvent(QMLEvent);
QMLEvent PopEvent();
void SwapActiveQueue();
void InitQueueThreadsafe();
void processEvents();
void QMLInitInput();
QMLEvent MakeEvent();

#endif