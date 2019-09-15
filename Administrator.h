#pragma once

#include "AdministratorBuilder.h"
#include "Conference.h"

using namespace std;
class AdministratorBuilder;

class Administrator:public Conference
{
public:
	Administrator(AdministratorBuilder &);
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

