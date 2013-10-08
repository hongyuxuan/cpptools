#include <iostream>
#include "datetime.h"

using namespace std;
using namespace Datetime;

string getFormatDate(const std::string& time)
{
    string date;
    if (Datetime::CheckRFC822DateValid(time))
    {
        date = time;
    }
    else if(Datetime::CheckRFC850DateValid(time))
    {
        date = Datetime::ConvertDateString(time, DATE_FORMAT_RFC850, DATE_FORMAT_RFC822);
    }
    else if (Datetime::CheckAnsicDateValid(time))
    {
        date = Datetime::ConvertDateString(time, DATE_FORMAT_ANSI, DATE_FORMAT_RFC822);
    }
    else
    {
		return "error";
    }
    return date;
}

int main()
{
	string time = "Thu, 26 Sep 2013 04:35:00 GMT";
	cout << Datetime::GetCurrentTimeString() << endl;
}
