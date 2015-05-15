#include "dll_export.h"

#include "resource_manager.h"

using namespace std;
InternalResourceManager resourceManager;

/**
 * Sets resource manager interface
 * 
 *
 * @param pointer to instane of interface
 *
 * @return 1
 */
int SetResourceManager(ResourceManagerIface *m)
{
	resourceManager.manager= m;
	return 1;
}


/**
 * Constructor.
 * Initializes internal resource manager.
 */
InternalResourceManager::InternalResourceManager()
{
	manager=0;
}

/**
 * Loads all queued images
 * 
 */
void InternalResourceManager::LoadImages()
{
	for(unsigned int i=0;i<imageLoadQueue.size();i++)
	{
		string &txt=imageLoadQueue[i];
		if(images.count(txt)>0)
		{
		}
		else
		{
			ImageData  img= manager->LoadImage(txt.c_str());

			images[txt]=img;
		}
	}
	imageLoadQueue.clear();
}

/**
 * Loads all queued fonts.
 * 
 */
void InternalResourceManager::LoadFonts()
{
	for(unsigned int i=0;i<fontLoadQueue.size();i++)
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
	fontLoadQueue.clear();
	fontSizeLoadQueue.clear();
}

/**
 * Creates load request for font
 * 
 *
 * @param font name
 * @param font size
 *
 * @return 1
 */
int InternalResourceManager::TryLoadFont(string txt, int size)
{
	fontLoadQueue.push_back(txt);
	fontSizeLoadQueue.push_back(size);
	return 1;
}

/**
 * Creates load request for image
 * 
 *
 * @param image path
 *
 * @return 1
 */
int InternalResourceManager::TryLoadImage(string path)
{
	imageLoadQueue.push_back(path);
	return 1;
}


