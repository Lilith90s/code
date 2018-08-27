#include "stdafx.h"
#include "Chapter13.h"


Chapter13::Chapter13()
{
}


Chapter13::~Chapter13()
{
}

HasPtr HasPtr::f(HasPtr hp)
{
	HasPtr ret = hp;
	return ret;
}


class Numbered
{
public:
	Numbered() { static int count; count++;  };
	Numbered(Numbered& n) {}
	~Numbered();
	
private:
	bool flag=true;
};

Numbered::~Numbered()
{
}
