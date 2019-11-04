#pragma once

#include "Builder.h"
#include "Program.h"
#include "Presentation.h"

typedef enum{PDATE, PNAME, PADDPRESENT, PFIN, PENDBILD} PBILD;

class Program;

class ProgramBuilder:public Builder
{
public:
	ProgramBuilder(void);
	ProgramBuilder(string&,time_t&);
	ProgramBuilder(const ProgramBuilder&);
	~ProgramBuilder(void);
	void ReadInFile(ifstream&)override;
	ProgramBuilder &SetDate(time_t&);
	ProgramBuilder &SetName(string&);
	ProgramBuilder &AddPresent(Presentation&);
	friend ifstream &operator >> (ifstream&, ProgramBuilder&);
	friend istream &operator >> (istream&, ProgramBuilder&);
private:
	friend Program;
	time_t dateSt;
	string name;
	List<Presentation*> *presentations;
};

