#pragma once



#include <iostream>
#include <string>
#include "stdafx.h"



using namespace std;


class Screen
{
	
public:
	typedef string::size_type pos;
	friend class Window_mgr;

	inline Screen &set(char );
	inline Screen &set(pos , pos , char );
	Screen();
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) { }
	char get()const														//读取光标处的字符
	{																	
		return contents[cursor];                                        //隐式内联
	}
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') {}
	inline char get(pos ht, pos wd) const;								//显式内联
	Screen &move(pos r, pos c);											//在之后设为内联
	void some_member() const;											//const 成员函数
	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }
	pos size() const;
	void dummy_fcn(pos height);




	~Screen();
	
private:
	void do_display(std::ostream &os) const { os << contents; }

	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	mutable size_t access_ctr;		//即使在一个const对象内也能被修改
};

Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
	// TODO: 在此处插入 return 语句
}

Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
	// TODO: 在此处插入 return 语句
}

inline											//可以在函数的定义处指定inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;						//计算行的位置
	cursor = row + c;							//在行内将光标移动到指定的列
	return *this;								//以左值的形式返回对象
}


