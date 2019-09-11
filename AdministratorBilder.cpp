#include "AdministratorBilder.h"
#include <iostream>

using namespace std;

AdministratorBilder::AdministratorBilder(void)
{	
	name	    = "";
	surname	    = "";
	father_name = "";
	position    = "";
	responsible = "";
}

AdministratorBilder::AdministratorBilder(string &name):name(name)
{
	surname	    = "";
	father_name = "";
	position    = "";
	responsible = "";
}

AdministratorBilder::AdministratorBilder(const AdministratorBilder &myBilder)
{
	name = myBilder.name;
	surname = myBilder.surname;
	responsible = myBilder.responsible;
	father_name = myBilder.father_name;
	position = myBilder.position;
}

AdministratorBilder::~AdministratorBilder(void)
{
}

void AdministratorBilder::ReadInFile(ifstream &stream)
{
	stream >> name ;
	stream >> surname;
	stream >> father_name;
	stream >> position;
	stream >> responsible;
}

AdministratorBilder &AdministratorBilder::SetName(string &Nname)
{
	name = Nname;
	return *this;
}

AdministratorBilder &AdministratorBilder::SetSurname(string &Nsurname)
{
	surname = Nsurname;
	return *this;
}

AdministratorBilder &AdministratorBilder::SetFatherName(string &Nfathername)
{
	father_name = Nfathername;
	return *this;
}

AdministratorBilder &AdministratorBilder::SetPosition(string &Nposition)
{
	position = Nposition;
	return *this;
}

AdministratorBilder &AdministratorBilder::SetResponsible(string &Nresponsible)
{
	responsible = Nresponsible;
	return *this;
}

ostream &operator >> (istream &stream, AdministratorBilder &myBilder)
{
	if(myBilder.name=="")
	{
		cout << "Enter name:";
		stream >> myBilder.name;
	}
	if(myBilder.surname=="")
	{
		cout << "Enter surname:";
		stream >> myBilder.surname;
	}	
	if(myBilder.father_name=="")
	{
		cout << "Enter father name:";
		stream >> myBilder.father_name;
	}
	if(myBilder.position=="")
	{
		cout << "Enter position:";
		stream >> myBilder.position;
	}
	if(myBilder.responsible=="")
	{
		cout << "Enter responsible:";
		stream >> myBilder.responsible;
	}
}