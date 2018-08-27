#pragma once
#include<string>
using namespace std;
class Person
{
public:
	Person();
	Person(const string desname,const string destaddress);
	~Person();
	const std::string getname() { return this->name; }
	const std::string getadress() { return this->address; }
	void setname(string name);
	void setaddress(string address);


	friend istream& read(istream & is, Person & person);
	friend ostream& print(ostream & os, const Person & person);

private:
	std::string name;
	std::string address;

};

