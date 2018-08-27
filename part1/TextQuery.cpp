#include "stdafx.h"
#include "TextQuery.h"


TextQuery::TextQuery()
{

}

TextQuery::TextQuery(ifstream& infile)
{
	string line;
	while (getline(infile,line))
	{
		lines.push_back(line);
	}
}

int TextQuery::Find_words(string words)
{
	
	int line_count=1;
	int pos;
	for (auto  it = lines.begin(); it != lines.end(); it++)
	{
		bool flag = true;
		if ((pos = (*it).find(words, 0)) != string::npos )
		{
			
			if (pos - 1 > 0)
			{
				flag = !isalpha((*it)[pos - 1]);
			}
			if (pos + words.size() < (*it).size())
			{
				flag = !isalpha((*it)[pos + words.size()]);
			}
			result.insert(make_pair(line_count, (*it)));
		}
		line_count++;
	}
	return 0;
}

int TextQuery::print_result()
{
	for (auto it = result.begin(); it != result.end(); it++)
	{
		printf("	(line %d) %s \n", it->first, (it->second).c_str());
	}
	return 0;
}

int TextQuery::clear()
{
	result.clear();
	return 0;
}


TextQuery::~TextQuery()
{
	TextQuery::clear();
}
