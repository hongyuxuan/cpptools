#ifndef STRUTIL_H
#define STRUTIL_H

#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace StrUtil
{

bool StartWith(const string& str, const string& prefix);

bool EndWith(const string& str, const string& prefix);

string ToUpper(string s);

string ToLower(string s);

vector<string> Split(string& s, const string& separator);

template<typename T> 
string ToString(const T& t, const string& connector = ",")
{
	ostringstream out;
	for (typeof(t.begin()) iter = t.begin(); iter != t.end(); iter++)
	{
		out << *iter << connector;
	}
	string res = out.str();
	res = res.substr(0, res.length() - connector.length());
	return res;
}

string Trim(string s);

}

#endif
