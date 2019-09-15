#include "Builder.h"

Builder::Builder(void)
{
	cout << "Object of class - Builder" << endl << "Magic method - constructor without parameters" << endl;
}

Builder::~Builder(void)
{
	cout << "Object of class - Builder" << endl << "Magic method - destructor" << endl;
}

Builder::Builder(string&s)
{
	cout << "Object of class - Builder" << endl << "Magic method - constructor with parameters" << endl;
}

Builder::Builder(const Builder&b)
{
	cout << "Object of class - Builder" << endl << "Magic method - constructor for copy" << endl;
}
