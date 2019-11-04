#include "ProgramBuilder.h"
#include "IteratorPtr.h"

ProgramBuilder::ProgramBuilder(void)
{
	cout << "Object of class - ProgramBuilder" << endl << "Magic method - constructor without parameters" << endl;
	dateSt = 0;
	name = "";
	presentations = new List<Presentation*>;
}

ProgramBuilder::ProgramBuilder(string&myName,time_t&myTime)
{
	cout << "Object of class - ProgramBuilder" << endl << "Magic method - constructor with parameters" << endl;
	dateSt = myTime;
	name = myName;
	presentations = new List<Presentation*>;
}

ProgramBuilder::ProgramBuilder(const ProgramBuilder&Build)
{
	cout << "Object of class - ProgramBuilder" << endl << "Magic method - constructor for copy" << endl;
	dateSt = Build.dateSt;
	name = Build.name;
	presentations = new List<Presentation*>;
	*presentations = *Build.presentations;
}

ProgramBuilder::~ProgramBuilder(void)
{
	cout << "Object of class - ProgramBuilder" << endl << "Magic method - destructor" << endl;
	IteratorPtr<Presentation*> i(presentations->GetCorrectIterator());
	for(i->First(); !i->IsDone(); i->Next())
		delete i->CurrentItem();
	delete presentations;
}

void ProgramBuilder::ReadInFile(ifstream&stream )
{
	long cnt;
	stream >> name;
	stream >> dateSt;
	stream >> cnt;
	for(int i = 0; i<cnt; i++)
	{
		Presentation *tmp = new Presentation;
		stream >> *tmp;
		presentations->Append(tmp);
	}
}

ProgramBuilder &ProgramBuilder::SetDate(time_t&myTime)
{
	dateSt = myTime;
	return *this;
}

ProgramBuilder &ProgramBuilder::SetName(string&myName)
{
	name = myName;
	return *this;
}

ProgramBuilder &ProgramBuilder::AddPresent(Presentation&tmp)
{
	presentations->Append(&tmp);
	return *this;
}

ifstream &operator >> (ifstream &stream, ProgramBuilder &myBuilder)
{
	if (myBuilder.name == "")
	{
		stream >> myBuilder.name;
	}	
	if(myBuilder.dateSt==0)
	{
		stream >> myBuilder.dateSt;
	}
	long cnt;
	stream >> cnt;
 	for(int i = 0; i < cnt; i++)
	{
		Presentation *tmp = new Presentation;
		stream >> *tmp;
		myBuilder.presentations->Append(tmp);
	}
	return stream;
}

istream &operator >> (istream &stream, ProgramBuilder &myBuilder)
{
	if (myBuilder.name == "")
	{
		cout << "Enter name:";
		stream >> myBuilder.name;
	}
	if (myBuilder.dateSt == 0)
	{
		cout << "Enter date:";
		stream >> myBuilder.dateSt;
	}
	long cnt;
	cout << "Enter number prentation:";
	stream >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		Presentation *tmp = new Presentation;
		stream >> *tmp;
		myBuilder.presentations->Append(tmp);
	}
	return stream;
}