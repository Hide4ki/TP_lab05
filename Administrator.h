#pragma once

#include "AdministratorBilder.h"
#include "Conference.h"

using namespace std;

class Administrator:public Conference
{
public:
	Administrator(void);
	Administrator(AdministratorBilder &);
	Administrator(const Administrator &);
	~Administrator(void);
	void WriteInFile(ofstream) override;
private:
	string name;
	string surname;
	string father_name;
	string position;
	string responsible;
};

