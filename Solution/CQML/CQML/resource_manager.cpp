#include "resource_manager.h"

using namespace std;
InternalResourceManager resourceManager;

int SetResourceManager(ResourceManagerIface *m)
{
	resourceManager.manager= m;
	return 1;
}

InternalResourceManager::InternalResourceManager()
{
	manager=0;
}

int InternalResourceManager::TryLoadFont(string txt)
{
	if(fonts.count(txt)>0)
	{
	}
	else
	{
		void * font=manager->LoadFont(txt.c_str());
		fonts[txt]=font;
	}
	return 1;
}

int InternalResourceManager::TryLoadImage(string path)
{
	if(fonts.count(path)>0)
	{
	}
	else
	{
		void * img=manager->LoadImage(path.c_str());
		fonts[path]=img;
	}
	return 1;
}


