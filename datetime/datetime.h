#ifndef DATETIME_H
#define DATETIME_H

#include <string>
#include <stdint.h>
#include <ctime>

#define BJ_TIME_DIFF (8*60*60)
#define DATE_FORMAT "%a, %d %b %Y %H:%M:%S GMT"
#define DATE_FORMAT_RFC822 "%a, %d %b %Y %H:%M:%S GMT"
#define DATE_FORMAT_RFC850 "%A, %d-%b-%y %H:%M:%S GMT"
#define DATE_FORMAT_ANSI "%a %b %H:%M:%S %Y"
#define DATE_FORMAT_IOS8601 "%Y-%m-%dT%H:%M:%S.000Z"
#define DATE_FORMAT_NOW "%Y-%m-%d %H:%M:%S"

using namespace std;

namespace Datetime
{

bool CheckRFC850DateValid(const string& date);

bool CheckAnsicDateValid(const string& date);

bool CheckRFC822DateValid(const string& date);

string ConvertDateString(const string& date, const char *sourceFormat, const char *targetFormat);

string DateToString(int64_t date, const string& format = DATE_FORMAT);

int64_t StringToDate(const string& date);

int64_t StringToDate(const string& date, const char * sourceFormat);

int64_t GetCurrentTime();

string GetCurrentTimeString();

}

#endif
