#include "stdafx.h"
#include "head_part2.h"

using namespace std::placeholders;


int main()
{
	

	//在C的末尾构造一个person对象
	//使用三个参数的person构造函数
	//vector<Person> c;
	//c.emplace_back("zhangjun","nj");

	//pushback只能创建一个临时的person对象，再传递给push_back
	//c.push_back(Person("yituanjun","cs"));
	//DeleteForward_List();
	//forward_list<string> f1 = { "luoaotian","nanjing","liyang" };
	//InsertForward_List_After_String(f1,"luoaotian","yituanjun");
	
	size_t size1 = 0;
	size_t size2 = 0;
	vector<string> vec;
	string input;
	istringstream in(input);
	//sum = accumulate(vec.begin(), vec.end(), string(""));
	//vector<double> vecdou;
	//double sum = accumulate(vecdou.begin(), vecdou.end(), 0.0);
	ifstream file("test.txt");
	
	runQueries(file);
	
	system("pause");
	return 0;
	
}

