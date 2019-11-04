#include "Presentation.h"

Presentation::Presentation(void)
{	
	cout << "Object of class - Presentation" << endl << "Magic method - constructor without parameters" << endl;
}

Presentation::Presentation(time_t myTime,string&myName)
{
	cout << "Object of class - Presentation" << endl << "Magic method - constructor with parameters" << endl;
	stTime = myTime;
	name = myName;
}

Presentation::Presentation(const Presentation&myPres)
{
	cout << "Object of class - Presentation" << endl << "Magic method - constructor for copy" << endl;
	stTime = myPres.stTime;
	name = myPres.name;
}

Presentation::~Presentation(void)
{
	cout << "Object of class - Presentation" << endl << "Magic method - destructor" << endl;
}

void Presentation::setName(string&tname)
{
	name = tname;
}

void Presentation::setDate(time_t time)
{
	stTime = time;
}

string &Presentation::getName(void)
{
	return name;
}

time_t Presentation::getDate(void)
{
	return stTime;
}

ofstream &operator<<(ofstream &stream, Presentation &myPresent)
{
	stream << myPresent.stTime << endl;
	stream << myPresent.name << endl;
	return stream;
}

ifstream &operator>>(ifstream &stream,Presentation &myPresent)
{
	cout << "Input time start:";
	stream >> myPresent.stTime;
	cout << "Input name:";
	stream >> myPresent.name;
	return stream;
}

istream &operator>>(istream &stream,Presentation &myPresent)
{
	cout << "Input time start:";
	stream >> myPresent.stTime;
	cout << "Input name:";
	stream >> myPresent.name;
	return stream;
}