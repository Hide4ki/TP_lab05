#include "Speaker.h"
#include "MyException.h"
#include <iostream>

using namespace std;

Speaker::Speaker(void)
{
	myType = SPE;
	cout << "Object of class - Speaker" << endl << "Magic method - constructor without parameters" << endl;
}

Speaker::Speaker(SpeakerBilder &bild)
{
	myType = SPE;
	cout << "Object of class - Speaker" << endl << "Magic method - constructor with parameters" << endl;
	string error = "Attempt to set Speaker without:";
	if(bild.name=="")
		error += " name,";
	if(bild.surname=="")	
		error += " surname,";
	if(bild.father_name=="")	
		error += " father name,";
	if(bild.organization=="")
		error += " organization,";
	if(bild.myLecture=="")
		error += " myLecture.";
	error[error.size()-1] = '.';
	if(error!="Attempt to set Speaker without.")
		throw MyException(error.c_str());
	name		 = bild.name;
	surname		 = bild.surname;
	father_name	 = bild.father_name;
	organization = bild.organization;
	myLecture	 = bild.myLecture;	
	annotation	 = bild.annotation;
}

Speaker::Speaker(const Speaker &mySpeaker)
{
	myType = SPE;
	cout << "Object of class - Speaker" << endl << "Magic method - constructor for copy" << endl;
	name		 = mySpeaker.name;
	surname		 = mySpeaker.surname;
	father_name	 = mySpeaker.father_name;
	organization = mySpeaker.organization;
	myLecture	 = mySpeaker.myLecture;
	annotation   = mySpeaker.annotation;
}		 


Speaker::~Speaker(void)
{
	cout << "Object of class - Speaker" << endl << "Magic method - destructor" << endl;
}

void Speaker::WriteInFile(ofstream &stream)const
{
	stream << name         << endl; 
	stream << surname      << endl;
	stream << father_name  << endl;	
	stream << organization << endl; 
	stream << myLecture	   << endl; 
	stream << annotation   << endl; 
}

bool Speaker::operator == (const Speaker&B)const
{
	return name == B.name && surname == B.surname &&  father_name == B.father_name && organization == B.organization && myLecture == B.myLecture && annotation == B.annotation?true:false;
}