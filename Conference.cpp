#include "Conference.h"

Conference::Conference(void)
{
	cout << "Object of class - Conference" << endl << "Magic method - constructor without parameters" << endl;
}

Conference::Conference(const string&s)
{
	cout << "Object of class - Conference" << endl << "Magic method - constructor with parameters" << endl;
}

Conference::Conference(const Conference&c)
{
	cout << "Object of class - Conference" << endl << "Magic method - constructor for copy" << endl;
}

Conference::~Conference(void)
{
	cout << "Object of class - Conference" << endl << "Magic method - destructor" << endl;
}
