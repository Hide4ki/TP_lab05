#pragma once

#include <ctime>
#include "List.h"
#include "Conference.h"
#include "ProgramBilder.h"
#include "Presetion.h"

using namespace std;
class ProgramBilder;

class Program:public Conference
{
public:
	Program(ProgramBilder&);
	Program(const Program&);
	~Program(void);
	void WriteInFile(ofstream&)const override;
	bool operator == (const Program&)const;
private:
	time_t dateSt;
	string name;
	List<Presetion*> *presentations;
	Program(void);
};