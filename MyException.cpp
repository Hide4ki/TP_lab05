#include "MyException.h"

MyException::MyException(void):message("Exception is undefined")
{
	cout << "Object of class - MyException" << endl << "Magic method - constructor without parameters" << endl;
}

MyException::MyException(const string m):message(m)
{
	cout << "Object of class - MyException" << endl << "Magic method - constructor with parameters" << endl;
}

MyException::MyException(const MyException &myException): message(myException.message)
{
	cout << "Object of class - MyException" << endl << "Magic method - constructor for copy" << endl;
}

MyException::~MyException(void)
{
	cout << "Object of class - MyException" << endl << "Magic method - destructor" << endl;
}

ostream &operator << (ostream &stream,const MyException &myException)
{
	stream << myException.message.c_str() << endl;
	return stream;
}
