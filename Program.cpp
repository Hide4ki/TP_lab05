#include "Program.h"
#include "MyException.h"
#include <iostream>
#include "IteratorPtr.h"

Program::Program(void)
{
	myType = PRO;
	presentations = new List<Presetion*>;
	cout << "Object of class - Program" << endl << "Magic method - constructor without parameters" << endl;
}

Program::Program(ProgramBilder&bild)
{
	myType = PRO;
	presentations = new List<Presetion*>;
	cout << "Object of class - Program" << endl << "Magic method - constructor with parameters" << endl;
	string error = "Attempt to set program without:";
	if(bild.name=="")
		error += " name,";
	if(bild.dateSt==0)
		error += " date.";
	error[error.size()-1] = '.';
	if(error!="Attempt to set program without.")
		throw MyException(error.c_str());
	name			= bild.name;
	dateSt			= bild.dateSt;
	*presentations	= *bild.presentations;
}

Program::Program(const Program&myProg)
{
	myType = PRO;
	presentations = new List<Presetion*>;
	cout << "Object of class - Program" << endl << "Magic method - constructor for copy" << endl;
	name			= myProg.name;
	dateSt			= myProg.dateSt;
	*presentations	= *myProg.presentations;
}

Program::~Program(void)
{
	IteratorPtr<Presetion*> i = presentations->GetCorrectIterator();
	for(i->First(); !i->IsDone(); i->Next())
		delete i->CurrentItem();
	cout << "Object of class - Program" << endl << "Magic method - destructor" << endl;
	delete presentations;
}

void Program::WriteInFile(ofstream&stream)const
{
	stream << name   << endl; 
	stream << dateSt << endl; 
	IteratorPtr<Presetion*> i = presentations->GetCorrectIterator();
	stream << presentations->Count();
	for(i->First(); !i->IsDone(); i->Next())
		stream << *i->CurrentItem();
}

bool Program::operator == (const Program&B)const
{
	return name == B.name && dateSt == B.dateSt &&  &presentations == &B.presentations?true:false;
}
