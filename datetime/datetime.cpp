#include "datetime.h"
#include <ctime>
#include <boost/regex.hpp>

using namespace std;

bool Datetime::CheckRFC822DateValid(const string& date)
{
    static boost::regex re("(((Mon)|(Tue)|(Wed)|(Thu)|(Fri)|(Sat)|(Sun)), (0[1-9]|([1-2]\\d)|(3[0-1])) ((Jan)|(Feb)|(Mar)|(Apr)|(May)|(Jun)|(Jul)|(Aug)|(Sep)|(Oct)|(Nov)|(Dec)) (19|20)\\d\\d (([0-1]\\d)|(2[0-3])):[0-5]\\d:[0-5]\\d GMT)");
    return boost::regex_match(date, re);
}

bool Datetime::CheckRFC850DateValid(const string& date)
{
    static boost::regex re("(((Monday)|(Tuesday)|(Wednesday)|(Thursday)|(Friday)|(Saturday)|(Sunday))), (0[1-9]|([1-2]\\d)|(3[0-1]))-((Jan)|(Feb)|(Mar)|(Apr)|(May)|(Jun)|(Jul)|(Aug)|(Sep)|(Oct)|(Nov)|(Dec))-\\d\\d (([0-1]\\d)|(2[0-3])):[0-5]\\d:[0-5]\\d GMT");
    return boost::regex_match(date, re);
}

bool Datetime::CheckAnsicDateValid(const string& date)
{
    static boost::regex re("(((Mon)|(Tue)|(Wed)|(Thu)|(Fri)|(Sat)|(Sun)) ((Jan)|(Feb)|(Mar)|(Apr)|(May)|(Jun)|(Jul)|(Aug)|(Sep)|(Oct)|(Nov)|(Dec)) ( [1-9]|([1-2]\\d)|(3[0-1]))) (([0-1]\\d)|(2[0-3])):[0-5]\\d:[0-5]\\d (19|20)\\d\\d");
    return boost::regex_match(date, re);
}

string Datetime::ConvertDateString(const string& date, const char *sourceFormat, const char *targetFormat)
{
    int64_t t = StringToDate(date, sourceFormat);
    return DateToString(t, targetFormat);
}

int64_t Datetime::StringToDate(const string& date, const char * sourceFormat)
{
    tm t;   
    strptime(date.data(), sourceFormat, &t);
    int64_t time =  (int64_t)mktime(&t);
    return time;
}

int64_t Datetime::StringToDate(const string& date)
{
    tm t;
    strptime(date.data(), DATE_FORMAT, &t);
    int64_t time = (int64_t)mktime(&t) + BJ_TIME_DIFF;
    return time;
}

string Datetime::DateToString(int64_t date, const string& format)
{
    time_t *t = ((time_t *)&date);
    tm result;
    gmtime_r(t, &result);
    char buf[128] = {0};
    strftime(buf, 128, format.c_str(), &result);
    return buf;
}

int64_t Datetime::GetCurrentTime()
{
    struct timespec tm;
    clock_gettime(CLOCK_REALTIME, &tm);
    return tm.tv_sec + BJ_TIME_DIFF;
}

string Datetime::GetCurrentTimeString()
{
	int64_t nowtime = Datetime::GetCurrentTime();
	return Datetime::DateToString(nowtime, DATE_FORMAT_NOW);
}

