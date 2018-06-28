#include "stdafx.h"
#include "Screen.h"


Screen::Screen()
{

}


Screen::~Screen()
{

}


void Screen::some_member() const
{
	++access_ctr;		//保存一个技术值，用于记录成员函数被调用的次数
	//该成员函数需要完成的其他工作
}

void Screen::dummy_fcn(pos height)
{
	cursor = width * this->height;
	cursor = width * Screen::height;
}

Screen::pos Screen::size() const
{
	return height * width;
}


char Screen::get(pos r, pos c)const		//在类的内部声明称inline
{
	pos row = r * width;						//计算行的位置
	return contents[row + c];					//返回给定列的字符
}