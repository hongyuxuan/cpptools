#include <iostream>
#include "base64.h"

using namespace std;

int main()
{
	string s = "Authorization   : signature-type	: hmac-sha1 END";
	istringstream is(s);
	ostringstream os;
	Base64::Base64Encoding(is, os);
	cout << os.str() << endl;
	istringstream iss(os.str());
	ostringstream oss;
	Base64::Base64Decoding(iss, oss);
	cout << oss.str() << endl;
}
