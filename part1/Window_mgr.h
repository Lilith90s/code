#pragma once



#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Screen.h"


using namespace std;
 class Window_mgr
{

public:
	//������ÿ����Ļ�ı��
	using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex i);
	Window_mgr();
	ScreenIndex addScreen(const Screen&);

	~Window_mgr();
private:
	//���window_mgr׷�ٵ�Screen
	//Ĭ������£�һ��window_mgr����һ����׼�ߴ�Ŀհ�Screen
	std::vector<Screen> screens{ Screen(24, 80, ' ') };

};



void Window_mgr::clear(ScreenIndex i)
{
	//sָ������յ���Ļ
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}