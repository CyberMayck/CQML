#pragma once



#include "dll_export.h"

#include <unordered_map>
#include <vector>
#include <string>
struct ImageData
{
	void * img;
	int width;
	int height;
};

struct ResourceManagerIface
{
	virtual void * LoadFont(const char *, int size) = 0;
	virtual ImageData LoadImage(const char *) = 0;
};

CQML_API int SetResourceManager(ResourceManagerIface *);
struct InternalResourceManager
{
	InternalResourceManager();
	int TryLoadFont(std::string font, int size);
	int TryLoadImage(std::string imagePath);
	void LoadImages();
	void LoadFonts();

	ResourceManagerIface * manager;
	std::unordered_map<std::string, void*> fonts;
	std::unordered_map<std::string, ImageData> images;
	std::vector<std::string> fontLoadQueue;
	std::vector<int> fontSizeLoadQueue;
	std::vector<std::string> imageLoadQueue;
};
extern InternalResourceManager resourceManager;

