#include "stdafx.h"
#include "Date.h"


Date::Date()
{
}

Date::Date(string date)
{
	string henggang = "-";
	string xiegang = "/";
	string coma = ",";
	string number = "0123456789";
	string month;
	string sign;

	unsigned flag = 0;

	if (date.find_first_of(henggang) != string::npos)
	{
		sign = henggang;
	}
	if (date.find_first_of(xiegang) != string::npos)
	{
		sign = xiegang;
	}
	if (date.find_first_of(coma)!=string::npos)
	{
		sign = coma;
	}

	DevideBy(date, sign);

}

unsigned Date::StrmonToIntMon(string smonth)
{
	for (int i = 0; i < 12; i++)
	{
		if (smonth == mon[i])
			return i + 1;
	}

	return 15;
}


Date::~Date()
{
}

string Date::DevideBy(string src,string sign)
{
	unsigned pos = 0, pos1 = 0, pos2 = 0, pos3 = 0;
	unsigned _pos, _pos1;
	

	if ((pos1 = src.find_first_of(sign,pos))!=string::npos)
	{
		year = stoul(src.substr(pos, pos1 - pos));
		//cout << pos << " : " << pos1 << endl;
	}
	pos = pos1 + 1;
	if ((pos1 = src.find_first_of(sign, pos)) != string::npos)
	{
		string smonth;
		smonth = src.substr(pos, pos1 - pos);
		//cout << pos << " : " << pos1 << endl;
		month = StrmonToIntMon(smonth);
		if (month == 15)
		{
			month = stoul(smonth);
		}
	}
	pos = pos1 + 1;
	if ((pos1 = src.find_first_of(sign, pos)) != string::npos)
	{
		day = stoul(src.substr(pos, pos1 - pos));
		//cout << pos << " : " << pos1 << endl;
	}

	cout << "分割前" << endl;
	cout << src << endl;
	cout << "分割后" << endl;
	cout << "年：" << year << " 月：" << month  << " 日：" << day << endl;
	
	return string();
}
