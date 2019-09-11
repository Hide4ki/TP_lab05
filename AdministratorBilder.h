#pragma once 

#include <string>
#include "Administrator.h"
#include "Bilder.h"

class AdministratorBilder:public Bilder
{
public:
	AdministratorBilder(void);
	AdministratorBilder(string name);
	AdministratorBilder(const AdministratorBilder&);
	~AdministratorBilder(void);
	void ReadInFile(ostream&)override;
	AdministratorBilder &SetName(string&);
	AdministratorBilder &SetSurname(string&);
	AdministratorBilder &SetFatherName(string&);
	AdministratorBilder &SetPosition(string&);
	AdministratorBilder &SetResponsible(string&);
private:
	friend Administrator;
	string name;
	string surname;
	string fathername;
	string position;
	string responsible;
};
