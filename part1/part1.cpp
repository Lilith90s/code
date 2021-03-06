// part1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "Person.h"
#include "Screen.h"
#include "Entrust.h"

using namespace std;

void in_vector();	//vector存取
void vstrToup(vector<string> vstr);		//使用vector 将输入单词小写字母改为大写
void widefor();		//范围for函数
void exp_3_17();
void DoubleVector();
inline void PrintTitle(const string title) { cout << "this Function is from C++ Primer :" << title << endl; }
void div();
void printNDEBUG();


int main()
{
	//widefor(); 
	//in_vector();
	//vstrToup();
	//exp_3_17();
	//DoubleVector();
	//div();
	printNDEBUG();
	//Person my;
	//Screen::pos ht = 24, wd = 80;
	//Screen myScreen(5, 5, 'X');
	//myScreen.move(4, 0).set('#').display(cout);
	//cout << endl;
	//myScreen.display(cout);
	//cout << endl;
	//Entrust en(cin);
	system("pause");
	return 0;
}



void printNDEBUG()
{
	cout << __func__ << endl;
	cout << __FILE__ << endl;
	cout << __TIME__ ;
	cout << __DATE__ << endl;
	cout << __LINE__ << endl;
}

void DoubleVector()
{
	PrintTitle("3.23");
	vector<int> iv{ 1,2,3,4,5,6,7,8,9,10 };

	for (auto it = iv.begin(); it != iv.end(); it++)
	{
		(*it) = (*it) * 2;
		cout << (*it)<< " ";
	}
	cout << endl;
}

void div()
{
	int a;
	int b;
	float result;
	while (1)
	{
		try
		{
			cout << "Please input A:";
			cin >> a;
			cout << "Please input B:";
			cin >> b;
			if (b == 0)
				throw runtime_error("b is can not be 0");
		}
		catch (runtime_error err)
		{
			while (b==0)
			{
				cin.clear();
				cout << endl;
				cout << err.what() << "\nInput B again" << endl;
				cin >> b;
			}
		}

		result = static_cast<float>(a)/ b;
		cout << "the result is " << result << endl;
		break;
	}

}

void exp_3_17()
{
	PrintTitle("3.17");
	vector<string> vstr;
	string n;
	cout << "请输入要转换大写的字符串" << endl;
	while (cin >> n)
	{
		vstr.push_back(n);
	}
	vstrToup(vstr);
}

void vstrToup(vector<string> vstr)
{
	PrintTitle("3.17(P94)");
	
	const int MAX = 20;
	char *str=new char[MAX];
	while (cin >> str)
		vstr.push_back(str);
	
	for (unsigned int i = 0; i < vstr.size(); i++)
	{
		for (unsigned int j = 0; j < vstr[i].length(); j++)
			vstr[i][j] = toupper(vstr[i][j]);
		cout << vstr[i] << endl;
	}
}

void in_vector()
{
	PrintTitle("3.14(P91)");
	vector<int> vn;
	const int MAX=5;
	int na[MAX];
	for (int i = 0; i < MAX; i++)
	{
		cin >> na[i];
		vn.push_back(na[i]);
	}
	for (int i = 0; i < MAX; i++)
		cout << vn[i] << endl;
	system("pause");
}

void widefor()	
{	
	PrintTitle("3.6");
	string s1;
	cout << "输入需要转换为X的字符串" << endl;
	getline(cin, s1);
	if (!s1.empty())
	{
		for (auto &c : s1)
			c = 'X';
		cout << s1 << endl;
	}
	else
		cout << "您输入的字符串为空" << endl;
	system("pause");
}

