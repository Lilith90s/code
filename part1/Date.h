#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Date
{
public:
	Date();
	Date(string date);
	unsigned StrmonToIntMon(string);
	~Date();

public:
	unsigned year;
	unsigned month;
	unsigned day;


private:
	string DevideBy(string,string);
	vector<string> mon = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	string number = "0123456789";

};

