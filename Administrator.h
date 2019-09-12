#pragma once

#include "AdministratorBilder.h"
#include "Conference.h"

using namespace std;
class AdministratorBilder;

class Administrator:public Conference
{
public:
	Administrator(AdministratorBilder &);
	Administrator(const Administrator &);
	~Administrator(void);
	void WriteInFile(ofstream&) const override;
	bool operator == (const Administrator&)const;
private:
	string name;
	string surname;
	string father_name;
	string position;
	string responsible;
	Administrator(void);
};

