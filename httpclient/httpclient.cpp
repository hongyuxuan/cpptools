#include <iostream>
#include <stdlib.h>
#include "httpclient.h"

using namespace std;

HttpClient::HttpClient()
{
	mCurl = NULL;
	mHeaders = NULL;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	mCurl = curl_easy_init();
    if (mCurl == NULL)
    {
	//	MY_THROW(HttpClientException, "Failed to create CURL connection");
    }
	curl_easy_setopt(mCurl, CURLOPT_WRITEFUNCTION, &writer);
//	curl_easy_setopt(mCurl, CURLOPT_WRITEDATA, &content);
}

size_t HttpClient::writer(void *data, size_t size, size_t nmemb, void *userf)
{
    long sizes = size * nmemb;
	string temp((char *)data, sizes);
	mContent += temp;
    return sizes;
}

void HttpClient::SetHeaders(vector<string> headers)
{
	for(int i=0; i<headers.size(); i++)
	{
		mHeaders = curl_slist_append(mHeaders, headers[i].c_str());
	}
	curl_easy_setopt(mCurl, CURLOPT_HTTPHEADER, mHeaders);
}

void HttpClient::SetVerbose()
{
	curl_easy_setopt(mCurl, CURLOPT_VERBOSE, 1L);
}

void HttpClient::SendRequest(HTTP_METHOD method, const char * uri)
{
	switch(method)
	{
		case HTTP_GET:
			mContent.erase(); 
			curl_easy_setopt(mCurl, CURLOPT_URL, uri); 
			curl_easy_perform(mCurl);
	}
}

string HttpClient::GetResponse()
{
	return mContent;
}

HttpClient::~HttpClient()
{
	if (mHeaders != NULL)
	{
		curl_slist_free_all(mHeaders);
	}
	curl_easy_cleanup(mCurl);
	curl_global_cleanup();
}

string HttpClient::mContent = "";

