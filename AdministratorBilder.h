#pragma once 

#include <string>
#include "Administrator.h"
#include "Bilder.h"

class Administrator;

class AdministratorBilder:public Bilder
{
public:
	AdministratorBilder(void);
	AdministratorBilder(string&);
	AdministratorBilder(const AdministratorBilder&);
	~AdministratorBilder(void);
	void ReadInFile(ifstream&)override;
	AdministratorBilder &SetName(string&);
	AdministratorBilder &SetSurname(string&);
	AdministratorBilder &SetFatherName(string&);
	AdministratorBilder &SetPosition(string&);
	AdministratorBilder &SetResponsible(string&);
	friend ostream &operator >> (istream&, AdministratorBilder&);
private:
	friend Administrator;
	string name;
	string surname;
	string father_name;
	string position;
	string responsible;
};
