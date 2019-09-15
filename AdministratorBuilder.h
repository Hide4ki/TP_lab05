#pragma once 

#include <string>
#include "Administrator.h"
#include "Builder.h"

typedef enum{ANAME, ASURNAME, AFATHERNAME, APOSITION, ARESPONSIBLE, AFIN, AENDBILD} ABILD;

class Administrator;

class AdministratorBuilder:public Builder
{
public:
	AdministratorBuilder(void);
	AdministratorBuilder(string&);
	AdministratorBuilder(const AdministratorBuilder&);
	~AdministratorBuilder(void);
	void ReadInFile(ifstream&)override;
	AdministratorBuilder &SetName(string&);
	AdministratorBuilder &SetSurname(string&);
	AdministratorBuilder &SetFatherName(string&);
	AdministratorBuilder &SetPosition(string&);
	AdministratorBuilder &SetResponsible(string&);
	friend istream &operator >> (istream&, AdministratorBuilder&);
private:
	friend Administrator;
	string name;
	string surname;
	string father_name;
	string position;
	string responsible;
};
