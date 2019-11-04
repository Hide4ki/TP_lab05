#include "SpeakerBuilder.h"
#include <iostream>

using namespace std;

SpeakerBuilder::SpeakerBuilder(void)
{	
	cout << "Object of class - SpeakerBuilder" << endl << "Magic method - constructor without parameters" << endl;
	name	      = "";
	surname	      = "";
	father_name   = "";
	organization  = "";
	myLecture     = "";
	annotation    = "NuLL";
}

SpeakerBuilder::SpeakerBuilder(string &name):name(name)
{
	cout << "Object of class - SpeakerBuilder" << endl << "Magic method - constructor with parameters" << endl;
	surname	      = "";
	father_name   = "";
	organization  = "";
	myLecture     = "";
	annotation    = "NuLL";
}

SpeakerBuilder::SpeakerBuilder(const SpeakerBuilder &myBuilder)
{
	cout << "Object of class - SpeakerBuilder" << endl << "Magic method - constructor for copy" << endl;
	name	      = myBuilder.name;
	surname	      = myBuilder.surname;
	father_name   = myBuilder.father_name;
	organization  = myBuilder.organization;
	myLecture     = myBuilder.myLecture;
	annotation    = myBuilder.annotation;
}

SpeakerBuilder::~SpeakerBuilder(void)
{
	cout << "Object of class - SpeakerBuilder" << endl << "Magic method - destructor" << endl;
}

void SpeakerBuilder::ReadInFile(ifstream &stream)
{
	stream >> name	      ;
	stream >> surname	  ;    
	stream >> father_name ;  
	stream >> organization;  
	stream >> myLecture   ;  
	stream >> annotation  ;  
}

SpeakerBuilder &SpeakerBuilder::SetName(string &Nname)
{
	name = Nname;
	return *this;
}

SpeakerBuilder &SpeakerBuilder::SetSurname(string &Nsurname)
{
	surname = Nsurname;
	return *this;
}

SpeakerBuilder &SpeakerBuilder::SetFathername(string&F)
{
	father_name = F;
	return *this;
}
SpeakerBuilder &SpeakerBuilder::SetOrganization(string&O)
{
	organization = O;
	return *this;
}

SpeakerBuilder &SpeakerBuilder::SetLecture(string&L)
{
	myLecture = L;
	return *this;
}

SpeakerBuilder &SpeakerBuilder::SetAnnotation(string&A)
{
	annotation = A;
	return *this;
}

istream &operator >> (istream &stream, SpeakerBuilder &myBuilder)
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
	if(myBuilder.organization=="")
	{
		cout << "Enter organization:";
		stream >> myBuilder.organization;
	}
	if(myBuilder.myLecture=="")
	{
		cout << "Enter myLecture:";
		stream >> myBuilder.myLecture;
	}
	if(myBuilder.annotation=="")
	{
		cout << "Enter annotation:";
		stream >> myBuilder.annotation;
	}
	return stream;
}