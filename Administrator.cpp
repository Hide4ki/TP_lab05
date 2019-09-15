#include "Administrator.h"
#include "MyException.h"
#include <iostream>

using namespace std;

Administrator::Administrator(void)
{
	myType = ADM;
	cout << "Object of class - Administrator" << endl << "Magic method - constructor without parameters" << endl;
}

Administrator::Administrator(AdministratorBuilder &Build)
{
	cout << "Object of class - Administrator" << endl << "Magic method - constructor with parameters" << endl;
	myType = ADM;
	string error = "Attempt to set administrator without:";
	if(Build.name=="")
		error += " name,";
	if(Build.surname=="")	
		error += " surname,";
	if(Build.father_name=="")	
		error += " father name,";
	if(Build.position=="")
		error += " position,";
	if(Build.responsible=="")
		error += " responsible.";
	error[error.size()-1] = '.';
	if(error!="Attempt to set administrator without.")
		throw MyException(error);
	name		= Build.name;
	responsible	= Build.responsible;
	position	= Build.position;
	father_name	= Build.father_name;
	surname		= Build.surname;
}

Administrator::Administrator(const Administrator &myAdmin)
{
	cout << "Object of class - Administrator" << endl << "Magic method - constructor for copy" << endl;
	myType = ADM;
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

void Administrator::WriteInFile(ofstream &stream)const
{
	stream << name         << endl; 
	stream << surname      << endl;
	stream << father_name  << endl;	
	stream << position     << endl; 
	stream << responsible  << endl; 
}

bool Administrator::operator == (const Administrator&B)const
{
	return name == B.name && surname == B.surname &&  father_name == B.father_name && position == B.position && responsible == B.responsible?true:false;
}