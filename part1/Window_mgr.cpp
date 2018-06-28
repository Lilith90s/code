#include "stdafx.h"
#include "Window_mgr.h"

Window_mgr::Window_mgr()
{
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}


Window_mgr::~Window_mgr()
{
}
