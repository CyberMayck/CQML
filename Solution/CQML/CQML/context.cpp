#include "context.h"

QML_Context * acQML_Context(GUI_Group * g, GUI_Element * e)
{
	QML_Context * context;
	context = (QML_Context *)malloc(sizeof(context));
	context->root=g;
	context->self=e;
	return context;
}
