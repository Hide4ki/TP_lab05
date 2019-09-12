#pragma once

#include "Bilder.h"
#include "Program.h"
#include "Presetion.h"

class Program;

class ProgramBilder:public Bilder
{
public:
	ProgramBilder(void);
	ProgramBilder(string&,time_t&);
	ProgramBilder(const ProgramBilder&);
	~ProgramBilder(void);
	void ReadInFile(ifstream&)override;
	ProgramBilder &SetDate(time_t&);
	ProgramBilder &SetName(string&);
	ProgramBilder &AddPresent(Presetion&);
	friend istream &operator >> (istream&, ProgramBilder&);
private:
	friend Program;
	time_t dateSt;
	string name;
	List<Presetion*> *presentations;
};

