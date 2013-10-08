#include <iostream>
#include "httpclient.h"

using namespace std;

int main()
{
	HttpClient * hc = new HttpClient();
	hc->SetVerbose();
	vector<string> headers;
	headers.push_back("authorization: 63wd3dpztlmb5ocdkj94pxmm: ipgzI6M8kqgvVa6vPT1HF4eo8HA=");
    headers.push_back("content-type: text/html");
    headers.push_back("x-ali-data-meta-author: hongyx2014@126.com");
    headers.push_back("x-ali-data-magic: abracadabra");
	headers.push_back("x-ali-data-auth-signature-type: Hmac-Sha1");
	//headers.push_back("x-ali-data-auth-signature-type: RSA");
	headers.push_back("x-ali-data-auth-method: proxy-authentication");
	headers.push_back("x-ali-data-auth-realmemberid: p1_067210");
	headers.push_back("content-md5: def4b1ca41734c013e19a8542d096b94");
    headers.push_back("date: Sun, 29 Sep 2013 13:30:00 GMT");
	hc->SetHeaders(headers);
	hc->SendRequest(HTTP_GET, "http://127.0.0.1/havana");
	cout << hc->GetResponse();
	delete hc;
}
