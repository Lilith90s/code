#include "stdafx.h"
#include "head_part2.h"
using namespace placeholders;
istream& readtovector(istream &is)
{
	string in;
	vector<string> vec;

	while (getline(is, in))
	{
		vec.push_back(in);
	}

	istringstream line;
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		string word;
		line.str(*it);
		while (line >> word)
		{
			cout << word << endl;
		}
		line.clear();
	}
	return is;
}

void getdeque()
{
	deque<string> que;
	string buf;
	while (cin >> buf)
	{
		if (buf == "end") break;
		que.push_back(buf);
	}

	auto it = que.begin();
	for (it; it != que.end(); it++)
	{
		cout << *it;
	}
}

void DeleteForward_List()
{
	forward_list<int> test = { 1,2,3,4,5,6,7,8,9,10 };
	auto prev = test.before_begin();
	auto curr = test.begin();
	while (curr != test.end())
	{
		if ((*curr) % 2 == 1)
		{
			curr = test.erase_after(prev);
		}
		else
		{
			prev = curr;
			curr++;
		}
	}
	for (auto it = test.begin(); it != test.end(); it++)
	{
		cout << *it << endl;
	}
	return void();
}

void InsertForward_List_After_String(forward_list<string>& test, string str1, string str2)
{
	bool flag = true;
	auto it1 = test.before_begin();
	auto it2 = test.begin();
	for (; it2 != test.end(); it1 = it2++)
	{
		if ((*it2) == str1)
		{
			test.insert_after(it2, str2);
			cout << *it2 << "插入" + str2 << endl;
			flag = false;
		}
	}
	if (flag)
	{
		test.insert_after(it1, str2);
	}
}

void CopyForward_List()
{
	forward_list<int> test = { 1,2,3,4,5,6,7,8,9 };
	auto it1 = test.before_begin();
	auto it2 = test.begin();
	while (it2 != test.end())
	{
		if ((*it2) % 2 == 1)
		{
			it2 = test.insert_after(it1, *it2);
			advance(it1, 2);
			advance(it2, 2);
		}
		else
		{
			it2 = test.erase_after(it1);
		}
	}
	for (auto it = test.begin(); it != test.end(); it++)
	{
		cout << *it << endl;
	}
}

void SearchString()
{
	string s1 = "ab2c3d7R4E6";
	string s2 = "0123456789";
	size_t pos = 0;
	while ((pos = s1.find_first_of(s2, pos)) != string::npos)
	{
		cout << s1[pos] << endl;
		++pos;
	}


}

void SearchMiddleWord()
{
	ifstream file("test.txt");
	string sfile;
	string check = "acenmorsuvwxz";
	string sub;
	size_t pos1 = 0, pos2 = 0, pos3 = 0, length = 0;
	file >> sfile;

	while ((pos1 = sfile.find_first_of(check, pos1)) != string::npos)
	{

		pos2 = pos1 + 1;
		pos2 = sfile.find_first_not_of(check, pos2);
		if (pos2 != string::npos)
		{
			length = pos2 - pos1;
			cout << sfile.substr(pos1, length);
			cout << pos1 << "--" << pos2 << endl;
		}
		else
		{
			length = sfile.size() - pos1;
			cout << sfile.substr(pos1, length);
			break;
		}
		pos1 = pos2;
	}
}

void CountStl()
{
	list<string> lis = { "one","one","two","ok" };

	auto result = count(lis.begin(), lis.end(), "one");
	cout << result << endl;
}

void ElimDups(vector<string>& words)
{
	//按字典序排序words，以便查找重复单词
	sort(words.begin(), words.end());
	//排列在范围的前部
	auto end_unique = unique(words.begin(), words.end());
	//删除重复单词
	words.erase(end_unique, words.end());
}

bool isShorter(const string & s1, const string & s2)
{
	return s1.size() < s2.size();
}

void predicatSort()
{
	vector<string> vecs = { "appleee","fox","jumps","over","quick","red","slow","the","the","turtle" };
	ElimDups(vecs);

	stable_sort(vecs.begin(), vecs.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	for (auto &s : vecs)
	{
		cout << s << " ";
	}
	cout << endl;
}

void testFilln()
{
	vector<int> ivec = { 1,2,3,5,6,8,9 };
	fill_n(ivec.begin(), ivec.size(), 0);
	for (auto it = ivec.begin(); it != ivec.end(); it++)
	{
		cout << *it << endl;
	}
}

bool biggerThan5(string s)
{
	if (s.size() > 5)
	{
		return true;
	}
	else
		return false;
}

void parditionTest(int sz)
{
	vector<string> vecs = { "lis","ok","qwert","zhangsna","asdfghh","hello","a" };
	//partition(vecs.begin(), vecs.end(), biggerThan5);
	auto wc = find_if(vecs.begin(), vecs.end(),
		[sz](const string &a) {return a.size() >= sz; });
	cout << *wc << endl;
}

void testStablePardition()
{
	vector<string> words = { "1","22","333","4444","55555","666666","7777777","88888888","aaaa","hello","wrold","cocos","Unral","2D","unity-3d","yituanjun","luoaotian" };
	vector<string>::size_type sz = 3;
	ElimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	//for_each(words.begin(), words.end(), [](const string &s) {cout << s << " "; });
	//cout << endl;
	auto wc = stable_partition(words.begin(), words.end(), [sz](const string &a) {return a.size() <= sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << "of longer" << endl;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

istream& myread(istream &is)
{
	string  mm;
	while (is >> mm)
		cout << mm << endl;
	is.clear();
	return is;
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;//make_plural(wc, "word ", "s ")当输入中文本中
											 //word数大于一是在word后加s，为words为word的复数！
}

vector<vector<int>> transpose(vector<vector<int> >& A) {
	vector<vector<int>> B;
	vector<int> Btemp;
	auto it1 = A.begin();			//hang
	auto it2 = (*it1).begin();		//lie
	auto itend = (*it1).end();
	int i = 0;
	for (it2 = (*it1).begin(); it2 != itend; it2++)
	{

		for (it1 = A.begin(); it1 != A.end(); it1++)
		{
			auto data = (*it1).begin() + i;
			Btemp.push_back(*data);
		}
		B.push_back(Btemp);
		Btemp.clear();
	}
	return B;
}

int primePalindrome(int N) {
	for (int i = N; i< 2 * 100000000; i++)
	{
		if (isPrime(i) == false)
			continue;
		if (ispalind(i) == false)
			continue;
		return i;
	}
	return 0;
}
bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n % 2 == 0 && n != 2) return false;
	double dn = sqrt(n) + 1;
	for (int i = 2; i <= dn; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

bool ispalind(int n)
{
	stringstream ss;
	ss << n;
	string str;
	ss >> str;
	size_t size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] != str[size - 1 - i])
			return false;
	}
	return true;
}
int testCount_if()
{
	using namespace std::placeholders;
	int sz = 6;
	_int64 counts = 0;
	vector<string> words = { "1","22","333","4444","55555","666666","7777777","88888888","aaaa","hello","wrold","cocos","Unral","2D","unity-3d","yituanjun","luoaotian" };
	auto func2 = [](string &word, string::size_type sz) {return word.size() > sz; };
	counts = count_if(words.begin(), words.end(), bind(func2, _1, sz));
	cout << "长度大于6的字符串有" << counts << "个" << endl;

	return 0;
}
int testCheck_size()
{
	vector<int> vec1 = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	string name = "luoaotian";
	auto fun = [](int sz, string::size_type length) {return sz > length; };
	cout << count_if(vec1.begin(), vec1.end(), bind(fun, _1, name.size())) << endl;


	return 0;
}
int myfunction()
{
	vector<int> vec = { 1,2,3,4 };
	ostream_iterator<int> out_iter(cout, " ,");

	for (auto e : vec)
		*out_iter = e;
	return 0;
}
int fileStreamToVec()
{
	ifstream fin("test.txt");
	istream_iterator<string> file_iter(fin), eof;
	vector<string> svec;
	while (file_iter != eof)
	{
		svec.push_back(*file_iter++);
	}
	for (auto e : svec)
		cout << e << endl;
	return 0;
}

int sortFromStream()
{
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> ivec;
	auto it = ivec.begin();
	unique_copy(in_iter, eof, back_inserter(ivec));
	sort(ivec.begin(), ivec.end(), [](int i, int j) {return i > j; });
	for (auto e : ivec)
	{
		*out_iter = e;
	}
	return 0;
}

int classifyFile()
{
	ifstream fin("intiger_data.txt");
	ofstream odd("odd_data.txt"),even("ecen_data.txt");
	istream_iterator<int> in_iter(fin), eof;
	ostream_iterator<int> odd_iter(odd, "\n"), even_iter(even, "\n");
	while (in_iter != eof)
	{
		if ((*in_iter) % 2 == 1) odd_iter = *in_iter;
		else even_iter = *in_iter;
		in_iter++;
	}
	return 0;
}

int wordsCount()
{
	ifstream fin("test.txt");
	map<string, size_t> count;
	string word;
	while (fin >> word)
	{
		word.erase(remove_if(word.begin(), word.end(), ispunct),word.end());	
		for (auto it = word.begin(); it != word.end(); it++)
		{
			*it = tolower(*it);
		}
		++count[word];
	}
	map<string, size_t>::iterator mapi;
	for (mapi = count.begin(); mapi != count.end(); ++mapi)//C++ 11支持:const auto &s : word_count
	{
		//两个成员分别代表关键字和对应值
		cout << mapi->first << " ";
		cout << mapi->second << " " << endl;
	}

	return 0;
}

int vectorPointer(shared_ptr<vector<int>> pv)
{
	
	int var;
	while (cin >> var)
	{
		pv->push_back(var);
	}
	printVector(pv);
	return 0;
}

void printVector(shared_ptr<vector<int>>  pv)
{
	for (auto e : *pv)
	{
		cout << e << endl;
	}
}

void runQueries(ifstream & infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for , or q to quit: " << endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		tq.Find_words(s);
		tq.print_result();
		tq.clear();
	}
}
