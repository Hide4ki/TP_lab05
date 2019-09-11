#include "Administrator.h"
#include "MyException.h"
#include <iostream>

using namespace std;

Administrator::Administrator(void)
{
	cout << "Object of class - Administrator" << endl << "Magic method - constructor without parameters" << endl;
}

Administrator::Administrator(AdministratorBilder &bild)
{
	myType = ADM;
	cout << "Object of class - Administrator" << endl << "Magic method - constructor with parameters" << endl;
	string error = "Attempt to set administrator without:";
	if(bild.name!="")
		error += "name,";
	if(bild.surname!="")	
		error += "surname,";
	if(bild.father_name!="")	
		error += "father name,";
	if(bild.position!="")
		error += "position,";
	if(bild.responsible!="")
		error += "responsible.";
	error[error.size()-1] = '.';
	if(error!="Attempt to set administrator without:")
		throw MyException(error.c_str());
	name		= bild.name;
	responsible	= bild.responsible;
	position	= bild.position;
	father_name	= bild.father_name;
	surname		= bild.surname;
}

Administrator::Administrator(const Administrator &myAdmin)
{
	myType = ADM;
	cout << "Object of class - Administrator" << endl << "Magic method - constructor for copy" << endl;
	name		= myAdmin.name;
	surname		= myAdmin.surname;
	father_name	= myAdmin.father_name;
	position	= myAdmin.position;
	responsible	= myAdmin.responsible;
}

Administrator::~Administrator(void)
{
	cout << "Object of class - Administrator" << endl << "Magic method - destructor" << endl;
}

void Administrator::WriteInFile(ofstream &stream)
{
	stream << name         << endl; 
	stream << surname      << endl;
	stream << father_name  << endl;	
	stream << position     << endl; 
	stream << responsible  << endl; 
}

bool Administrator::operator == (Administrator&B)
{
	return name == B.name && surname == B.surname &&  father_name == B.father_name && position == B.position && responsible == B.responsible?true:false;
}