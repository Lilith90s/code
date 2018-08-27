#include "stdafx.h"
#include "Message.h"



Message::Message(const Message &m):contents(m.contents),folders(m.folders)
{
	add_to_Folders(m); //将本消息添加到指向m的folder中
}

Message & Message::operator=(const Message &rhs)
{
	// 通过先删除指针再插入他们来处理自赋值情况
	remove_from_Folders();//更新已有folder
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void Message::swap(Message & lhs, Message & rhs)
{
	using std::swap;
	//将每个消息的指针从它原来的folder中删除
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	//交换contents和folder指针set
	swap(lhs.folders, rhs.folders);			//使用swap（set&，set&）
	swap(lhs.contents, rhs.contents);	//使用swap（string&，string&）
	//将每个message的指针添加到它的新folder中
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

Message::~Message()
{
	remove_from_Folders();
}
