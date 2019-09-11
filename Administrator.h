#pragma once

#include "AdministratorBilder.h"
#include "Conference.h"

using namespace std;

class Administrator:public Conference
{
public:
	Administrator(AdministratorBilder &);
	Administrator(const Administrator &);
	~Administrator(void);
	void WriteInFile(ofstream&) override;
	bool operator == (Administrator&);
private:
	string name;
	string surname;
	string father_name;
	string position;
	string responsible;
	Administrator(void);
};

