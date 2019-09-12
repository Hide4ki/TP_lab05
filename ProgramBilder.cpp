#include "ProgramBilder.h"
#include "IteratorPtr.h"

ProgramBilder::ProgramBilder(void)
{
	dateSt = 0;
	name = "";
	presentations = new List<Presetion*>;
	cout << "Object of class - ProgramBilder" << endl << "Magic method - constructor without parameters" << endl;
}

ProgramBilder::ProgramBilder(string&myName,time_t&myTime)
{
	dateSt = myTime;
	name = myName;
	presentations = new List<Presetion*>;
	cout << "Object of class - ProgramBilder" << endl << "Magic method - constructor with parameters" << endl;
}

ProgramBilder::ProgramBilder(const ProgramBilder&bild)
{
	dateSt = bild.dateSt;
	name = bild.name;
	presentations = new List<Presetion*>;
	*presentations = *bild.presentations;
	cout << "Object of class - ProgramBilder" << endl << "Magic method - constructor for copy" << endl;
}

ProgramBilder::~ProgramBilder(void)
{
	IteratorPtr<Presetion*> i = presentations->GetCorrectIterator();
	for(i->First(); !i->IsDone(); i->Next())
		delete i->CurrentItem();
	cout << "Object of class - ProgramBilder" << endl << "Magic method - destructor" << endl;
	delete presentations;
}

void ProgramBilder::ReadInFile(ifstream&stream )
{
	long cnt;
	stream >> name;
	stream >> dateSt;
	stream >> cnt;
	for(int i = 0; i<cnt; i++)
	{
		Presetion *tmp = new Presetion;
		stream >> *tmp;
		presentations->Append(tmp);
	}
}

ProgramBilder &ProgramBilder::SetDate(time_t&myTime)
{
	dateSt = myTime;
	return *this;
}

ProgramBilder &ProgramBilder::SetName(string&myName)
{
	name = myName;
	return *this;
}

ProgramBilder &ProgramBilder::AddPresent(Presetion&tmp)
{
	presentations->Append(&tmp);
	return *this;
}

istream &operator >> (istream &stream, ProgramBilder &myBilder)
{
	if(myBilder.dateSt==0)
	{
		cout << "Enter date:";
		stream >> myBilder.dateSt;
	}
	if(myBilder.name=="")
	{
		cout << "Enter name:";
		stream >> myBilder.name;
	}	
	long cnt;
	cout << "Enter number prentation:";
	stream >> cnt;
 	for(int i = 0; i < cnt; i++)
	{
		Presetion *tmp = new Presetion;
		stream >> *tmp;
		myBilder.presentations->Append(tmp);
	}
	return stream;
}