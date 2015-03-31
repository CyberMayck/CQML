#pragma once

#include <unordered_map>
#include <vector>
#include <string>

struct ResourceManagerIface
{
	virtual void * LoadFont(const char *) = 0;
	virtual void * LoadImage(const char *) = 0;
};

int SetResourceManager(ResourceManagerIface *);

struct InternalResourceManager
{
	InternalResourceManager();
	int TryLoadFont(string font);
	int TryLoadImage(string imagePath);

	ResourceManagerIface * manager;
	std::unordered_map<std::string, void*> fonts;
	std::unordered_map<std::string, void*> images;
	std::vector<std::string> fontLoadQueue;
	std::vector<std::string> imageLoadQueue;
};
extern InternalResourceManager resourceManager;

