#include <iostream>
#include "strutil.h"

using namespace std;

int main()
{
	string s = ":Authorization   : signature-type	: hmac-sha1 END:";
	/*cout << StrUtil::StartWith(s, "Authorization") << endl;
	cout << StrUtil::EndWith(s, "END") << endl;
	cout << StrUtil::ToUpper(s) << endl;
*/
	vector<string> v = StrUtil::Split(s, ":");
//	cout << StrUtil::ToString(v, "%20") << endl;
	for (int i=0; i<v.size(); i++)
		cout << StrUtil::Trim(v[i]) << endl;
}
