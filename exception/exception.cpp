#include <execinfo.h>
#include <stdlib.h>
#include <cxxabi.h>
#include <iostream>
#include <sstream>
#include "exception.h"
 
using namespace std;
 
ExceptionBase::ExceptionBase(const string& msg) throw()
    : mMsg(msg),
      mFile("<unknown file>"),
      mFunc("<unknown func>"),
      mLine(-1)
{
}
 
ExceptionBase::~ExceptionBase() throw()
{
}
 
void ExceptionBase::Init(const char * file, const char * func, int line)
{
    mFile = file;
    mFunc = func;
    mLine = line;
}
 
string ExceptionBase::GetClassName() const
{
    return "ExceptionBase";
}
 
const char* ExceptionBase::what() const throw()
{
    return ToString().c_str();
}
 
const string& ExceptionBase::ToString() const
{
    if (mWhat.empty())
    {
        stringstream sstr("");
        if (mLine > 0)
        {
            sstr << mFile << "(" << mLine << ")";
        }
        //sstr <<  ": " << GetClassName();
        if (!GetMessage().empty())
        {
            sstr << ": " << GetMessage();
        }
        mWhat = sstr.str();
    }
    return mWhat;
}
 
string ExceptionBase::GetMessage() const
{
    return mMsg;
}
