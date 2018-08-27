#pragma once
#include "Chapter13.h"
class StrVec
{
public:
	StrVec() ://成员默认初始化
		elements(nullptr), first_tree(nullptr), cap(nullptr) {};
	~StrVec();

	StrVec(const StrVec&);							//拷贝构造函数
	StrVec(StrVec &&s) noexcept //移动操作不应该抛出任何异常
		//成员初始化器接管s中的资源
		:elements(s.elements), first_tree(s.first_tree), cap(s.cap)
	{
		//令s进入这样的状态-----对其运行析构函数是安全的
		s.elements = s.first_tree = s.cap = nullptr;
	}

	StrVec& operator = (const StrVec&);		//拷贝赋值运算符
	StrVec& operator = (StrVec &&rhs) noexcept;
	void push_back(const string &);				//拷贝元素
	size_t size() const { return first_tree - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_tree; }
private:
	static allocator<string> alloc;//分配元素
	//被添加元素的函数所使用
	void chk_n_alloc();
	//工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();              //销毁元素并释放内存
	void reallocate();    //获得耕读的内存并拷贝已有元素
	string *elements;   //指向数组首元素的指针
	string *first_tree;   //指向数组第一个空闲元素的指针
	string *cap;           //指向数组尾后位置的指针
};

