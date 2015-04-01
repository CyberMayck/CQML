#include "dll_export.h"

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

void InternalResourceManager::LoadImages()
{
	for(int i=0;i<imageLoadQueue.size();i++)
	{
		string &txt=imageLoadQueue[i];
		if(images.count(txt)>0)
		{
		}
		else
		{
			void * image=manager->LoadImage(txt.c_str());
			images[txt]=image;
		}
	}
}
void InternalResourceManager::LoadFonts()
{
	for(int i=0;i<fontLoadQueue.size();i++)
	{
		string &txt=fontLoadQueue[i];
		int size=fontSizeLoadQueue[i];
		string hashStr=txt+"__"+std::to_string(size);
		if(fonts.count(hashStr)>0)
		{
		}
		else
		{
			void * font=manager->LoadFont(txt.c_str(),size);
			fonts[hashStr]=font;
		}
	}
}

int InternalResourceManager::TryLoadFont(string txt, int size)
{
	fontLoadQueue.push_back(txt);
	fontSizeLoadQueue.push_back(size);
	return 1;
}

int InternalResourceManager::TryLoadImage(string path)
{
	imageLoadQueue.push_back(path);
	return 1;
}


