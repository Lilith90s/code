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
	// ����һ��io���͵�������Ϊ��һ��������io�����ڲ��ܿ��������ͣ�����ֻ��ʹ������������
}

ostream& print(ostream & os, const Person & person)
{
	cout << "Output name and address:";
	os << person.name << "  " << person.address;
	return os;
	// TODO: �ڴ˴����� return ���
}

