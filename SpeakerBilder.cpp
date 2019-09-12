#include "SpeakerBilder.h"
#include <iostream>

using namespace std;

SpeakerBilder::SpeakerBilder(void)
{	
	name	      = "";
	surname	      = "";
	father_name   = "";
	organization  = "";
	myLecture     = "";
	annotation    = "";
	cout << "Object of class - SpeakerBilder" << endl << "Magic method - constructor without parameters" << endl;
}

SpeakerBilder::SpeakerBilder(string &name):name(name)
{
	surname	      = "";
	father_name   = "";
	organization  = "";
	myLecture     = "";
	annotation    = "";
	cout << "Object of class - SpeakerBilder" << endl << "Magic method - constructor with parameters" << endl;
}

SpeakerBilder::SpeakerBilder(const SpeakerBilder &myBilder)
{
	name	      = myBilder.name;
	surname	      = myBilder.surname;
	father_name   = myBilder.father_name;
	organization  = myBilder.organization;
	myLecture     = myBilder.myLecture;
	annotation    = myBilder.annotation;
	cout << "Object of class - SpeakerBilder" << endl << "Magic method - constructor for copy" << endl;
}

SpeakerBilder::~SpeakerBilder(void)
{
	cout << "Object of class - SpeakerBilder" << endl << "Magic method - destructor" << endl;
}

void SpeakerBilder::ReadInFile(ifstream &stream)
{
	stream >> name	      ;
	stream >> surname	  ;    
	stream >> father_name ;  
	stream >> organization;  
	stream >> myLecture   ;  
	stream >> annotation  ;  
}

SpeakerBilder &SpeakerBilder::SetName(string &Nname)
{
	name = Nname;
	return *this;
}

SpeakerBilder &SpeakerBilder::SetSurname(string &Nsurname)
{
	surname = Nsurname;
	return *this;
}

SpeakerBilder &SpeakerBilder::SetFathername(string&F)
{
	father_name = F;
	return *this;
}
SpeakerBilder &SpeakerBilder::SetOrganization(string&O)
{
	organization = O;
	return *this;
}

SpeakerBilder &SpeakerBilder::SetLecture(string&L)
{
	myLecture = L;
	return *this;
}

SpeakerBilder &SpeakerBilder::SetAnnotation(string&A)
{
	annotation = A;
	return *this;
}

istream &operator >> (istream &stream, SpeakerBilder &myBilder)
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
	if(myBilder.organization=="")
	{
		cout << "Enter organization:";
		stream >> myBilder.organization;
	}
	if(myBilder.myLecture=="")
	{
		cout << "Enter myLecture:";
		stream >> myBilder.myLecture;
	}
	if(myBilder.annotation=="")
	{
		cout << "Enter annotation:";
		stream >> myBilder.annotation;
	}
	return stream;
}