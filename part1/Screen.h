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
	char get()const														//��ȡ��괦���ַ�
	{																	
		return contents[cursor];                                        //��ʽ����
	}
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') {}
	inline char get(pos ht, pos wd) const;								//��ʽ����
	Screen &move(pos r, pos c);											//��֮����Ϊ����
	void some_member() const;											//const ��Ա����
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
	mutable size_t access_ctr;		//��ʹ��һ��const������Ҳ�ܱ��޸�
};

Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
	// TODO: �ڴ˴����� return ���
}

Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
	// TODO: �ڴ˴����� return ���
}

inline											//�����ں����Ķ��崦ָ��inline
Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;						//�����е�λ��
	cursor = row + c;							//�����ڽ�����ƶ���ָ������
	return *this;								//����ֵ����ʽ���ض���
}


