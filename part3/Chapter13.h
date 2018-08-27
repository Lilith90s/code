#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Chapter13
{
public:
	Chapter13();
	~Chapter13();
};

class HasPtr
{
	friend void swap(HasPtr &, HasPtr &);
	friend bool operator < (const HasPtr& s1, const HasPtr& s2);
	friend void show(vector<HasPtr>& vec);
public:
	HasPtr(const string& s = string()) :ps(new string(s)), i(0), use{ new size_t(1) } {};
	//拷贝构造函数
	HasPtr(const HasPtr& hp) :ps(new string(*hp.ps)), i(hp.i), use(hp.use) { ++*use; };
	//拷贝赋值运算符
	HasPtr& operator = (const HasPtr& p)
	{
		++*p.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = p.ps;
		use = p.use;
		i = p.i;
		return *this;
	}

	HasPtr() {};
	~HasPtr() { if (*use == 0) { delete ps; delete use; } };
	
	void PrintString() { cout << *ps << endl; };
	HasPtr f(HasPtr hp);
private:
	string *ps;
	size_t *use;
	int i;
};


inline void swap(HasPtr& a, HasPtr& b)
{
	using std::swap;
	swap(a.ps, b.ps);
	std::swap(a.i, b.i);
	cout << "123" << endl;
}

bool operator < (const HasPtr& s1, const HasPtr& s2)
{
	cout << "定义的operator < 被调用" << endl;
	return *s1.ps < *s2.ps;
}

void show(vector<HasPtr>& vec)
{
	//auto it1 = vec.begin();
	for (auto e : vec)
	{
		cout << e.ps << endl;
	}
}