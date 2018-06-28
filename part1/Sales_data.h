//��������sales_data��֧����sales_item����ȫһ���Ĳ�������  
//sales_data�Ľӿ�Ӧ�ð������²���  
//һ��isbn��Ա���������ڷ��ض����ISBN���  
//һ��combine��Ա���������ڽ�һ��sales_data����ӵ���һ��������  
//�ӿں���  
//һ��add�ĺ�����ִ������sales_data����ļӷ�  
//һ��read�����������ݴ�istream���뵽sales_data������  
//һ��print��������sales_data�����ֵ�����ostream��  

#ifndef SALES_DATA_H  
#define SALES_DATA_H  

#include"stdafx.h"
#include<iostream>  
#include<string>  
using namespace std;
class sales_data
{
private:
	string bookno;//���  
	double units_sold;//���۳��Ĳ���  
	double price;//�����ۼ�  
	double revenue;//�����۶�  
	double average;

public:
	sales_data();//����һ���޲εĹ��캯��  
	sales_data(string b, int u, double p) :bookno(b), units_sold(u), price(p) {}//����һ���в�����Ĭ�Ϲ��캯�����ò����ĳ�ʼ��������ݳ�Ա��ʼ��  
	friend istream& operator >> (istream &, sales_data &);//�����>>����Ϊ��Ԫ����  
	friend ostream& operator << (ostream &, sales_data &);//�����<<����Ϊ��Ԫ����  
	friend sales_data operator + (sales_data & lhs, sales_data & rhs);//������Ԫ����������� + ����  
	sales_data& operator = (const sales_data &);//���ظ�ֵ�����  
	friend bool operator == (sales_data &, sales_data &);//������Ԫ������˫Ŀ�����==����  
	sales_data & operator += (const sales_data &);//����һ������sales_item���͵����������+=�������ββ��ó�������  
	double avg_price();
	string isbn() const;//����isbn�������������鼮��  
						//һ��combine��Ա���������ڽ�һ��sales_data����ӵ���һ��������  
	sales_data& combine(const sales_data &);
	//����sales_data��ķǳ�Ա�ӿں���  
	//һ��read�����������ݴ�istream���뵽sales_data������  
	friend istream & read(istream &, sales_data &);//����һ��read������������������Ϊistream &  
												   //һ��add�ĺ�����ִ������sales_data����ļӷ�  
	friend sales_data add(const sales_data &, const sales_data &);

};
sales_data::sales_data()//�����޲����Ĺ��캯��  
{
	bookno = "null";
	units_sold = 0;
	price = 0.0;
}

istream& operator >>(istream &input, sales_data &s)//�����������>>���ж���  
{
	input >> s.bookno >> s.units_sold >> s.price;
	if (input)
	{
		s.revenue = s.units_sold * s.price;
	}
	return input;
}
ostream& operator << (ostream &output, sales_data &s)//�����������<<���ж���  
{
	//output << s.bookno << " "<< s.units_sold << " " << s.revenue << " " << s.price << endl;  
	output << s.bookno << " " << s.units_sold << " " << s.revenue << " " << s.avg_price() << endl;
	return output;
}
//������sales_item�������ʱ������Ӧ�ü�������������isbn����Ƿ���ͬ  
sales_data operator + (sales_data & lhs, sales_data & rhs)//�������������+����,lhs��rhs��sales_item�Ķ���  
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
sales_data& sales_data:: operator = (const sales_data &lhs)//���ظ�ֵ�����=  
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
	return *this;//��this������Ϊ��ֵ����,*this�൱��һ��sales_item����  
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
//һ��combine��Ա���������ڽ�һ��sales_data����ӵ���һ��������  
sales_data& sales_data::combine(const sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
istream & read(istream &input, sales_data &rhs)//����һ��read�����������ݴ�istream���뵽sales_data������  
{
	input >> rhs.bookno >> rhs.units_sold >> rhs.price;
	rhs.revenue = rhs.units_sold * rhs.price;
	return input;
}

sales_data add(const sales_data &lhs, const sales_data &rhs)//һ��add�ĺ�����ִ������sales_data����ļӷ�  
{
	sales_data sum = lhs;
	sum.combine(rhs);
	sum.avg_price();
	return sum;
}
#endif 
