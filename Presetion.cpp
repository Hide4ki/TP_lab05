#include "presetion.h"

Presetion::Presetion(void)
{	
	cout << "Object of class - Presetion" << endl << "Magic method - constructor without parameters" << endl;
}

Presetion::Presetion(time_t myTime,string&myName)
{
	stTime = myTime;
	name = myName;
	cout << "Object of class - Presetion" << endl << "Magic method - constructor with parameters" << endl;
}

Presetion::Presetion(const Presetion&myPres)
{
	stTime = myPres.stTime;
	name = myPres.name;
	cout << "Object of class - Presetion" << endl << "Magic method - constructor for copy" << endl;
}

Presetion::~Presetion(void)
{
	cout << "Object of class - Presetion" << endl << "Magic method - destructor" << endl;
}

void Presetion::setName(string&tname)
{
	name = tname;
}

void Presetion::setDate(time_t time)
{
	stTime = time;
}

string &Presetion::getName(void)
{
	return name;
}

time_t Presetion::getDate(void)
{
	return stTime;
}

ofstream &operator<<(ofstream &stream, Presetion &myPresent)
{
	stream << myPresent.stTime << endl;
	stream << myPresent.name << endl;
	return stream;
}

ifstream &operator>>(ifstream &stream,Presetion &myPresent)
{
	stream >> myPresent.stTime;
	stream >> myPresent.name;
	return stream;
}

istream &operator>>(istream &stream,Presetion &myPresent)
{
	stream >> myPresent.stTime;
	stream >> myPresent.name;
	return stream;
}