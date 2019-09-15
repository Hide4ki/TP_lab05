#include "AdministratorBuilder.h"
#include <iostream>

using namespace std;

AdministratorBuilder::AdministratorBuilder(void)
{	
	cout << "Object of class - AdministratorBuilder" << endl << "Magic method - constructor without parameters" << endl;
	name	    = "";
	surname	    = "";
	father_name = "";
	position    = "";
	responsible = "";
}

AdministratorBuilder::AdministratorBuilder(string &name):name(name)
{
	cout << "Object of class - AdministratorBuilder" << endl << "Magic method - constructor with parameters" << endl;
	surname	    = "";
	father_name = "";
	position    = "";
	responsible = "";
}

AdministratorBuilder::AdministratorBuilder(const AdministratorBuilder &myBuilder)
{
	cout << "Object of class - AdministratorBuilder" << endl << "Magic method - constructor for copy" << endl;
	name = myBuilder.name;
	surname = myBuilder.surname;
	responsible = myBuilder.responsible;
	father_name = myBuilder.father_name;
	position = myBuilder.position;
}

AdministratorBuilder::~AdministratorBuilder(void)
{
	cout << "Object of class - AdministratorBuilder" << endl << "Magic method - destructor" << endl;
}

void AdministratorBuilder::ReadInFile(ifstream &stream)
{
	stream >> name ;
	stream >> surname;
	stream >> father_name;
	stream >> position;
	stream >> responsible;
}

AdministratorBuilder &AdministratorBuilder::SetName(string &Nname)
{
	name = Nname;
	return *this;
}

AdministratorBuilder &AdministratorBuilder::SetSurname(string &Nsurname)
{
	surname = Nsurname;
	return *this;
}

AdministratorBuilder &AdministratorBuilder::SetFatherName(string &Nfathername)
{
	father_name = Nfathername;
	return *this;
}

AdministratorBuilder &AdministratorBuilder::SetPosition(string &Nposition)
{
	position = Nposition;
	return *this;
}

AdministratorBuilder &AdministratorBuilder::SetResponsible(string &Nresponsible)
{
	responsible = Nresponsible;
	return *this;
}

istream &operator >> (istream &stream, AdministratorBuilder &myBuilder)
{
	if(myBuilder.name=="")
	{
		cout << "Enter name:";
		stream >> myBuilder.name;
	}
	if(myBuilder.surname=="")
	{
		cout << "Enter surname:";
		stream >> myBuilder.surname;
	}	
	if(myBuilder.father_name=="")
	{
		cout << "Enter father name:";
		stream >> myBuilder.father_name;
	}
	if(myBuilder.position=="")
	{
		cout << "Enter position:";
		stream >> myBuilder.position;
	}
	if(myBuilder.responsible=="")
	{
		cout << "Enter responsible:";
		stream >> myBuilder.responsible;
	}
	return stream;
}