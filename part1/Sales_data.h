//本程序将令sales_data类支持与sales_item类完全一样的操作集合  
//sales_data的接口应该包括以下操作  
//一个isbn成员函数，用于返回对象的ISBN编号  
//一个combine成员函数，用于将一个sales_data对象加到另一个对象上  
//接口函数  
//一个add的函数，执行两个sales_data对象的加法  
//一个read函数，将数据从istream读入到sales_data对象中  
//一个print函数，将sales_data对象的值输出到ostream中  

#ifndef SALES_DATA_H  
#define SALES_DATA_H  

#include"stdafx.h"
#include<iostream>  
#include<string>  
using namespace std;
class sales_data
{
private:
	string bookno;//书号  
	double units_sold;//销售出的册数  
	double price;//单本售价  
	double revenue;//总销售额  
	double average;

public:
	sales_data();//声明一个无参的构造函数  
	sales_data(string b, int u, double p) :bookno(b), units_sold(u), price(p) {}//声明一个有参数的默认构造函数，用参数的初始化表对数据成员初始化  
	friend istream& operator >> (istream &, sales_data &);//运算符>>重载为友元函数  
	friend ostream& operator << (ostream &, sales_data &);//运算符<<重载为友元函数  
	friend sales_data operator + (sales_data & lhs, sales_data & rhs);//声明有元的运算符重载 + 函数  
	sales_data& operator = (const sales_data &);//重载赋值运算符  
	friend bool operator == (sales_data &, sales_data &);//声明有元的重载双目运算符==函数  
	sales_data & operator += (const sales_data &);//声明一个返回sales_item类型的重载运算符+=函数，形参采用常量引用  
	double avg_price();
	string isbn() const;//声明isbn函数，并返回书籍号  
						//一个combine成员函数，用于将一个sales_data对象加到另一个对象上  
	sales_data& combine(const sales_data &);
	//声明sales_data类的非成员接口函数  
	//一个read函数，将数据从istream读入到sales_data对象中  
	friend istream & read(istream &, sales_data &);//声明一个read函数，函数返回类型为istream &  
												   //一个add的函数，执行两个sales_data对象的加法  
	friend sales_data add(const sales_data &, const sales_data &);

};
sales_data::sales_data()//定义无参数的构造函数  
{
	bookno = "null";
	units_sold = 0;
	price = 0.0;
}

istream& operator >>(istream &input, sales_data &s)//对重载运算符>>进行定义  
{
	input >> s.bookno >> s.units_sold >> s.price;
	if (input)
	{
		s.revenue = s.units_sold * s.price;
	}
	return input;
}
ostream& operator << (ostream &output, sales_data &s)//对重载运算符<<进行定义  
{
	//output << s.bookno << " "<< s.units_sold << " " << s.revenue << " " << s.price << endl;  
	output << s.bookno << " " << s.units_sold << " " << s.revenue << " " << s.avg_price() << endl;
	return output;
}
//将两个sales_item对象相加时，程序应该检测其两个对象的isbn书号是否相同  
sales_data operator + (sales_data & lhs, sales_data & rhs)//定义重载运算符+函数,lhs和rhs是sales_item的对象  
{
	sales_data ret;
	ret.bookno = lhs.bookno;
	ret.units_sold = lhs.units_sold + rhs.units_sold;
	ret.revenue = lhs.revenue + rhs.revenue;
	ret.avg_price();
	return ret;
}
bool operator == (sales_data &lhs, sales_data &rhs)
{
	return lhs.units_sold == rhs.units_sold && lhs.price == rhs.price && lhs.isbn() == rhs.isbn();
}
sales_data& sales_data:: operator = (const sales_data &lhs)//重载赋值运算符=  
{
	bookno = lhs.bookno;
	units_sold = lhs.units_sold;
	price = lhs.price;
	return *this;
}
sales_data& sales_data ::operator += (const sales_data &rhs)//  
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;//将this对象作为左值返回,*this相当于一个sales_item对象  
}
double sales_data::avg_price()
{
	average = revenue / units_sold;
	return average;
}
string sales_data::isbn() const
{
	return bookno;
}
//一个combine成员函数，用于将一个sales_data对象加到另一个对象上  
sales_data& sales_data::combine(const sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
istream & read(istream &input, sales_data &rhs)//声明一个read函数，将数据从istream读入到sales_data对象中  
{
	input >> rhs.bookno >> rhs.units_sold >> rhs.price;
	rhs.revenue = rhs.units_sold * rhs.price;
	return input;
}

sales_data add(const sales_data &lhs, const sales_data &rhs)//一个add的函数，执行两个sales_data对象的加法  
{
	sales_data sum = lhs;
	sum.combine(rhs);
	sum.avg_price();
	return sum;
}
#endif 
