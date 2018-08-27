#include "stdafx.h"
#include "StrVec.h"


StrVec::StrVec()
{
}


StrVec::~StrVec()
{
	free();
}

StrVec::StrVec(const StrVec &s)
{
	//调用alloc_n_copy分配空间以容纳与s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_tree = cap = newdata.second;
}

StrVec & StrVec::operator=(const StrVec &rhs)
{
	// 调用alloc_n_copy分配内存，大小与rhs中元素占用空间一样多
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_tree = cap = data.second;
	return *this;
}

StrVec & StrVec::operator=(StrVec && rhs) noexcept
{
	// TODO: 在此处插入 return 语句
	//直接检测自赋值
	if (this != &rhs)
	{
		free();//释放已有元素
		elements = rhs.elements;//从rhs接管资源
		first_tree = rhs.first_tree;
		cap = rhs.cap;
		//将rhs置于可析构状态
		rhs.elements = rhs.first_tree = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();//确保有空间容纳新元素
	//在first_free指向的元素中构造s的副本
	alloc.construct(first_tree++, s);
}

void StrVec::chk_n_alloc()
{
	if (size() == capacity())
		reallocate();
}

pair<string*, string*> StrVec::alloc_n_copy(const string *e, const string *b)
{
	//分配空间保存给定范围中的元素
	auto data = alloc.allocate(e - b);
	//初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
	return { data,uninitialized_copy(b,e,data) };
	
}

void StrVec::free()
{
	//不能传递给deallocate一个空指针，如果element为0，函数什么也不做
	if (elements)
	{
		//逆序销毁旧元素
		for (auto p = first_tree; p != elements;)
		{
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	//我们将分配当前大小两倍的内存空间
	auto newcapacity = size() ? 2 * size() : 1;
	//分配新内存
	auto newdata = alloc.allocate(newcapacity);
	//将数据从旧内存移动到新内存
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); i++)
	{
		alloc.construct(dest++, move(*elem++));
	}
	free();//释放旧内存空间
	//更新数据结构，执行新元素
	elements = newdata;
	first_tree = dest;
	cap = elements + newcapacity;
}
