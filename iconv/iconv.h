#include <iconv.h>
#include <iostream>
#include <cstring>

using namespace std;

// 代码转换操作类
class Iconv
{
private:
	iconv_t icv;
public:
	Iconv(const string& from_charset, const string& to_charset) 
	{
		icv = iconv_open(to_charset.c_str(), from_charset.c_str());
	}
	~Iconv() 
	{
		iconv_close(icv);
	}

	// 转换输出
	int convert(char * inbuf, int inlen, char * outbuf, int outlen) 
	{
		char **pin = &inbuf;
		char **pout = &outbuf;

		memset(outbuf, 0, outlen);
		return iconv(icv, pin, (size_t *)&inlen, pout, (size_t *)&outlen);
	}
};
