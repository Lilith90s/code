// part3.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Chapter13.h"



int main()
{
	HasPtr h1("hello");
	HasPtr h2 = h1.f(h1);
	h1.PrintString();
	h2.PrintString();
	system("pause");
	
	return 0;
}


