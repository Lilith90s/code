#pragma once
#include <vector>
#include <iostream>
#include <set>
#include "Message.h"
using namespace std;
class Folder
{
public:
	Folder();
	~Folder();
	void addMsg(Message*);
	void remMsg(Message*);
private:
	set<Message*> Msgs;
};

