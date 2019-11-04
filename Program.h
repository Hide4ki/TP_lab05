#pragma once

#include <ctime>
#include "List.h"
#include "Conference.h"
#include "ProgramBuilder.h"
#include "Presentation.h"

using namespace std;
class ProgramBuilder;

class Program:public Conference
{
public:
	Program(ProgramBuilder&);
	Program(const Program&);
	~Program(void);
	void WriteInFile(ofstream&)const override;
	bool operator == (const Program&)const;
private:
	time_t dateSt;
	string name;
	List<Presentation*> *presentations;
	Program(void);
};