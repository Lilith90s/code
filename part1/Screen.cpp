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
	++access_ctr;		//����һ������ֵ�����ڼ�¼��Ա���������õĴ���
	//�ó�Ա������Ҫ��ɵ���������
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


char Screen::get(pos r, pos c)const		//������ڲ�������inline
{
	pos row = r * width;						//�����е�λ��
	return contents[row + c];					//���ظ����е��ַ�
}