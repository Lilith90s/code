#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
using namespace std;
#pragma once
class TextQuery
{
public:
	TextQuery();
	TextQuery(ifstream& infile);
	int Find_words(string words);
	int print_result();
	int clear();

	~TextQuery();
private:
	vector<string> lines;
	map<int, string> result;
};

