#include "Speaker.h"
#include "MyException.h"
#include <iostream>

using namespace std;

Speaker::Speaker(void)
{
	cout << "Object of class - Speaker" << endl << "Magic method - constructor without parameters" << endl;
	myType = SPE;
}

Speaker::Speaker(SpeakerBuilder &Build)
{
	cout << "Object of class - Speaker" << endl << "Magic method - constructor with parameters" << endl;
	myType = SPE;
	string error = "Attempt to set Speaker without:";
	if(Build.name=="")
		error += " name,";
	if(Build.surname=="")	
		error += " surname,";
	if(Build.father_name=="")	
		error += " father name,";
	if(Build.organization=="")
		error += " organization,";
	if(Build.myLecture=="")
		error += " myLecture.";
	error[error.size()-1] = '.';
	if(error!="Attempt to set Speaker without.")
		throw MyException(error);
	name		 = Build.name;
	surname		 = Build.surname;
	father_name	 = Build.father_name;
	organization = Build.organization;
	myLecture	 = Build.myLecture;	
	annotation	 = Build.annotation;
}

Speaker::Speaker(const Speaker &mySpeaker)
{
	cout << "Object of class - Speaker" << endl << "Magic method - constructor for copy" << endl;
	myType = SPE;
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