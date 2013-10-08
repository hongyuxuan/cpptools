#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
 
#include <exception>
#include <string>

#define MY_THROW(ExClass, args...)                             \
    do                                                         \
    {                                                          \
		ExClass e(args);                                       \
		e.Init(__FILE__, __PRETTY_FUNCTION__, __LINE__);       \
		throw e;                                               \
	}                                                \
    while (false)     
 
#define MY_DEFINE_EXCEPTION(ExClass, Base)                     \
	ExClass(const string& msg = "") throw()               \
	: Base(msg)                                            \
     {}                                                         \
	~ExClass() throw() {}                                        \
	/* override */ string GetClassName() const            \
	{                                                         \
		return #ExClass;                                       \
	}

using namespace std;

class ExceptionBase : public exception
{
public:
	ExceptionBase(const string& msg = "") throw();
	virtual ~ExceptionBase() throw();
	void Init(const char * file, const char * func, int line);
	virtual string GetClassName() const;
	virtual string GetMessage() const;
    const char * what() const throw();
	const string& ToString() const;

protected:
	string mMsg;
	const char * mFile;
	const char * mFunc;
	int mLine;

private:
    mutable string mWhat;
};

/*
 * This is an example exception
 *
 * class DxpException : public ExceptionBase
 * {
 * public:
 *     MY_DEFINE_EXCEPTION(DxpException, ExceptionBase);
 * };
 *
*/
#endif
