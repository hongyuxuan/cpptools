#include <iostream>
#include "exception.h"

using namespace std;

void funcA()
{
	MY_THROW(DxpException, "this is a exception test");
}

int main()
{
	try
	{
		funcA();
	}
	catch(DxpException& e)
	{
		cout << e.what() << endl;
	}
}
