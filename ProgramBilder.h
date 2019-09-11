#pragma once

#include "Bilder.h"
#include "Program.h"

class ProgramBilder:public Bilder
{
public:
	ProgramBilder(void);
	ProgramBilder(string&);
	ProgramBilder(const ProgramBilder&);
	~ProgramBilder(void);
	void ReadInFile(ostream&)override;
	ProgramBilder &SetName(string&);
	ProgramBilder &SetSurname(string&);
	ProgramBilder &SetOrganization(string&);
	ProgramBilder &SetLecture(string&);
	ProgramBilder &SetAnnotation(string&);
private:
	time_t dateSt;
	string name;
	List<Presetion*> presentations;
};

