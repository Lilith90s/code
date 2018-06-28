#include "stdafx.h"
#include "Person.h"
#include <iostream>
using namespace std;


Person::Person()
{

}


Person::~Person()
{
}

void Person::setname(const string sname)
{
	istream& read(istream & is, Person & person);
	read(cin, *this);
}

void Person::setaddress(const string saddress)
{
	ostream& print(ostream & os, const Person & person);
	print(cout, *this);
}

istream& read(istream & is, Person & person)
{
	cout << "Input name and address:";
	is >> person.name >> person.address; 
	return is;
	// 接受一个io类型的引用作为第一个参数，io类属于不能拷贝的类型，所以只能使用引用来传递
}

ostream& print(ostream & os, const Person & person)
{
	cout << "Output name and address:";
	os << person.name << "  " << person.address;
	return os;
	// TODO: 在此处插入 return 语句
}

