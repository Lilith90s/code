#pragma once
#include <iostream>
#include <string>
using namespace std;
class Entrust
{
public:
	Entrust(string s, int a, int b) :book(s), price(a), sale(b) { cout << "1" << endl; }
	Entrust() :Entrust("", 0, 0) { cout << price << endl; }
	Entrust(istream &is) :Entrust() { cout << "3" << endl; }

	~Entrust();

	string book;
	int price;
	int sale;
};

