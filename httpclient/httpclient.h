#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <curl/curl.h>
#include <string>
#include <vector>
//#include "exception.h"

enum HTTP_METHOD
{
	HTTP_GET,
	HTTP_POST,
	HTTP_HEAD,
	HTTP_PUT
};

using namespace std;

const long CONTENT_MAX_LENGTH = 102400;     // 100KB

class HttpClient
{
public:
	HttpClient();
	~HttpClient();
	void SetHeaders(vector<string> headers);
	void SetVerbose();
	void SendRequest(HTTP_METHOD method, const char *uri);
	string GetResponse();

private:
	CURL *mCurl;
	CURLcode mErrno;
	struct curl_slist *mHeaders;
	static string mContent;
	
	static size_t writer(void *data, size_t size, size_t nmemb, void *userf);
};

/*class HttpClientException : public ExceptionBase
{
public:
    MY_DEFINE_EXCEPTION(HttpClientException, ExceptionBase);
};
*/

#endif
