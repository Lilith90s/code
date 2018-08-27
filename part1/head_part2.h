#pragma once
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include "Person.h"
#include <deque>
#include <forward_list>
#include <Windows.h>
#include "Date.h"
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <memory>
#include <map>
#include "TextQuery.h"

istream& myread(istream &is);
istream& readtovector(istream &is);
void getdeque();
void DeleteForward_List();
void InsertForward_List_After_String(forward_list<string> &, string, string);
void CopyForward_List();
void SearchString();
void SearchMiddleWord();
void CountStl();
void ElimDups(vector<string> &words);
bool isShorter(const string &s1, const string&s2);
void predicatSort();
void testFilln();
bool biggerThan5(string);
void parditionTest(int);
void testStablePardition();
string make_plural(size_t ctr, const string &word, const string &ending);
vector<vector<int>> transpose(vector<vector<int> >& A);
class Solution;
bool isPrime(int n);
int primePalindrome(int N);
bool ispalind(int n);
int testCount_if();
int testCheck_size();
int myfunction();
int fileStreamToVec();
int sortFromStream();
int classifyFile();
int wordsCount();
int vectorPointer(shared_ptr<vector<int>> pv);
void printVector(shared_ptr<vector<int>> pv);
void runQueries(ifstream &infile);


class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob() {};
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); };
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	string& front();
	string& back();

	~StrBlob() {};

private:
	std::shared_ptr < std::vector<std::string> > data;
	void check(size_type i, const std::string &msg)const;
};


inline void StrBlob::check(size_type i, const string & msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

inline string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
	// TODO: 在此处插入 return 语句
}

inline string & StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
	// TODO: 在此处插入 return 语句
}

inline void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
