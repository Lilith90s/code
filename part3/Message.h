#pragma once
#include <vector>
#include <iostream>
#include <set>
#include "Folder.h"
using namespace std;
class Message
{
	friend class Folder;
public:
	~Message();
	//folders 被隐式初始化为空集合
	explicit Message(const string &str = "") :contents(str) {};
	//拷贝控制成员，用来管理指向本message的指针
	Message(const Message&);						//拷贝构造函数
	Message& operator = (const Message&);		//拷贝赋值运算符

	void save(Folder&);
	void remove(Folder&);

private:
	string contents;						//实际消息文本
	set<Folder*> folders;				//包含本message的Folder
	//拷贝构造函数、赋值运算符和析构函数所使用的工具函数
	//将本message添加到指向参数的folder中
	void add_to_Folders(const Message&);
	//从folders中的每个folder中删除本message
	void remove_from_Folders();
	void swap(Message &lhs, Message &rhs);

};

