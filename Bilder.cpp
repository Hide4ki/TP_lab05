#include "Bilder.h"

Bilder::Bilder(void)
{
	cout << "Object of class - Bilder" << endl << "Magic method - constructor without parameters" << endl;
}

Bilder::~Bilder(void)
{
	cout << "Object of class - Bilder" << endl << "Magic method - destructor" << endl;
}

Bilder::Bilder(string&s)
{
	cout << "Object of class - Bilder" << endl << "Magic method - constructor with parameters" << endl;
}

Bilder::Bilder(const Bilder&b)
{
	cout << "Object of class - Bilder" << endl << "Magic method - constructor for copy" << endl;
}
