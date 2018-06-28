#pragma once



#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Screen.h"


using namespace std;
 class Window_mgr
{

public:
	//窗口中每个屏幕的编号
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex i);
	Window_mgr();
	ScreenIndex addScreen(const Screen&);

	~Window_mgr();
private:
	//这个window_mgr追踪的Screen
	//默认情况下，一个window_mgr包含一个标准尺寸的空白Screen
	std::vector<Screen> screens{ Screen(24, 80, ' ') };

};



void Window_mgr::clear(ScreenIndex i)
{
	//s指向想清空的屏幕
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}