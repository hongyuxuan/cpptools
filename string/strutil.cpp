#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "strutil.h"

using namespace std;

bool StrUtil::StartWith(const string& str, const string& prefix)
{
    return str.compare(0, prefix.length(), prefix) == 0;
}

bool StrUtil::EndWith(const string& str, const string& prefix)
{
	return str.compare(str.length() - prefix.length(), str.length(), prefix) == 0;
}

string StrUtil::ToUpper(string s)
{
    transform(s.begin(), s.end(), s.begin(), static_cast<int(*)(int)>(std::toupper));
    return s;
}

string StrUtil::ToLower(string s)
{
    transform(s.begin(), s.end(), s.begin(), static_cast<int(*)(int)>(std::tolower));
    return s;
}

vector<string> StrUtil::Split(string& s, const string& separator)
{
	vector<string> res;
	while(true)
	{
		string::size_type pos = s.find(separator);
		if (pos == string::npos)
		{
			if (!s.empty())
				res.push_back(s);
			break;
		}
		if (pos != 0)
			res.push_back(s.substr(0, pos));
		s = s.substr(pos + separator.length());
	}
	return res;
}

string StrUtil::Trim(string s)
{
	s.erase(s.begin(), find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	s.erase(find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}
