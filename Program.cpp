#include "Program.h"
#include "MyException.h"
#include <iostream>
#include "IteratorPtr.h"

Program::Program(void)
{
	cout << "Object of class - Program" << endl << "Magic method - constructor without parameters" << endl;
	myType = PRO;
	presentations = new List<Presentation*>;
}

Program::Program(ProgramBuilder&Build)
{
	cout << "Object of class - Program" << endl << "Magic method - constructor with parameters" << endl;
	myType = PRO;
	string error = "Attempt to set program without:";
	if(Build.name=="")
		error += " name,";
	if(Build.dateSt==0)
		error += " date.";
	error[error.size()-1] = '.';
	if(error!="Attempt to set program without.")
		throw MyException(error);
	presentations = new List<Presentation*>;
	name			= Build.name;
	dateSt			= Build.dateSt;
	IteratorPtr<Presentation*> i(Build.presentations->GetCorrectIterator());
	for (i->First(); !i->IsDone(); i->Next())
		presentations->Append(new Presentation(*i->CurrentItem()));
}

Program::Program(const Program&myProg)
{
	cout << "Object of class - Program" << endl << "Magic method - constructor for copy" << endl;
	myType = PRO;
	presentations = new List<Presentation*>;
	name			= myProg.name;
	dateSt			= myProg.dateSt;
	IteratorPtr<Presentation*> i(myProg.presentations->GetCorrectIterator());
	for (i->First(); !i->IsDone(); i->Next())
		presentations->Append(new Presentation(*i->CurrentItem()));
}

Program::~Program(void)
{
	cout << "Object of class - Program" << endl << "Magic method - destructor" << endl;
	IteratorPtr<Presentation*> i(presentations->GetCorrectIterator());
	for(i->First(); !i->IsDone(); i->Next())
		delete i->CurrentItem();
	delete presentations;
}

void Program::WriteInFile(ofstream&stream)const
{
	stream << name   << endl; 
	stream << dateSt << endl; 
	IteratorPtr<Presentation*> i(presentations->GetCorrectIterator());
	stream << presentations->Count()<< endl;
	for(i->First(); !i->IsDone(); i->Next())
		stream << *i->CurrentItem();
}

bool Program::operator == (const Program&B)const
{
	return name == B.name && dateSt == B.dateSt?true:false;
}
